#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>

#include "../common-ui/uicontext.h" // Para definiciòn de UIContext.
#include "../common-ui/uikeyboardinformation.h" // Para definiciòn de
// UIkeyboardInformation.
#include "../common-ui/uimouseinformation.h" // Para definiciòn de
// UIMouseInformation.
#include "../common-ui/button.h" // Para definiciòn de Button
#include "../../common/smartpointer/referencecountptr.h" // Para definiciòn de
// ReferenceCountPtr.

/**
 * Clase cuyo propòsito es representar la aplicaciòn del editor de mapas.
 */
class Application {
    /**
     * Atributos privados de la clase Application.
     */
    private:
        /**
         * Almacena la superficie que representa la ventana principal de la
         * aplicaciòn.
         */
        SDL_Surface* mainWindow;
        /**
         * Almacena el contexto de la interfaz gràfica de usuario de la
         * aplicaciòn.
         */
        UIContext uiContext;
        /**
         * Almacena un flag booleano indicando si està corriendo la apliaciòn
         * o no.
         */
        bool running;

    /**
     * Mètodos privados de la clase Application.
     */
    private:
        /**
         * Constructor copia de la clase Application.
         */
        Application(const Application& otherInstance);
        /**
         * Operador de asignaciòn de la clase Application.
         */
        Application& operator=(const Application& otherInstance);
        /**
         * Mètodo cuyo propòsito es procesar el evento de teclado de la
         * aplicaciòn.
         */
        void processKeyboardEvent(SDL_KeyboardEvent event);
        /**
         * Mètodo cuyo propòsito es procesar el evento de boton de mouse de la
         * aplicaciòn.
         */
        void processMouseButtonEvent(SDL_MouseButtonEvent event);
        /**
         * Mètodo cuyo propòsito es procesar el evento de movimiento de mouse
         * de la aplicaciòn.
         */
        void processMouseMotionEvent(SDL_MouseMotionEvent event);
        /**
         * Mètodo cuyo propòsito es procesar el evento de salida de la
         * aplicaciòn.
         */
        void processQuitEvent(SDL_QuitEvent event);
        /**
         * Mètodo cuyo propòsito es el de verificar si hay algun evento
         * disponible a procesar y delegarlo a los mètodos que procesan cada
         * tipo de evento en particular.
         */
        void processEvents();
        /**
         * Mètodo cuyo propòsito es el de dibujar la interfaz gràfica de la
         * aplicaciòn.
         */
        void draw();

    /**
     * Mètodos pùblicos de la clase Application.
     */
    public:
        /**
         * Constructor de la clase Application.
         */
        Application();
        /**
         * Mètodo cuyo propòsito es ejecutar la aplicaciòn hasta que el usuario
         * decida salir de la misma.
         */
        void execute();
        /**
         * Destructor virtual de la clase Application.
         */
        virtual ~Application();
};
 
#endif /** __APPLICATION_H__ */

