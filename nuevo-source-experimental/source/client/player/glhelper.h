#ifndef __GLHELPER_H__
#define __GLHELPER_H__

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

#endif /** __GLHELPER_H__ */

