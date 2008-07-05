#include "sphere.h"

Sphere::Sphere(UIState& uiState):
    Textured(),
    uiState(uiState) {
    initializeQuad();
}

Sphere::Sphere(UIState& uiState, const Texture& theTexture):
    Textured(theTexture),
    uiState(uiState) {
    initializeQuad();
}

Sphere::~Sphere() {
    terminateQuad();
}

void Sphere::initializeQuad() {
    sphereQuad = gluNewQuadric();
    gluQuadricDrawStyle (sphereQuad, GLU_FILL);
    gluQuadricNormals(sphereQuad, GLU_SMOOTH);
    gluQuadricTexture(sphereQuad, GL_TRUE);
}

void Sphere::terminateQuad() {
    gluDeleteQuadric(sphereQuad);
}

void Sphere::update() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, 0.0f);
}

void Sphere::draw() {
    // Habilito textura
    enableTexture();
    // Dibujo la esfera
    gluSphere(sphereQuad, 0.5, 50, 50);
    // Deshabilito textura
    disableTexture();
}

