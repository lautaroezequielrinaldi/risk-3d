#include "glspherewidget.h"
#include<iostream>
void GLSphereWidget::loadTexture(const std::string& imageFileName) {
    glEnable(GL_TEXTURE_2D);
    SDL_Surface * mapaSurface = IMG_Load(imageFileName.c_str());
    if (mapaSurface) {
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);

        SDL_LockSurface(mapaSurface);

        gluBuild2DMipmaps(GL_TEXTURE_2D,3,mapaSurface->w,
           mapaSurface->h,GL_BGR_EXT, GL_UNSIGNED_BYTE, mapaSurface->pixels);

        SDL_UnlockSurface(mapaSurface);
        SDL_FreeSurface(mapaSurface);

        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR_MIPMAP_LINEAR);
    }
}

void GLSphereWidget::drawWidget() {
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
	// Habilito la textura
    glBindTexture( GL_TEXTURE_2D, texture );
    glEnable(GL_TEXTURE_2D);

    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
	// Dibujo esfera
    gluSphere(sphere, radius, 20, 20);
	// Deshabilito la textura
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D);

	// Cargo matriz.
	glPopMatrix();
	// Cargo matriz.
	glPopMatrix();
}

GLSphereWidget::GLSphereWidget(const std::string& imageFileName, const float& radius): GL3DWidget(), texture(0), sphere(NULL), radius(radius) {
    sphere = gluNewQuadric();
    gluQuadricDrawStyle (sphere, GLU_FILL);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    gluQuadricTexture(sphere, GL_TRUE);
	this->setTexture(imageFileName);
	this->setBackgroundColor(GLWIDGET_ACTIVE, Color::RED);
	this->setBackgroundColor(GLWIDGET_INACTIVE, Color::BLUE);
}

void GLSphereWidget::setTexture(const std::string& imageFileName) {
	this->loadTexture(imageFileName);
}

GLSphereWidget::~GLSphereWidget() {
	gluDeleteQuadric(sphere);
}

