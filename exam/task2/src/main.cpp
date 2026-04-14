/*
 * Задание 2 — аналоговые часы (OpenGL + GLFW)
 */

#ifdef _WIN32
  #define WIN32_LEAN_AND_MEAN
  #include <windows.h>
  #include <GL/gl.h>
#else
  #include <GL/gl.h>
#endif

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <string>

#include "RasterFont3x5.hpp"

#ifndef M_PI
  #define M_PI 3.14159265358979323846
#endif

#ifndef GL_MULTISAMPLE
  #define GL_MULTISAMPLE 0x809D
#endif

using Color = rasterfont3x5::Color;
static const Color BG        = {0.10f, 0.10f, 0.14f, 1.0f};
static const Color CLOCK_BG  = {0.13f, 0.13f, 0.18f, 1.0f};
static const Color CLOCK_RIM = {0.50f, 0.50f, 0.60f, 1.0f};
static const Color HOUR_C    = {0.95f, 0.90f, 0.70f, 1.0f};
static const Color MIN_C     = {0.95f, 0.95f, 0.95f, 1.0f};
static const Color SEC_C     = {0.95f, 0.35f, 0.35f, 1.0f};
static const Color TICK_C    = {0.65f, 0.65f, 0.65f, 1.0f};
static const Color NUM_C     = {0.70f, 0.70f, 0.80f, 1.0f};
static const Color LABEL_C   = {0.95f, 0.95f, 0.95f, 1.0f};

static void drawLine(float x0, float y0, float x1, float y1)
{
    glBegin(GL_LINES);
    glVertex2f(x0, y0);
    glVertex2f(x1, y1);
    glEnd();
}

static void fillCircle(float cx, float cy, float r, int seg = 72)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= seg; i++) {
        float a = 2.0f * (float)M_PI * i / seg;
        glVertex2f(cx + r * std::cos(a), cy + r * std::sin(a));
    }
    glEnd();
}

static void outlineCircle(float cx, float cy, float r, int seg = 72)
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < seg; i++) {
        float a = 2.0f * (float)M_PI * i / seg;
        glVertex2f(cx + r * std::cos(a), cy + r * std::sin(a));
    }
    glEnd();
}

static void drawCenteredText(const std::string& s, float cx, float cy, float sz, const Color& col)
{
    float w = s.empty() ? 0.0f : rasterfont3x5::strW(s, sz) - sz;
    float topY = cy + 2.0f * sz;
    rasterfont3x5::drawStr(s, cx - w * 0.5f, topY, sz, col);
}

static void drawClock(float cx, float cy, float r)
{
    auto tp = std::chrono::system_clock::now();
    std::time_t tt = std::chrono::system_clock::to_time_t(tp);
    std::tm* tm = std::localtime(&tt);
    int h = tm->tm_hour % 12;
    int m = tm->tm_min;
    int s = tm->tm_sec;
    float ms = (float)(std::chrono::duration_cast<std::chrono::milliseconds>(
        tp.time_since_epoch()).count() % 1000) / 1000.0f;

    rasterfont3x5::setColor(CLOCK_BG);
    fillCircle(cx, cy, r);
    rasterfont3x5::setColor(CLOCK_RIM);
    glLineWidth(2.5f);
    outlineCircle(cx, cy, r);
    glLineWidth(1.0f);

    for (int i = 0; i < 12; i++) {
        float ang = (float)M_PI / 2.0f - i * (float)M_PI / 6.0f;
        float ca = std::cos(ang), sa = std::sin(ang);
        float r1 = (i % 3 == 0) ? r * 0.82f : r * 0.88f;
        float lw = (i % 3 == 0) ? 2.5f : 1.2f;
        rasterfont3x5::setColor(i % 3 == 0 ? LABEL_C : TICK_C);
        glLineWidth(lw);
        drawLine(cx + r1 * ca, cy + r1 * sa, cx + r * 0.96f * ca, cy + r * 0.96f * sa);
        glLineWidth(1.0f);

        int num = (i == 0) ? 12 : i;
        std::string lbl = std::to_string(num);
        float sz = std::clamp(r * 0.040f, 3.0f, 8.0f);
        float nr = r * 0.70f;
        drawCenteredText(lbl, cx + nr * ca, cy + nr * sa, sz, NUM_C);
    }

    glLineWidth(0.8f);
    rasterfont3x5::setColor({TICK_C.r, TICK_C.g, TICK_C.b, 0.4f});
    for (int i = 0; i < 60; i++) {
        if (i % 5 == 0) continue;
        float ang = (float)M_PI / 2.0f - i * (float)M_PI / 30.0f;
        drawLine(cx + r * 0.92f * std::cos(ang), cy + r * 0.92f * std::sin(ang),
                 cx + r * 0.96f * std::cos(ang), cy + r * 0.96f * std::sin(ang));
    }
    glLineWidth(1.0f);

    float ha = (float)M_PI / 2.0f - (h + m / 60.0f) * (float)M_PI / 6.0f;
    rasterfont3x5::setColor(HOUR_C);
    glLineWidth(4.5f);
    drawLine(cx, cy, cx + r * 0.55f * std::cos(ha), cy + r * 0.55f * std::sin(ha));

    float ma = (float)M_PI / 2.0f - (m + (s + ms) / 60.0f) * (float)M_PI / 30.0f;
    rasterfont3x5::setColor(MIN_C);
    glLineWidth(3.0f);
    drawLine(cx, cy, cx + r * 0.80f * std::cos(ma), cy + r * 0.80f * std::sin(ma));

    float sa = (float)M_PI / 2.0f - (s + ms) * (float)M_PI / 30.0f;
    rasterfont3x5::setColor(SEC_C);
    glLineWidth(1.5f);
    drawLine(cx - r * 0.15f * std::cos(sa), cy - r * 0.15f * std::sin(sa),
             cx + r * 0.88f * std::cos(sa), cy + r * 0.88f * std::sin(sa));
    glLineWidth(1.0f);

    rasterfont3x5::setColor(SEC_C);
    fillCircle(cx, cy, r * 0.035f);
}

int main()
{
    if (!glfwInit()) return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    GLFWwindow* win = glfwCreateWindow(700, 700, "Task 2 | Analog Clock", nullptr, nullptr);
    if (!win) { glfwTerminate(); return -1; }

    glfwMakeContextCurrent(win);
    glfwSwapInterval(1);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_MULTISAMPLE);

    while (!glfwWindowShouldClose(win)) {
        int w, h;
        glfwGetFramebufferSize(win, &w, &h);

        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, w, 0, h, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glClearColor(BG.r, BG.g, BG.b, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        float r = std::min((float)w, (float)h) * 0.44f;
        drawClock(w * 0.5f, h * 0.5f, r);

        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    glfwDestroyWindow(win);
    glfwTerminate();
    return 0;
}
