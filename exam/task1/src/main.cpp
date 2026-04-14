/*
 * Задание 1 — график функции (OpenGL + GLFW)
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
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

#include "RasterFont3x5.hpp"

#ifndef M_PI
  #define M_PI 3.14159265358979323846
#endif

#ifndef GL_MULTISAMPLE
  #define GL_MULTISAMPLE 0x809D
#endif

static const int VARIANT = 1;
static const int STEPS = 3000;

using Color = rasterfont3x5::Color;
static const Color BG      = {0.10f, 0.10f, 0.14f, 1.0f};
static const Color AXIS_C  = {0.85f, 0.85f, 0.85f, 1.0f};
static const Color GRAPH_C = {0.20f, 0.80f, 0.55f, 1.0f};
static const Color TICK_C  = {0.65f, 0.65f, 0.65f, 1.0f};
static const Color GRID_C  = {0.65f, 0.65f, 0.65f, 0.15f};
static const Color TEXT_C  = {0.95f, 0.95f, 0.95f, 1.0f};

struct FuncInfo { const char* name; double xmin, xmax; };
static const FuncInfo FUNCS[4] = {
    {},
    {"sin(3x) + cos(2x + PI*12)", -6.0*M_PI, 6.0*M_PI},
    {"2x^2 - 3x - 8",             -2.0,       3.0     },
    {"1/x",                        -4.0,       4.0     },
};

static bool evalY(double x, double& out)
{
    switch (VARIANT) {
    case 1: out = std::sin(3.0*x) + std::cos(2.0*x + M_PI*12.0); return true;
    case 2: out = 2.0*x*x - 3.0*x - 8.0; return true;
    case 3:
        if (std::fabs(x) < 1e-9) return false;
        out = 1.0 / x;
        return true;
    default:
        return false;
    }
}

static void drawLine(float x0, float y0, float x1, float y1)
{
    glBegin(GL_LINES);
    glVertex2f(x0, y0);
    glVertex2f(x1, y1);
    glEnd();
}

static void fillTri(float x0,float y0,float x1,float y1,float x2,float y2)
{
    glBegin(GL_TRIANGLES);
    glVertex2f(x0, y0);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

static void measureTextBounds(const std::string& s, float sz, float& outMinX, float& outMaxX)
{
    bool any = false;
    float pen = 0.0f;
    outMinX = 0.0f;
    outMaxX = 0.0f;

    for (char c : s) {
        int idx = rasterfont3x5::fontIdx(c);
        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 3; col++) {
                if (rasterfont3x5::FONT[idx][row][col] != '#') continue;
                float x = pen + col * sz;
                if (!any) { outMinX = outMaxX = x; any = true; }
                else { outMinX = std::min(outMinX, x); outMaxX = std::max(outMaxX, x); }
            }
        }
        pen += 4.0f * sz;
    }
    if (!any) { outMinX = 0.0f; outMaxX = 0.0f; }
}

static void drawTextCentered(const std::string& s, float cx, float cy, float sz, const Color& col)
{
    float minX = 0.0f, maxX = 0.0f;
    measureTextBounds(s, sz, minX, maxX);
    float midX = 0.5f * (minX + maxX);
    float topY = cy + 2.0f * sz;
    rasterfont3x5::drawStr(s, cx - midX, topY, sz, col);
}

static void drawTextRightCentered(const std::string& s, float rightX, float cy, float sz, const Color& col)
{
    float minX = 0.0f, maxX = 0.0f;
    measureTextBounds(s, sz, minX, maxX);
    float topY = cy + 2.0f * sz;
    rasterfont3x5::drawStr(s, rightX - maxX, topY, sz, col);
}

static std::string fmt(double v, int dec = 1)
{
    char buf[64];
    std::snprintf(buf, sizeof(buf), "%.*f", dec, v);
    std::string s = buf;
    if (s.find('.') != std::string::npos) {
        while (!s.empty() && s.back() == '0') s.pop_back();
        if (!s.empty() && s.back() == '.') s.pop_back();
    }
    if (s == "-0") s = "0";
    return s;
}

static double niceStep(double range, int lo = 10, int hi = 20)
{
    double raw = range / hi;
    double e = std::floor(std::log10(std::max(raw, 1e-12)));
    double base = std::pow(10.0, e);
    double ms[] = {1, 2, 2.5, 5, 10};
    for (double m : ms) {
        double step = base * m;
        double n = range / step;
        if (n >= lo && n <= hi) return step;
    }
    return base;
}

static void drawGraph(float px, float py, float pw, float ph)
{
    const FuncInfo& info = FUNCS[VARIANT];
    double xmin = info.xmin, xmax = info.xmax;
    double xr = xmax - xmin;

    struct Pt { double x, y; };
    std::vector<Pt> pts;
    pts.reserve(STEPS + 1);
    for (int i = 0; i <= STEPS; i++) {
        double x = xmin + xr * i / STEPS;
        double y;
        if (evalY(x, y)) pts.push_back({x, y});
    }
    if (pts.size() < 2) return;

    double ymin = pts[0].y, ymax = pts[0].y;
    for (const auto& p : pts) { ymin = std::min(ymin, p.y); ymax = std::max(ymax, p.y); }
    double yr = (ymax > ymin) ? (ymax - ymin) : 1.0;

    const float marginL = 62.0f, marginR = 18.0f, marginB = 46.0f, marginT = 26.0f;
    float iw = std::max(1.0f, pw - marginL - marginR);
    float ih = std::max(1.0f, ph - marginB - marginT);

    auto sx = [&](double x) { return px + marginL + (float)((x - xmin) / xr) * iw; };
    auto sy = [&](double y) { return py + marginB + (float)((y - ymin) / yr) * ih; };

    float y0 = std::clamp((float)sy(0.0), py + marginB, py + ph - marginT);
    float x0 = std::clamp((float)sx(0.0), px + marginL, px + pw - marginR);

    // Размер подписей осей (можешь менять)
    const float SZ = 3.0f;

    /* Оси */
    rasterfont3x5::setColor(AXIS_C);
    glLineWidth(1.6f);
    drawLine(px + marginL, y0, px + pw - marginR, y0);
    { float ax = px + pw - marginR; fillTri(ax + 10, y0, ax, y0 - 4, ax, y0 + 4); }
    drawLine(x0, py + marginB, x0, py + ph - marginT);
    { float ay = py + ph - marginT; fillTri(x0, ay + 10, x0 - 4, ay, x0 + 4, ay); }
    glLineWidth(1.0f);

    /* Деления X */
    double stepX = niceStep(xr);
    double tx = std::ceil(xmin / stepX) * stepX;
    while (tx <= xmax + 1e-9) {
        float s = (float)sx(tx);
        glLineWidth(0.5f);
        rasterfont3x5::setColor(GRID_C);
        drawLine(s, py + marginB, s, py + ph - marginT);

        glLineWidth(1.2f);
        rasterfont3x5::setColor(TICK_C);
        drawLine(s, y0 - 5, s, y0 + 5);
        glLineWidth(1.0f);

        if (std::fabs(tx) > stepX * 0.01) {
            rasterfont3x5::setColor(TEXT_C);
            std::string lbl = fmt(tx);
            drawTextCentered(lbl, s, y0 - (SZ * 2.4f), SZ, TEXT_C);
        }
        tx = std::round((tx + stepX) / stepX) * stepX;
    }

    /* Деления Y */
    double stepY = niceStep(yr);
    double ty = std::ceil(ymin / stepY) * stepY;
    while (ty <= ymax + 1e-9) {
        float s = (float)sy(ty);
        glLineWidth(0.5f);
        rasterfont3x5::setColor(GRID_C);
        drawLine(px + marginL, s, px + pw - marginR, s);

        glLineWidth(1.2f);
        rasterfont3x5::setColor(TICK_C);
        drawLine(x0 - 5, s, x0 + 5, s);
        glLineWidth(1.0f);

        if (std::fabs(ty) > stepY * 0.01) {
            std::string lbl = fmt(ty);
            drawTextRightCentered(lbl, x0 - 10.0f, s, SZ, TEXT_C);
        }
        ty = std::round((ty + stepY) / stepY) * stepY;
    }

    /* График */
    rasterfont3x5::setColor(GRAPH_C);
    glLineWidth(2.0f);

    bool open = false;
    double prevY = pts[0].y;
    for (size_t i = 0; i < pts.size(); i++) {
        if (i > 0 && std::fabs(pts[i].y - prevY) > yr * 0.7) {
            if (open) { glEnd(); open = false; }
        }
        if (!open) { glBegin(GL_LINE_STRIP); open = true; }
        glVertex2f((float)sx(pts[i].x), (float)sy(pts[i].y));
        prevY = pts[i].y;
    }
    if (open) glEnd();
    glLineWidth(1.0f);
}

int main()
{
    if (!glfwInit()) return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    const char* titles[4] = {
        "",
        "Task 1 | Variant 1",
        "Task 1 | Variant 2",
        "Task 1 | Variant 3",
    };
    GLFWwindow* win = glfwCreateWindow(1000, 650, titles[VARIANT], nullptr, nullptr);
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

        float mg = 12.0f;
        drawGraph(mg, mg, (float)w - 2 * mg, (float)h - 2 * mg);

        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    glfwDestroyWindow(win);
    glfwTerminate();
    return 0;
}
