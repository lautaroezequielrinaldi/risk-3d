#include "glspherewidget.h"

void GLSphereWidget::drawWidget(){
    // Cargo la matriz de proyeccion.
	glMatrixMode(GL_PROJECTION);
	// Cargo la identidad
	glLoadIdentity();
	// Guardo la matriz en el stack.
	glPushMatrix();
	// Translado coordenadas del origen
	glTranslatef(-0.0f, 0.0f, 0.0f);
	glRotatef(0.5f, 0.5f, 0.5f, 0.5f);
	// Cargo la matriz model view.
	glMatrixMode(GL_MODELVIEW);
	// Cargo la identidad.
	glLoadIdentity();
	// Guardo en el stack la matriz.
	glPushMatrix();
	// Establece el color de dibujado.
	switch (this->getState()) {
		case GLWIDGET_DISABLED: {
			Color backgroundColor = this->getBackgroundColor(GLWIDGET_DISABLED);
			glColor3f(backgroundColor.getRed(), backgroundColor.getGreen(), backgroundColor.getBlue());
			break;
		}
		case GLWIDGET_ACTIVE: {
            Color backgroundColor = this->getBackgroundColor(GLWIDGET_ACTIVE);
            glColor3f(backgroundColor.getRed(), backgroundColor.getGreen(), backgroundColor.getBlue());
            break;
		}
		case GLWIDGET_INACTIVE: {
            Color backgroundColor = this->getBackgroundColor(GLWIDGET_INACTIVE);
            glColor3f(backgroundColor.getRed(), backgroundColor.getGreen(), backgroundColor.getBlue());
            break;
        }
	}
	// Dibujo esfera
    gluSphere(sphere, radius, 20, 20);
	// Cargo matriz.
	glPopMatrix();
	// Cargo matriz.
	glPopMatrix();
}

GLSphereWidget::GLSphereWidget(const float& radius): GL3DWidget(), sphere(NULL), radius(radius) {
    sphere = gluNewQuadric();
    gluQuadricDrawStyle (sphere, GLU_FILL);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    gluQuadricTexture(sphere, GL_TRUE);
	this->setBackgroundColor(GLWIDGET_ACTIVE, Color::RED);
	this->setBackgroundColor(GLWIDGET_INACTIVE, Color::BLUE);
}

GLSphereWidget::~GLSphereWidget() {
	gluDeleteQuadric(sphere);
}

