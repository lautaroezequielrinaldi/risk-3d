#ifndef PLAYER_H_
#define PLAYER_H_

#include <list>
#include<string>
#include "../smartpointer/referencecountptr.h"

/**
 * Clase cuyo proposito es representar a un jugador dentro del modelo del juego.
 */

class Player
{
	
	private:
		
		/**
		 * Colores:
		 * 1	rojo  
		 * 2	negro  
		 * 3	verde  
		 * 4	amarillo   
		 * 5	azul   
		 * 6	blanco
		 */
		int color;

		int ejercitosAUbicar;
		
		static int ultimoColorAsignado;
		
		/*paises conquistados*/
		std::list <std::string> listaPaisesConquistados;
		
		/*continentes conquistados*/
		std::list <std::string> listaContinentesConquistados;
		
	public:
		
		/**
		 * Constructor de la clase
		 */
		Player(int color,int armyCount);
		
		/**
		 * Constructor de la clase. 
		 * Asigna al jugador, un color que todavia no haya sido asignado.
		 */
		Player();
		
		/**
		 * Destructor de la clase
		 */
		~Player();
		
		/**
		 * Metodo cuyo proposito es obtener el color que identifica al jugador
		 */
		int getColor();
		 
		 /**
		  * Metodo cuyo proposito es establecer el color que identificara al jugador
		  */
		void setColor( int color);
		
		/**
		 * Metodo cuyo proposito es obtener la cantidad de ejercitos que posee el jugador para ubicar
		 */
		int getArmyCount();
		 
		 /**
		  * Metodo cuyo proposito es establecer la cantidad de ejercitos que podra ubicar el jugador.
		  */
		void setArmyCount(int armyCount);
					
		/**
		 * Metodo cuyo proposito es obtener la lista de nombres de los paises conquistados por un jugador
		 */
		std::list<std::string>& getConqueredLandList();
		
		/**
		 * Metodo cuyo proposito es obtener la lista de nombres de los continentes conquistados por un jugador
		 */
		std::list<std::string>& getConqueredContinentList();
		
		/**
		 * Metodo cuyo proposito es obtener la cantidad de paises conquistados por el jugador
		 */
		unsigned int getConqueredLands();
		
		/**
		 * Metodo cuyo proposito es obtener la cantidad de continentes conquistados por el jugador
		 */
		 unsigned int getConqueredContinents();
		 
		 /**
		 * Metodo cuyo proposito es agregar un pais a la lista de paises conquistados del jugador
		 */
		 void addConqueredLand(std::string & landName);
		 
		/**
		 * Metodo cuyo proposito es agregar un continente a la lista de continentes conquistados del jugador
		 */
		 void addConqueredContinent(std::string & continenName);
		 
		/**
		 * Metodo cuyo proposito es eliminar un pais a la lista de paises conquistados del jugador
		 */
		 void removeConqueredLand(std::string & landName);
		 
		 /**
		 * Metodo cuyo proposito es eliminar un continente a la lista de continentes conquistados del jugador
		 */
		 void removeConqueredContinent(std::string & continenName);
		 
		 /**
		  * Metodo cuyo proposito es verificar si un determinado pais esta conquistado por el jugador
		  */
		 bool landOwner(std::string & landName );
		  
		 /**
		  * Metodo cuyo proposito es verificar si un determinado continente esta conquistado por el jugador
		  */
		 bool continentOwner(std::string & continentName );
	
		/**
		 * Metodo cuyo proposito es transfrir los paises conquistados por el player indicado
		 * al player que invoca.
		 */
		 void transferLandsFrom(ReferenceCountPtr<Player>& player);	
	
		  
	private:
	
		  /**
		   * Metodo cuyo proposito es obtener un nuevo color que represente al jugador, sin repetir uno ya utilizado.
		   */	
		  int getNewColor();
	
};

#endif /*PLAYER_H_*/

