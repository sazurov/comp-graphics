#pragma once

#ifdef _WIN32
  #define WIN32_LEAN_AND_MEAN
  #include <windows.h>
  #include <GL/gl.h>
#else
  #include <GL/gl.h>
#endif

#include <algorithm>
#include <string>

namespace rasterfont3x5 {

struct Color { float r, g, b, a; };

inline void setColor(const Color& c) { glColor4f(c.r, c.g, c.b, c.a); }

inline constexpr const char* FONT[13][5] = {
    {"###","# #","# #","# #","###"}, /* 0 */
    {" # "," # "," # "," # "," # "}, /* 1 */
    {"###","  #","###","#  ","###"}, /* 2 */
    {"###","  #","###","  #","###"}, /* 3 */
    {"# #","# #","###","  #","  #"}, /* 4 */
    {"###","#  ","###","  #","###"}, /* 5 */
    {"###","#  ","###","# #","###"}, /* 6 */
    {"###","  #","  #","  #","  #"}, /* 7 */
    {"###","# #","###","# #","###"}, /* 8 */
    {"###","# #","###","  #","###"}, /* 9 */
    {"   ","   ","###","   ","   "}, /* 10 = '-' */
    {"   ","   ","   ","   ","   "}, /* 11 = ' ' */
    {"   ","   ","   ","   ","  #"}, /* 12 = '.' */
};

inline int fontIdx(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    if (c == '-') return 10;
    if (c == ' ') return 11;
    if (c == '.') return 12;
    return 11;
}

inline void drawChar(char c, float ox, float oy, float sz, const Color& col)
{
    int idx = fontIdx(c);
    setColor(col);
    glPointSize(std::max(1.0f, sz - 1.0f));
    glBegin(GL_POINTS);
    for (int row = 0; row < 5; row++) {
        for (int col2 = 0; col2 < 3; col2++) {
            if (FONT[idx][row][col2] == '#') {
                glVertex2f(ox + col2 * sz, oy - row * sz);
            }
        }
    }
    glEnd();
    glPointSize(1.0f);
}

inline float charW(float sz) { return 4.0f * sz; }
inline float strW(const std::string& s, float sz) { return (float)s.size() * charW(sz); }

inline void drawStr(const std::string& s, float ox, float oy, float sz, const Color& col)
{
    float x = ox;
    for (char c : s) {
        drawChar(c, x, oy, sz, col);
        x += charW(sz);
    }
}

} // namespace rasterfont3x5

