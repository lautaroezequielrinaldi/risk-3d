#ifndef __GAMEWINDOW_H__
#define __GAMEWINDoW_H__

#include<SDL.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include "ui/uistate.h"
#include "ui/button.h"

class GameWindow {
    /**
     * Atributos privados de la clase GameWindow.
     */
    private:
		/**
		 * Almacena el estado de la UI.
		 */
		UIState uiState;
		/**
		 * Almacena un boton.
		 */
		Button button;
        /**
         * Almacena un flag booleano indicando si esta corriendo el main loop.
         */
        bool running;

    /**
     * Metodos privados de la clase GameWindow.
     */
    private:
        /**
         * Metodo cuyo propòsito es iniciar SDL en el mejor modo de video grafico.
         */
        bool initializeSDL(int argc, char** argv);
        /**
         * Metodo cuyo proposito es iniciar OpenGL en el mejor modo de video grafico.
         */
        void initializeOpenGL();
        /**
         * Metodo cuyo propòsito es terminar SDL.
         */
        void terminateSDL();
        /**
         * Metodo cuyo propòsito es terminar OpenGL.
         */
        void terminateOpenGL();
        /**
         * Habilita modo 2D.
         */
        void enable2D();
        /**
         * Deshabilita modo 2D.
         */
        void disable2D();
        /**
         * Metodo cuyo propòsito es actualizar la escena grafica.
         */
        void updateScene();
        /**
         * Metodo cuyo propòsito es dibujar la escena grafica.
         */
        void drawScene();
        /**
         * Metodo cuyo propòsito es ejecutar el main loop del juego.
         */
        void mainLoop();
        /**
         * Obtiene un flag indicando si esta corriendo o no.
         */
        bool isRunning();
        /**
         * Mètodo cuyo proposito es cancelar la ejecucion de la aplicacion.
         */
        void stopRunning();
        /**
         * Process Events.
         */
        void processEvents();
        /**
         * Process mouse down event.
         */
        void processMouseDownEvent(const SDL_MouseButtonEvent& event);
        /**
         * Process mouse up event.
         */
        void processMouseUpEvent(const SDL_MouseButtonEvent& event);
        /**
         * Process mouse motion event.
         */
        void processMouseMotionEvent(const SDL_MouseMotionEvent& event);
        /**
         * Process key down event.
         */
        void processKeyDownEvent(const SDL_KeyboardEvent& event);
        /**
         * Process key up event.
         */
        void processKeyUpEvent(const SDL_KeyboardEvent& event);
        /**
         * Process a quit event.
         */
        void processQuitEvent(const SDL_QuitEvent& event);
    /**
     * Mètodos pùblicos de clase GameWindow.
     */
    public:
        /**
         * Constructor de la clase GameWindow.
         */
        GameWindow();
        /**
         * Ejecuta el main loop del juego.
         */
        int run(int argc, char** argv);
        /**
         * Destructor virtual de la clase GameWindow.
         */
        virtual ~GameWindow();
};

#endif /** __GAMEWINDOW_H__ */

