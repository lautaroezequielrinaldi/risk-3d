#ifndef __GAME_H__
#define __GAME_H__

#include "mapa.h" // Para definiciòn de Mapa.
#include "player.h" // Para definiciòn de Player.
#include "../smartpointer/referencecountptr.h" // Para definiciòn de
// ReferenceCountPtr.
#include "../parser/serializable.h" // Para definiciòn de Serializable.

/**
 * Clase cuyo propòsito es encapsular al juego.
 */
class Game: public Serializable {
    /**
     * Atributos privados de la clase Game.
     */
    private:
        /**
         * Almacena el mapa asociado al juego.
         */
        ReferenceCountPtr<Mapa> mapa;
        /**
         * Almacena la lista de jugadores del juego.
         */
        std::list< ReferenceCountPtr<Player> > playerList;

    /**
     * Mètodos privados de la clase Game.
     */
    private:
        /**
         * Constructor copia de la clase Game.
         */
        Game(const Game& otherInstance);
        /**
         * Operador de asignaciòn de la clase Game.
         */
        Game& operator=(const Game& otherInstance);

    /**
     * Mètodos pùblicos de la clase Game.
     */
    public:
        /**
         * Constructor de la clase Game.
         */
        Game();
        /**
         * Constructor de la clase Game.
         */
        Game(const ReferenceCountPtr<Mapa>& mapa,
            const std::list< ReferenceCountPtr<Player> >& playerList);
        /**
         * Constructor de la clase Game.
         */
        Game(const std::list< ReferenceCountPtr<Player> >& playerList);
        /**
         * Constructor de la clase Game.
         */
        Game(const ReferenceCountPtr<Mapa>& mapa);
        /**
         * Establece el mapa asociado al juego.
         */
        void setMapa(const ReferenceCountPtr<Mapa>& mapa);
        /**
         * Obtiene el mapa asociado al juego.
         */
        ReferenceCountPtr<Mapa>& getMapa();
        /**
         * Establece la lista de jugadores del juego.
         */
        void setPlayerList(
            const std::list< ReferenceCountPtr<Player> >& playerList);
        /**
         * Obtiene la lista de jugadores del juego.
         */
        std::list< ReferenceCountPtr<Player> >& getPlayerList();

        ReferenceCountPtr<Player> addPlayer();

        
        /**
         * Obtiene el jugador correspondinte al color especificado.
         * Retorna el jugador correspondiente o NULL en caso de no encontrar jugador con el color especificado.
         */
        ReferenceCountPtr<Player> getPlayer(int color);
        
        /**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
        std::string serialize();

		/**
		 * Metodo cuyo proposito es hidratar  un objeto a partir del Xml especificado.
		 */
		void* hydrate(std::string filename);
                
        /**
         * Destructor virtual de la clase Game.
         */
        virtual ~Game();
};

#endif /* __GAME_H__ */

