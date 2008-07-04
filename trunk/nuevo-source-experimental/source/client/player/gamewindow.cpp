#include "gamewindow.h"
#include "glhelper.h"
#include<iostream>

GameWindow::GameWindow(): running(true) {
    // No realiza ninguna accion.
}

bool GameWindow::initializeSDL() {
    if ( SDL_Init(SDL_INIT_EVERYTHING) < 0 ) {
        std::cerr << "Problemas iniciando SDL, error: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_Surface* screen = SDL_SetVideoMode(SDL_GetVideoInfo()->current_w, SDL_GetVideoInfo()->current_h,
        SDL_GetVideoInfo()->vfmt->BitsPerPixel, SDL_OPENGL);

    if (! screen ) {
        std::cerr << "Problemas creando display SDL, error: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

void GameWindow::terminateSDL() {
    SDL_FreeSurface( SDL_GetVideoSurface() );
    SDL_Quit();
}

void GameWindow::updateScene() {

}

void GameWindow::drawScene() {
    ColorRGBA color;
    color.red = 1.0;
    color.green = 1.0,
    color.blue = 0.0;
    color.alpha = 0.5;

    drawFilledRectangle(-0.75f,0.75f, 0.75f, -0.75f, color);

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
    if (! initializeSDL() ) {
        return 1;
    } 

    // Corre el main loop
    while ( this->isRunning() ) {
        // Proceso eventos
        processEvents();
        // Actualizo la escena
        updateScene();
        // Dibujo la escena
        drawScene();
    }

    // Termina SDL
    terminateSDL();

    return 0;
}

GameWindow::~GameWindow() {
    // No realiza ninguna accion.
}

