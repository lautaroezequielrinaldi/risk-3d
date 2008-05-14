#ifndef __UIMOUSEINFORMATION_H__
#define __UIMOUSEINFORMATION_H__

/**
 * Clase cuyo propòsito es almacenar informaciòn del estado del mouse
 * como su posiciòn X e Y, como que boton fue presionado.
 */
class UIMouseInformation {
    /**
     * Constantes y enumeraciones pùblicas de la clase UIMouseInformation.
     */
    public:
        /**
         * Enumeraciòn que representa si fue presionado el mouse o fue
         * soltado.
         */
        enum MouseReleaseStatus {
            /**
             * Enumeraciòn que representa que el mouse no tuvo
             * interacciòn.
             */
            MOUSE_RELEASE_NONE,
            /**
             * Enumeraciòn que representa que el mouse fue presionado.
             */
            MOUSE_RELEASE_PRESSED,
            /**
             * Enumeraciòn que representa que el mouse fue soltado.
             */
            MOUSE_RELEASE_RELEASED
        };
        /**
         * Enumeraciòn que representa el botòn del mouse que fue presionado
         * o fue soltado.
         */
        enum MouseButtonStatus {
            /**
             * Enumeraciòn que representa que ningùn boton del mouse
             * fue presionado o soltado.
             */
            MOUSE_BUTTON_NONE,
            /**
             * Enumeraciòn que representa que el botòn izquierdo del mouse
             * fue presionado o soltado.
             */
            MOUSE_BUTTON_LEFT,
            /**
             * Enumeraciòn que representa que el botòn central del mouse
             * fue presionado o soltado.
             */
            MOUSE_BUTTON_CENTER,
            /**
             * Enumeraciòn que representa que el botòn derecho del mouse
             * fue presionado o soltado.
             */
            MOUSE_BUTTON_RIGHT
        };

    /**
     * Atributos privados de la clase UIMouseInformation.
     */
    private:
        /**
         * Almacena el estado de presiòn del mouse.
         */
        MouseReleaseStatus releaseStatus;
        /**
         * Almacena el estado de los botones del mouse.
         */
        MouseButtonStatus buttonStatus;
        /**
         * Almacena la posiciòn X del mouse.
         */
        int x;
        /**
         * Almacena la posiciòn Y del mouse;
         */
        int y;

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
        MouseReleaseStatus& getReleaseStatus();
        /**
         * Mètodo cuyo propòsito es establecer el estado de presiòn del mouse.
         */
        void setReleaseStatus(const MouseReleaseStatus& releaseStatus);
        /**
         * Mètodo cuyo propòsito es obtener el estado de los botones del mouse.
         */
        MouseButtonStatus& getButtonStatus();
        /**
         * Mètodo cuyo propòsito es establecer el estado de los botones del
         * mouse.
         */
        void setButtonStatus(const MouseButtonStatus& buttonStatus);
        /**
         * Mètodo cuyo propòsito es obtener la posiciòn X del mouse.
         */
        int getX();
        /**
         * Mètodo cuyo propòsito es establecer la posicion X del mouse.
         */
        void setX(int x);
        /**
         * Mètodo cuyo propòstio es obtener la posiciòn Y del mouse.
         */
        int getY();
        /**
         * Mètodo cuyo propòsito es establecer la posiciòn Y del mouse.
         */
        void setY(int y);
        /**
         * Destructor virtual de la clase UIMouseInformation.
         */
        ~UIMouseInformation();
};

#endif /** __UIMOUSEINFORMATION_H__ */

