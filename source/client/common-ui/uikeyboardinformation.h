#ifndef __UIKEYBOARDINFORMATION_H__
#define __UIKEYBOARDINFORMATION_H__

#include<SDL/SDL.h> // Para definiciòn de

/**
 * Clase cuyo propòsito es almacenar informaciòn del estado del
 * keyboard, como que teclas fueron presionadas y cuales
 * liberadas.
 */
class UIKeyboardInformation {
    /**
     * Atributos privados de la clase UIKeyboardInformation.
     */
    private:
        /**
         * Almacena un vector de teclas indicando true si esta presionada y
         * false si no lo està.
         */
        bool keyboard[SDLK_MAX];

    /**
     * Mètodos pùblicos de la clase UIKeyboardInformation.
     */
    public:
        /**
         * Constructor de la clase UIKeyboardInformation.
         */
        UIKeyboardInformation();
        /**
         * Mètodo cuyo propòsito es marcar una tecla del teclado como
         * presionada.
         */
        void markKeyPressed(int key);
        /**
         * Mètodo cuyo propòsito es marcar una tecla del teclado como
         * no presionada.
         */
        void markKeyUnpressed(int key);
        /**
         * Mètodo cuyo propòsito es obtener el estado de presion de una tecla
         * del teclado.
         */
        bool isKeyPressed(int key);
        /**
         * Destructor virtual de la clase UIKeyboardInformation.
         */
        ~UIKeyboardInformation();
};

#endif /** __UIKEYBOARDINFORMATION_H__ */

