#include "glspherewidget.h"

void GLSphereWidget::drawWidget(){
    // Cargo la matriz model view
	glMatrixMode(GL_MODELVIEW);
	// Cargo la identidad
	glLoadIdentity();
	// Translado coordenadas del origen
	glTranslatef(0.0f, 0.0f, 0.0f);
    gluSphere(sphere, radius, 20, 20);
}

GLSphereWidget::GLSphereWidget(const float& radius): GL3DWidget(), sphere(NULL), radius(radius) {
    sphere = gluNewQuadric();
    gluQuadricDrawStyle (sphere, GLU_FILL);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    gluQuadricTexture(sphere, GL_TRUE);
}

GLSphereWidget::~GLSphereWidget() {
	gluDeleteQuadric(sphere);
}

