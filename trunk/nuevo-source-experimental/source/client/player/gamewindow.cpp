#include "gamewindow.h"
#include<GL/glut.h>

GameWindow::GameWindow():
    mainLoopRunning(true),
    uiState(),
    button(uiState),
    sphere() {
    // No realiza ninguna accion.
}

GameWindow::~GameWindow() {
    // No realiza ninguna accion.
}

bool GameWindow::initializeSDL(int argc, char** argv) {
    // Inicializo SDL
   if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0) {
        return false;
    }
    // Creo una ventana
    SDL_Surface* screen = SDL_SetVideoMode( SDL_GetVideoInfo()->current_w,
        SDL_GetVideoInfo()->current_h, SDL_GetVideoInfo()->vfmt->BitsPerPixel,
            SDL_OPENGL );
    if ( screen == NULL ) {
        return false;
    }
    glutInit(&argc, argv);
    return true;
}

void GameWindow::initializeOpenGL() {
    // Inicializo el Viewport OpenGL
    glViewport(0, 0, SDL_GetVideoInfo()->current_w,
        SDL_GetVideoInfo()->current_h);

    // Da perspectiva
    gluPerspective(60.0, 1.33, 0.1, 100.0);

    // Carga la matriz de proyeccion
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Establezco tamaño de boton y posicion.
    button.setX(300);
    button.setY(300);
    button.setWidth(500);
    button.setHeight(150);
    button.setVisible(true);
    button.setEnabled(true);

    // Cargo las texturas de la esfera.
    sphere.getTexture().load("mapa.jpg");
}

void GameWindow::terminateSDL() {
    SDL_FreeSurface( SDL_GetVideoSurface() );
    SDL_Quit();
}

void GameWindow::terminateOpenGL() {

}

void GameWindow::runMainLoop() {
    while ( mainLoopRunning ) {
        processEvents();
        updateScene();
        drawScene();
    }
}

void GameWindow::stopMainLoop() {
    mainLoopRunning = false;
}

void GameWindow::enable2D() {
    int vPort[4];

    glGetIntegerv(GL_VIEWPORT, vPort);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, vPort[2], 0, vPort[3], -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
}

void GameWindow::disable2D() {
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void GameWindow::updateScene() {
    sphere.update();
}

void GameWindow::drawScene() {
    // Limpia el fondo
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // Dibuja la esfera
    sphere.draw();

    // Habilita modo 2D
    enable2D();
    // Prepara IMGUI
    uiState.prepare();

    // Dibuja y procesa boton
    button.doProcess();

    // Termina IMGUI
    uiState.unprepare();

    // Deshabilita 2D
    disable2D();

    // Hace swap del buffer
    SDL_GL_SwapBuffers();
}

void GameWindow::processMouseDown(const SDL_MouseButtonEvent& event) {
    uiState.setMouseX(event.x);
    uiState.setMouseY(event.y);
    uiState.setMousePressed(true);
}

void GameWindow::processMouseUp(const SDL_MouseButtonEvent& event) {
    uiState.setMouseX(event.x);
    uiState.setMouseY(event.y);
    uiState.setMousePressed(false);
}

void GameWindow::processMouseMotion(const SDL_MouseMotionEvent& event) {
    uiState.setMouseX(event.x);
    uiState.setMouseY(event.y);
}

void GameWindow::processKeyDown(const SDL_KeyboardEvent& event)  {

}

void GameWindow::processKeyUp(const SDL_KeyboardEvent& event) {

}

void GameWindow::processQuit(const SDL_QuitEvent& event) {
    stopMainLoop();
}

void GameWindow::processEvents() {
    // Defino el evento a leer
    SDL_Event event;
    // Si hay evento
    if ( SDL_PollEvent(&event) ) {
        // Trato cada tipo de evento
        switch (event.type) {
            // Proceso bonton presionado
            case SDL_MOUSEBUTTONDOWN:
                processMouseDown(event.button);
                break;
            // Proceso boton soltado
            case SDL_MOUSEBUTTONUP:
                processMouseUp(event.button);
                break;
            // Proceso movimiento de mouse
            case SDL_MOUSEMOTION:
                processMouseMotion(event.motion);
                break;
            // Proceso tecla presionada
            case SDL_KEYDOWN:
                processKeyDown(event.key);
                break;
            // Proceso tecla liberada
            case SDL_KEYUP:
                processKeyUp(event.key);
                break;
            // Proceso quit
            case SDL_QUIT:
                processQuit(event.quit);
                break;
        }
    }
}

int GameWindow::run(int argc, char** argv) {
    if ( initializeSDL(argc, argv) ) {
        initializeOpenGL();

        runMainLoop();

        terminateOpenGL();
        terminateSDL();
       return 0;
    } else {
        return 1;
    }
}

