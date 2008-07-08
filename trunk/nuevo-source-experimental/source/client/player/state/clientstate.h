#ifndef __CLIENTSTATE_H__
#define __CLIENTSTATE_H__

#include<vector>
#include<string>
#include<sstream>
#include "../../../common/model/pais.h"
#include "../../../common/smartpointer/referencecountptr.h"

class GameWindow;

class ClientState {
    /**
     * Atributos privados de la clase ClientState.
     */
    private:
        /**
         * Almacena la ventana de juego que realiza las acciones.
         */
        GameWindow& gameWindow;
        /**
         * Almacena la cantidad de unidades a procear en dicho pais.
         */
        int armyCount;
        /**
         * Almacena el incremento de unidades.
         */
        int armyIncrement;
        /**
         * Almacena el primer pais seleccionado.
         */
        ReferenceCountPtr<Pais> firstCountry;
        /**
         * Almacena el segundo pais seleccionado.
         */
        ReferenceCountPtr<Pais> secondCountry;

    /**
     * Metodos publicos de la clse ClientState.
     */
    public:
        /**
         * Constructor de la clase ClientState.
         */
        ClientState(GameWindow& gameWindow);
        /**
         * Obtiene el GameWindow asociado al estado.
         */
        GameWindow& getGameWindow() const;
        /**
         * Procesa la seleccion de un pais.
         */
        virtual void selectCountry(ReferenceCountPtr<Pais>& pais);
        /**
         * Ejecuta el quit.
         */
        virtual void executeQuit();
        /**
         * Ejecuta surrender.
         */
        virtual void executeSurrender();
        /**
         * Ejecuta NoMore.
         */
        virtual void executeNoMore();
        /**
         * Ejecuta did I win.
         */
        virtual void executeDidIWin();
        /**
         * Obtiene la cantidad de unidades procesadas en un pais.
         */
        int getArmyCount() const;
        /**
         * Establece primer pais seleccioando.
         */
        void setFirstCountry(const ReferenceCountPtr<Pais>& country);
        /**
         * Establece segundo pais seleccionado.
         */
        void setSecondCountry(const ReferenceCountPtr<Pais>& country);
        /**
         * Obtiene primer pais seleccionado.
         */
        ReferenceCountPtr<Pais> getFirstCountry() const;
        /**
         * Obtiene segundo pais seleccionado.
         */
        ReferenceCountPtr<Pais> getSecondCountry() const;
        /**
         * Destructor virtual de la clase ClientState.
         */
        virtual ~ClientState();
};

#endif /** __CLIENTSTATE_H__ */

