#ifndef __UICONTEXT_H__
#define __UICONTEXT_H__

#include "../../common/smartptr/referencecountptr.h" // Para definicion de 
//ReferenceCountPtr
#include "uihandler.h" // Para definiciòn de UIHandler
#include "uimouseinformation.h" // Para definiciòn de UIMouseInformation
#include "uikeyboardinformation.h" // Para definiciòn de UIKeyboardInformation

/**
 * Clase cuyo propòsito es almacenar informaciòn del contexto de la interfaz
 * gràfica de usuario, como cual es el item Hot y Activo e informaciòn
 * del mouse y del teclado. 
 */
class UIContext {
    /**
     * Atributos privados de la clase UIContext.
     */
    private:
        /**
         * Almacena el item sobre el cual el usuario actualmente esta apunto de
         * interactuar.
         */
        ReferenceCountPtr<UIHandler> hotItem;
        /**
         * Almacena el item activo con el cual el usuario esta interactuando.
         */
        ReferenceCountPtr<UIHandler> activeItem;
        /**
         * Almacena la informaciòn del mouse.
         */
        ReferenceCountPtr<UIMouseInformation> mouseInformation;
        /**
         * Almacena la informaciòn del keyboard.
         */
        ReferenceCountPtr<UIKeyboardInformation> keyboardInformation;

    /**
     * Mètodos privados de la clase UIContext.
     */
    private:
        /**
         * Constructor copia de la clase UIContext.
         */
        UIContext(const UIContext& otherInstance);
        /**
         * Operador de asignaciòn de la clase UIContext.
         */
        UIContext& operator=(const UIContext& otherInstance);

    /**
     * Mètodos pùblicos de la clase UIContext.
     */
    public:
        /**
         * Constructor de la clase UIContext.
         */
        UIContext();
        /**
         * Mètodo cuyo propòsito es obtener el item sobre el cual el usuario
         * està a punto de interactuar.
         */
        ReferenceCountPtr<UIHandler> getHotItem();
        /**
         * Mètodo cuyo propòsito es establecer el item sobre el cual el usuario
         * està a punto de interactuar.
         */
        void setHotItem(ReferenceCountPtr<UIHandler> hotItem);
        /**
         * Mètodo cuyo propòsito es obtener el item activo con el cual el
         * usuario està interactuando.
         */
        ReferenceCountPtr<UIHandler> getActiveItem();
        /**
         * Mètodo cuyo propòsito es devolver el item activo con el cual el
         * usuario està interactuando.
         */
        void setActiveItem(ReferenceCountPtr<UIHandler> activeItem);
        /**
         * Mètodo cuyo propòsito es obtener la informaciòn del mouse.
         */
        ReferenceCountPtr<UIMouseInformation> getMouseInformation();
        /**
         * Mètodo cuyo propòsito es establecer la informaciòn del mouse.
         */
        void setMouseInformation(ReferenceCountPtr<UIMouseInformation> mouseInformation);
        /**
         * Mètodo cuyo propòsito es obtener la informaciòn del teclado.
         */
        ReferenceCountPtr<UIKeyboardInformation> getKeyboardInformation();
        /**
         * Mètodo cuyo propòsito es establecer la informaciòn del teclado.
         */
        void setKeyboardInformation(
            ReferenceCountPtr<UIKeyboardInformation> keyboardInformation);
        /**
         * Destructor virtual de la clase UIContext.
         */
        ~UIContext();
};

#endif /** __UICONTEXT_H__ */

