#include "gl2dwidget.h"
void GL2DWidget::preDrawWidget() {
	// Obtengo la dimension del viewport.
	GLfloat viewportDimension[4];
	glGetFloatv(GL_VIEWPORT, viewportDimension);

    // Guarda en el stack la matriz actual.
    glPushMatrix();
    // Guarda en el stack los atributos actuales.
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    // Deshabilita DEPTH BUFFER.
    glDisable(GL_DEPTH_TEST);
    // Carga la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
    // Carga la identidad.
    glLoadIdentity();
    // Establece coordenadas 2D.
    //glOrtho(0, viewportDimension[2], viewportDimension[3], 0, 0, 1);
    glOrtho(0, 1024, 768, 0, 0, 1);
    // Carga la matriz model view.
    glMatrixMode(GL_MODELVIEW);
}

void GL2DWidget::postDrawWidget() {
    // Carga del stack los atributos.
    glPopAttrib();
    // Carga del sack la matriz actual.
	glMatrixMode(GL_PROJECTION);
    glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

GL2DWidget::GL2DWidget(): GLWidget() {
	// No realiza ninguna accion.
}

GL2DWidget::~GL2DWidget() {
	// No realiza ninguna accion.
}

