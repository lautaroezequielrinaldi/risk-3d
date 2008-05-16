#include "application.h"
#include<iostream>
Application::Application():
    mainWindow(NULL),
    uiContext(),
    running(true) {
    SDL_Init(SDL_INIT_EVERYTHING);
    mainWindow = SDL_SetVideoMode(1024,768, 32, SDL_DOUBLEBUF | SDL_RESIZABLE);
    if (mainWindow == NULL) {
        std::cout << "No se pudo crear ventana" << std::endl;
    }
}

void Application::processKeyboardEvent(SDL_KeyboardEvent event) {
    // Obtengo la informaciòn del teclado desde el contexto de interfaz
    // gràfica.
    ReferenceCountPtr<UIKeyboardInformation> keyboardInformation =
        this->uiContext.getKeyboardInformation();

    // Si el evento es de presiòn de tecla.
    if ( event.type == SDL_KEYDOWN ) {
        // Marco la tecla como presionada.
        keyboardInformation->markKeyPressed(event.keysym.sym);
    } else {
        // Marco la tecla como liberada.
        keyboardInformation->markKeyUnpressed(event.keysym.sym);
    }
}

void Application::processMouseButtonEvent(SDL_MouseButtonEvent event) {
    // Obtengo la informaciòn del mouse desde el contexto de interfaz gràfica
    ReferenceCountPtr<UIMouseInformation> mouseInformation =
        this->uiContext.getMouseInformation();

    // Establezco las coordenadas X e Y del mouse.
    mouseInformation->setX(event.x);
    mouseInformation->setY(event.y);

    // Establezco el botòn del mouse con el cual se interactuò.
    mouseInformation->setButtonStatus(event.button);

    // Establezco el estado de presiòn del boton del mouse.
    mouseInformation->setReleaseStatus(event.state);
}

void Application::processMouseMotionEvent(SDL_MouseMotionEvent event) {
    // Obtengo la informaciòn del mouse desde el contexto de interfaz gràfica
    ReferenceCountPtr<UIMouseInformation> mouseInformation =
        this->uiContext.getMouseInformation();

    // Establezco las coordenadas X e Y del mouse.
    mouseInformation->setX(event.x);
    mouseInformation->setY(event.y);
}

void Application::processQuitEvent(SDL_QuitEvent event) {
    this->running = false;
}

void Application::processEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                this->processKeyboardEvent(event.key);
                break;
            case SDL_KEYUP:
                this->processKeyboardEvent(event.key);
                break;
            case SDL_MOUSEBUTTONDOWN:
                this->processMouseButtonEvent(event.button);
                break;
            case SDL_MOUSEBUTTONUP:
                this->processMouseButtonEvent(event.button);
                break;
            case SDL_MOUSEMOTION:
                this->processMouseMotionEvent(event.motion);
                break;
            case SDL_QUIT:
                this->processQuitEvent(event.quit);
                break;
        }
    }
}

void Application::draw() {
    UIHandler handler;
    Button button(handler, 10, 10, 50, 50);
    if (button.drawAndProcess(mainWindow, uiContext)) {
        std::cout << "Se presiono el boton" << std::endl;
    }
    SDL_Flip(mainWindow);
}

void Application::execute() {
    // Aca va el codigo que inicializa SDL
    while (running) {
        this->processEvents();
        this->draw();
    }
}

Application::~Application() {
    SDL_Quit();
}

