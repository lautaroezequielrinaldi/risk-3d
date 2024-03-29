#ifndef __MAP_H__
#define __MAP_H__

/**
 * server => client
 * 
 * Comando que se envia una unica vez con toda la informacion del juego
 * Hay que cambiar el nombre a Game algo
 */


#include <string>
#include <vector>
#include "command.h"
#include "../model/gamemanager.h"

class Map : public Command
{
	
	
	public:
		
		/*
		 * Constructor de la clase
		 * la idea es que reciba una lista de parametros y con ellos arme el ataque que se validara, en ppio
		 * sera una lista de strings y en el caso de necesitar convertir un elemento a int usare atoi.
		 */
		Map(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		Map(const std::string &xml);
		

		Map();
		/*
		 * Destructor de la clase
		 */
		 
		virtual ~Map();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();
		/**
		 * Metodo cuyo proposito es hidratar  un objeto a partir del Xml especificado.
		 */
		void* hydrate(const std::string &xml);
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);

		virtual std::string getName();
		
		/**
		 * Notifica que se ejecuto el comando.
		 */
		virtual void accept(CommandObserver* observer); 		
};

#endif /*__MAP_H__*/
