#include "gamewindow.h"
#include "glhelper.h"
#include<iostream>

GameWindow::GameWindow(): running(true) {
    // No realiza ninguna accion.
}

bool GameWindow::initializeSDL() {
    // Intento inicializar SDL
    if ( SDL_Init(SDL_INIT_EVERYTHING) < 0 ) {
        std::cerr << "Problemas iniciando SDL, error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Intengo inicializar una ventana SDL
    SDL_Surface* screen = SDL_SetVideoMode(SDL_GetVideoInfo()->current_w, SDL_GetVideoInfo()->current_h,
        SDL_GetVideoInfo()->vfmt->BitsPerPixel, SDL_OPENGL);

    if (! screen ) {
        std::cerr << "Problemas creando display SDL, error: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

void GameWindow::initializeOpenGL() {
    // Inicializo el viewport de OpenGL
    glViewport(0, 0, SDL_GetVideoInfo()->current_w, SDL_GetVideoInfo()->current_h);
}

void GameWindow::terminateSDL() {
    SDL_FreeSurface( SDL_GetVideoSurface() );
    SDL_Quit();
}

void GameWindow::terminateOpenGL() {

}

void GameWindow::enable2D() {
    // Pone la matriz actual en el stack
    glPushMatrix();
    // Guarda los atributos en el stack
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    // Carga la matriz de proyeccion
    glMatrixMode (GL_PROJECTION);
    // Pone la matriz actual en el stack
    // carga la identidad
    glLoadIdentity ();
    // Visualiza 2d
    glOrtho (0, SDL_GetVideoInfo()->current_w, SDL_GetVideoInfo()->current_h, 0, 0, 1);
    // Carga la matriz model view
    glMatrixMode (GL_MODELVIEW);
}

void GameWindow::disable2D() {
    // Carga del stack los atributos.
    glPopAttrib();
    // Carga del stack la matriz actual.
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    // Carga del stack la matriz actual.
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void GameWindow::updateScene() {

}

void GameWindow::drawScene() {
    this->enable2D();
    ColorRGBA color;
    color.red = 1.0;
    color.green = 1.0,
    color.blue = 0.0;
    color.alpha = 0.5;

    drawFilledRectangle(0.0f, 0.0f, 200.0f, 200.0f, color);
    this->disable2D();
    SDL_GL_SwapBuffers();
}

bool GameWindow::isRunning() {
    return this->running;
}

void GameWindow::stopRunning() {
    this->running = false;
}

void GameWindow::processEvents() {
    SDL_Event event;
    if ( SDL_PollEvent(&event) ) {
        switch (event.type) {
            case SDL_MOUSEBUTTONDOWN:
                processMouseDownEvent(event.button);
                break;
            case SDL_MOUSEBUTTONUP:
                processMouseUpEvent(event.button);
                break;
            case SDL_MOUSEMOTION:
                processMouseMotionEvent(event.motion);
                break;
            case SDL_KEYDOWN:
                processKeyDownEvent(event.key);
                break;
            case SDL_KEYUP:
                processKeyUpEvent(event.key);
                break;
            case SDL_QUIT:
                processQuitEvent(event.quit);
            default:
                break;
        }
    }
}

void GameWindow::processMouseDownEvent(const SDL_MouseButtonEvent& event) {

}

void GameWindow::processMouseUpEvent(const SDL_MouseButtonEvent& event) {

}

void GameWindow::processMouseMotionEvent(const SDL_MouseMotionEvent& event) {

}

void GameWindow::processKeyDownEvent(const SDL_KeyboardEvent& event) {

}

void GameWindow::processKeyUpEvent(const SDL_KeyboardEvent& event) {

}

void GameWindow::processQuitEvent(const SDL_QuitEvent& event) {
    this->stopRunning();
}

int GameWindow::run() {
    // Verifica si puede iniciar SDL
    if (! this->initializeSDL() ) {
        return 1;
    } 
    // Inicializa OpenGL
    this->initializeOpenGL();

    // Corre el main loop
    while ( this->isRunning() ) {
        // Proceso eventos
        this->processEvents();
        // Actualizo la escena
        this->updateScene();
        // Dibujo la escena
        this->drawScene();
    }

    // Termina OpenGL
    this->terminateOpenGL();

    // Termina SDL
    this->terminateSDL();

    return 0;
}

GameWindow::~GameWindow() {
    // No realiza ninguna accion.
}

