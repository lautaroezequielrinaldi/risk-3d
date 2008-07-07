#ifndef __GAMEWINDOW_H__
#define __GAMEWINDOW_H__

#include "ui/sphere.h"
#include "ui/uistate.h"
#include "ui/button.h"
#include "ui/label.h"
#include "net/serverproxy.h"
#include "../../common/smartpointer/referencecountptr.h"
#include "../../common/commands/commandobserver.h"

class GameWindow: public CommandObserver {
    /**
     * Atributos privados de la clase GameWindow.
     */
    private:
        /**
         * Almacena el server proxy con el cual se va a comunicar.
         */
        ReferenceCountPtr<ServerProxy> serverProxy;
        /**
         * Indica si el main loop esta corriendo,
         */
        bool mainLoopRunning;
        /**
         * Alamcena el estado de la UI.
         */
        UIState uiState;
        /**
         * Almacena  el boton para fin de accion,
         */
        Button noMoreButton;
        /**
         * Almacena el boton para surrender.
         */
        Button surrenderButton;
        /**
         * Almacena el boton para quit.
         */
        Button quitButton;
        /**
         * Almacena el label para el pais bajo el mouse.
         */
        Label hooverCountryLabel;
        /**
         * Almacena el label para las unidades del pais bajo el mouse.
         */
        Label hooverUnitLabel;
        /**
         * Almacena el label para mensajes.
         */
        Label messageLabel;
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
         * Process sphere click.
         */
        void processSphereClick(); 
        /**
         * Process events.
         */
        void processEvents();
        /**
         * Disconnects and quits from the gane,
         */
        void disconnectAndQuit();
    /**
     * Metodos publicos de la clase GameWindow.
     */
    public:
        /**
         *  Constructor de la clase GameWindow.
          */
        GameWindow(const ReferenceCountPtr<ServerProxy>& = NULL);
        /**
         * Destructor virtual de la clase GameWindow.
         */
        virtual ~GameWindow();
        /**
         * Termina el main loop.
         */
        void stopMainLoop();
        /**
         * Obtiene el proxy server usado en el juego.
         */
        ReferenceCountPtr<ServerProxy> getServerProxy() const;
        /**
         * Pone a correr la ventana principal del juego.
         */
        int run(int argc, char** argv);
};
  
#endif /** __GAMEWINDOW_H__ */

