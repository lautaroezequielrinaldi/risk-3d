#ifndef __BUTTON_H__
#define __BUTTON_H__

#include<SDL/SDL.h>
//#include<SDL/SDL_image.h> comentado por charli para compilar
#include "uicontext.h"
#include "uihandler.h"
#include "uimouseinformation.h"
#include "uisupport.h"

class Button {
    /**
     * Atributo privado de la clase Button.
     */
    private:
        /**
         * Almacena el Id del boton.
         */
        UIHandler handler;
        /**
         * Almacena la posicion X del boton,
         */
        int x;
        /**
         * Almacena la posicion Y del boton.
         */
        int y;
        /**
         * Almacena el ancho del boton.
         */
        int width;
        /**
         * Almacena el alto del boton.
         */
        int height;

    /**
     * Mètodos privados de la clase Button,
     */
    private:
        /**
         * Constructor copia de la clase Button.
         */
        Button(const Button& otherInstance);
        /**
         * Operador de asignaciòn de la clase Button.
         */
        Button& operator=(const Button& otherInstance);

    /**
     * Mètodos pùblicos de la clase Button.
     */
    public:
        /**
         * Constructor de la clase Button.
         */
        Button(UIHandler handler, int x, int y, int width, int height);
        /**
         * Mètodo cuyo propòsito es dibujar el botòn de acuerdo al contexto
         * de la interfaz gràfica y devolver true si fue presionado o false
         * si no lo fue,
         */
        bool drawAndProcess(SDL_Surface* mainWindow, UIContext& uiContext);
        /**
         * Destructor virtual de la clase Button.
         */
        virtual ~Button();
};

#endif /** __BUTTON_H__ */

