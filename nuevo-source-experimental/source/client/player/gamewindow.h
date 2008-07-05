#ifndef __GAMEWINDOW_H__
#define __GAMEWINDOW_H__

#include "ui/sphere.h"
#include "ui/uistate.h"
#include "ui/button.h"

class GameWindow {
    /**
     * Atributos privados de la clase GameWindow.
     */
    private:
        /**
         * Indica si el main loop esta corriendo,
         */
        bool mainLoopRunning;
        /**
         * Alamcena el estado de la UI.
         */
        UIState uiState;
        /**
         * Almacena el boton.
         */
        Button button;
        /**
         * Almacena la efera.
         */
        Sphere sphere;

    /**
     * Metodos privados de la clase GameWindow.
     */
    private:
        /**
         * Inicializa SDL.
         */
        bool initializeSDL(int argc, char** argv);
        /**
         * Inicializa OpenGL.
         */
        void initializeOpenGL();
        /**
         * Terminate SDL.
         */
        void terminateSDL();
        /**
         * Termiantes OpenGL.
         */
        void terminateOpenGL();
        /**
         * Corre Main Loop.
         */
        void runMainLoop();
        /**
         * Termina el main loop.
         */
        void stopMainLoop();
        /**
         * Habilita el modo 2D.
         */
        void enable2D();
        /**
         * Deshabilita el modo 2D.
         */
        void disable2D();
        /**
         * Updatea la escena.
         */
        void updateScene();
        /**
         * Dibuja la escena.
         */
        void drawScene();
        /**
         * Process mouse down event.
         */
        void processMouseDown(const SDL_MouseButtonEvent& event);
        /**
         * Process mouse up event.
         */
        void processMouseUp(const SDL_MouseButtonEvent& event);
        /**
         * Process mouse motion event.
         */
        void processMouseMotion(const SDL_MouseMotionEvent& event);
        /**
         * Process key down.
         */
        void processKeyDown(const SDL_KeyboardEvent& event);
        /**
         * Process key up.
         */
        void processKeyUp(const SDL_KeyboardEvent& event);
        /**
         * Process quit,
         */
        void processQuit(const SDL_QuitEvent& event);
        /**
         * Process events.
         */
        void processEvents();
    /**
     * Metodos publicos de la clase GameWindow.
     */
    public:
        /**
         *  Constructor de la clase GameWindow.
         */
        GameWindow();
        /**
         * Destructor virtual de la clase GameWindow.
         */
        virtual ~GameWindow();
        /**
         * Pone a correr la ventana principal del juego.
         */
        int run(int argc, char** argv);
};
  
#endif /** __GAMEWINDOW_H__ */
