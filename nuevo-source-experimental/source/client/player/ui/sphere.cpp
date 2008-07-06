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
        sphereState.incrementAlphaInTime(deltaTime);
        std::cout << "ALPHA: " << sphereState.getAlpha() << std::endl;
    }
    if ( uiState.getKeyPressed(SDLK_RIGHT) ) {
        sphereState.decrementAlphaInTime(deltaTime);
        std::cout << "ALPHA: " << sphereState.getAlpha() << std::endl;
    }
    if ( uiState.getKeyPressed(SDLK_UP) ) {
        sphereState.incrementBetaInTime(deltaTime);
        std::cout << "BETA: " << sphereState.getBeta() << std::endl;
    }
    if ( uiState.getKeyPressed(SDLK_DOWN) ) {
        sphereState.decrementBetaInTime(deltaTime);
        std::cout << "BETA: " << sphereState.getBeta() << std::endl;
    }
    if ( uiState.getKeyPressed(SDLK_PAGEUP) ) {
        sphereState.incrementDistanceInTime(deltaTime);
        std::cout << "DISTANCE: " << sphereState.getDistance() << std::endl;
    }
    if ( uiState.getKeyPressed(SDLK_PAGEDOWN) ) {
        sphereState.decrementDistanceInTime(deltaTime);
        std::cout << "DISTANCE: " << sphereState.getDistance() << std::endl;
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        sphereState.getDistance() * cos(sphereState.getAlpha()) * cos(sphereState.getBeta()),
        sphereState.getDistance() * sin(sphereState.getAlpha()) * cos(sphereState.getBeta()),
        sphereState.getDistance() * sin(sphereState.getBeta()),
        0.0, 0.0, 0.0,
        0.0, 0.0, -1.0);
    glRotatef(0.5, 1.0,0.0,0.0);
    glRotatef(0.5, 0.0, 1.0, 0.0);
}

void Sphere::draw() {
    // Habilito textura
    enableTexture();
    // Rotate in te  axis
    // Dibujo la esfera
    gluSphere(sphereQuad, 0.5, 50, 50);
    // Deshabilito textura
    disableTexture();
}

