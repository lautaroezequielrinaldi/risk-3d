#ifndef __UIMOUSEINFORMATION_H__
#define __UIMOUSEINFORMATION_H__

#include<SDL/SDL.h> // Para definiciòn de Uint8, Uint16

/**
 * Clase cuyo propòsito es almacenar informaciòn del estado del mouse
 * como su posiciòn X e Y, como que boton fue presionado.
 */
class UIMouseInformation {
    /**
     * Atributos privados de la clase UIMouseInformation.
     */
    private:
        /**
         * Almacena el estado de presiòn del mouse.
         */
        Uint8 releaseStatus;
        /**
         * Almacena el estado de los botones del mouse.
         */
        Uint8 buttonStatus;
        /**
         * Almacena la posiciòn X del mouse.
         */
        Uint16 x;
        /**
         * Almacena la posiciòn Y del mouse;
         */
        Uint16 y;

    /**
     * Mètodos pùblicos de la clase UIMouseInformation.
     */
    public:
        /**
         * Constructor de la clase UIMouseInformation.
         */
        UIMouseInformation();
        /**
         * Mètodo cuyo propòsito es obtener el estado de presiòn del mouse.
         */
        Uint8 getReleaseStatus() const;
        /**
         * Mètodo cuyo propòsito es establecer el estado de presiòn del mouse.
         */
        void setReleaseStatus(const Uint8& releaseStatus);
        /**
         * Mètodo cuyo propòsito es obtener el estado de los botones del mouse.
         */
        Uint8 getButtonStatus() const;
        /**
         * Mètodo cuyo propòsito es establecer el estado de los botones del
         * mouse.
         */
        void setButtonStatus(const Uint8& buttonStatus);
        /**
         * Mètodo cuyo propòsito es obtener la posiciòn X del mouse.
         */
        Uint16 getX() const;
        /**
         * Mètodo cuyo propòsito es establecer la posicion X del mouse.
         */
        void setX(const Uint16& x);
        /**
         * Mètodo cuyo propòstio es obtener la posiciòn Y del mouse.
         */
        Uint16 getY() const;
        /**
         * Mètodo cuyo propòsito es establecer la posiciòn Y del mouse.
         */
        void setY(const Uint16& y);
        /**
         * Destructor virtual de la clase UIMouseInformation.
         */
        virtual ~UIMouseInformation();
};

#endif /** __UIMOUSEINFORMATION_H__ */

