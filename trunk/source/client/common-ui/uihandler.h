#ifndef __UIHANDLER_H__
#define __UIHANDLER_H__

/**
 * Macro GEN_ID que devuelve o genera un ID de elemento grafico ùnico.
 */
#define STRINGERMACRO( x ) #x 
#define GEN_ID (int)(__FILE__ STRINGERMACRO(__LINE__))

/**
 * Clase cuyo propòsito es identificar a un control grafico dentro de una
 * interfaz grafica Inmediate Mode GUI.
 */
class UIHandler {
    /**
     * Atributos privados de la clase UIHandler.
     */
    private:
        /**
         * Almacena el ID del elemento gràfico actual.
         */
        int elementId;
        /**
         * Almacena el ìndice del elemento gràfico en el array de elementos
         * gràficos. Si el elemento gràfico no se encuentra dentro de un array
         * de elementos gràficos su ìndice serà 0.
         */
        int arrayIndex;

    /**
     * Mètodos pùblicos de la clase UIHandler.
     */
    public:
        /**
         * Constructor de la clase UIHandler.
         * Construye un UIHandler a partir del ID de elemento gràfico actual.
         */
        UIHandler(int elementId = GEN_ID);
        /**
         * Mètodo cuyo propòsito es obtener el ID del elemento gràfico actual.
         */
        int getElementId();
        /**
         * Mètodo cuyo propòsito es establecer el ID del elemento gràfico
         * actual.
         */
        void setElementId(int elementId);
        /**
         * Mètodo cuyo propòsito es obtener el ìndice del elemento gràfico
         * actual dentro del array de elementos gràficos.
         */
        int getArrayIndex();
        /**
         * Mètodo cuyo propòsito es establecer el ìndice  del elemento gràfico
         * actual dentro del array de elementos gràficos.
         */
        void setArrayIndex(int arrayIndex);
        /**
         * Operador de comparaciòn de la clase UIHandler.
         */
        bool operator==(const UIHandler& otherInstance);
        /**
         * Operador de comparaciòn de la clase UIHandler.
         */
        bool operator!=(const UIHandler& otherInstance);
        /**
         * Destructor virtual de la clase UIHandler.
         */
        ~UIHandler();
};

#endif /** __UIHANDLER_H__ */

