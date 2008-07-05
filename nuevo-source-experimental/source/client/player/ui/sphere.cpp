#include "sphere.h"
#include<iostream>
Sphere::Sphere(UIState& uiState):
    Textured(),
    uiState(uiState),
    sphereState() {
    initializeQuad();
}

Sphere::Sphere(UIState& uiState, const Texture& theTexture):
    Textured(theTexture),
    uiState(uiState),
    sphereState() {
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
    gluQuadricOrientation(sphereQuad, GLU_OUTSIDE);
}

void Sphere::terminateQuad() {
    gluDeleteQuadric(sphereQuad);
}

void Sphere::update() {
    double newTime = SDL_GetTicks();
    double deltaTime = (newTime - sphereState.getLastTime()) / 1000.0;
    sphereState.setLastTime(newTime);

    if ( uiState.getKeyPressed(SDLK_LEFT) ) {
        std::cerr << "Left presionada" << std::endl;
        sphereState.incrementAlphaInTime(deltaTime);
    }
    if ( uiState.getKeyPressed(SDLK_RIGHT) ) {
        sphereState.decrementAlphaInTime(deltaTime);
    }
    if ( uiState.getKeyPressed(SDLK_UP) ) {
        sphereState.incrementBetaInTime(deltaTime);
    }
    if ( uiState.getKeyPressed(SDLK_DOWN) ) {
        sphereState.decrementBetaInTime(deltaTime);
    }
    if ( uiState.getKeyPressed(SDLK_PAGEUP) ) {
        sphereState.incrementDistanceInTime(deltaTime);
    }
    if ( uiState.getKeyPressed(SDLK_PAGEDOWN) ) {
        sphereState.decrementDistanceInTime(deltaTime);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        sphereState.getDistance() * cos(sphereState.getAlpha()) * cos(sphereState.getBeta()),
        sphereState.getDistance() * sin(sphereState.getAlpha()) * cos(sphereState.getBeta()),
        sphereState.getDistance() * sin(sphereState.getBeta()),
        0.0, 0.0, 0.0,
        0.0, 0.0, -1.0);
}

void Sphere::draw() {
    // Habilito textura
    enableTexture();
    // Dibujo la esfera
    gluSphere(sphereQuad, 0.5, 50, 50);
    // Deshabilito textura
    disableTexture();
}

