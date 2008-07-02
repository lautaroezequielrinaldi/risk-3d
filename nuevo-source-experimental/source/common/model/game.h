#ifndef __GAME_H__
#define __GAME_H__

#include "mapa.h" // Para definiciòn de Mapa.
#include "player.h" // Para definiciòn de Player.
#include "dice.h" // PAra def de Dado
#include "../smartpointer/referencecountptr.h" // Para definiciòn de
// ReferenceCountPtr.
#include "../parser/serializable.h" // Para definiciòn de Serializable.
#include<vector>

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
         * Almacena el dado con el que se jugara.
         */
        Dice& dado;

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
        Game(Dice& dice);
        /**
         * Constructor de la clase Game.
         */
        Game(const ReferenceCountPtr<Mapa>& mapa,
            const std::list< ReferenceCountPtr<Player> >& playerList,
            Dice& dice);
        /**
         * Constructor de la clase Game.
         */
        Game(const std::list< ReferenceCountPtr<Player> >& playerList, Dice& dice);
        /**
         * Constructor de la clase Game.
         */
        Game(const ReferenceCountPtr<Mapa>& mapa, Dice& dice);
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
        void setPlayerList(const std::list< ReferenceCountPtr<Player> >& playerList);
        /**
         * Obtiene la lista de jugadores del juego.
         */
        std::list< ReferenceCountPtr<Player> >& getPlayerList();

		/**
		 * Para solicitarle al Game que cree un nuevo jugador y lo devuelva
		 *
		 */
        ReferenceCountPtr<Player> & addPlayer();

        /**
         * Obtiene el jugador correspondinte al color especificado.
         * Retorna el jugador correspondiente o NULL en caso de no encontrar jugador con el color especificado.
         */
        ReferenceCountPtr<Player> getPlayer(int color);
        
        /**
         * Metodo cuyo proposito es obtener el dado que se utilizara para jugar.
         */
      	Dice& getDice();
      	
      	/**
      	 * Metodo cuyo proposito es establecer el dado que utilizara el juego.
      	 */
      	void setDice( Dice & dice );
        
        /**
         * Metodo cuyo proposito es devolver el id del jugador dueño del pais countryName.
         * Si el pais no tiene dueño, devuelve cero.
         */
        int getCountryOwner(std::string & countryName);
        
       /**
	* Metodo cuyo proposito es verificar si un conjunto de paises forman uno o mas continentes del mapa del juego.
	* Retorna un vector con los nombres de los continentes formados por los paises de countryList.
	*/
	std::vector<std::string> conformContinent(const std::list<std::string>& countryList);

        /**
	* Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
	*/
        std::string serialize();

	/**
		* Metodo cuyo proposito es hidratar  un objeto a partir del Xml especificado.
		*/
	void* hydrate(const std::string & filename);


	void remove(int color);
                
        /**
         * Destructor virtual de la clase Game.
         */
        virtual ~Game();
};

#endif /* __GAME_H__ */

