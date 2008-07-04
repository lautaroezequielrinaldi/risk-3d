#ifndef __GLHELPER_H__
#define __GLHELPER_H__

#include<string>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>

typedef struct ColorRGB {
    GLfloat red;
    GLfloat green;
    GLfloat blue;
} ColorRGB;

typedef struct ColorRGBA {
    GLfloat red;
    GLfloat green;
    GLfloat blue;
    GLfloat alpha;
} ColorRGBA;


void drawFilledRectangle(const GLfloat& x, const GLfloat& y, const GLfloat& width, const GLfloat& height, const ColorRGB& color);

void drawFilledRectangle(const GLfloat& x, const GLfloat& y, const GLfloat& width, const GLfloat& height, const ColorRGBA& color); 

int calculateTextWidth(const std::string& text, const int& padding = 0); 

int calculateTextHeight(const std::string& text, const int& padding = 0); 

void drawCenteredText(const std::string& text, const GLfloat& x, const GLfloat& y, const GLfloat& width, const GLfloat& height, const ColorRGB& color);

void drawText(const std::string& text, const GLfloat& x, const GLfloat& y, const ColorRGB& color);
#endif /** __GLHELPER_H__ */

