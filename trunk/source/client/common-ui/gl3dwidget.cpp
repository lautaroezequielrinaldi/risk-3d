#include "gl3dwidget.h"

void GL3DWidget::preDrawWidget() {
    // Obtengo la dimension del viewport.
	GLfloat viewportDimension[4];
    glGetFloatv(GL_VIEWPORT, viewportDimension);

	// Guarda en el stack la matriz actual.
    glPushMatrix();
    // Guarda en el stack los atributos actuales.
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    // Habilita DEPTH BUFFER.
    glEnable(GL_DEPTH_TEST);
    // Carga la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
    // Carga la identidad.
    glLoadIdentity();
    // Carga la matriz model view.
    glMatrixMode(GL_MODELVIEW);
}

void GL3DWidget::postDrawWidget() {
    // Carga del stack los atributos.
    glPopAttrib();
    // Carga del stack la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
	// Carga del stack la matriz de model view.
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

GL3DWidget::GL3DWidget(): GLWidget() {
    // No realiza ninguna accion.
}

GL3DWidget::~GL3DWidget() {
     // No realiza ninguna accion.
}

