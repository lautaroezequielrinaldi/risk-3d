#ifndef __YOUARE_H__
#define __YOUARE_H__

/**
 * server => client
 * 
 * mensaje que se envia tras un JoinGame informando al cliente cual es su numero
 */


#include <string>
#include <vector>
#include "command.h"
#include "../model/gamemanager.h"

class YouAre : public Command
{
	
	private:
		int numeroJugador;
	
	public:
		
		/*
		 * Constructor de la clase
		 * la idea es que reciba una lista de parametros y con ellos arme el ataque que se validara, en ppio
		 * sera una lista de strings y en el caso de necesitar convertir un elemento a int usare atoi.
		 */
		YouAre(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		YouAre( std::string xml);
		

		YouAre();
		/*
		 * Destructor de la clase
		 */
		 
		virtual ~YouAre();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();

		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);
		
		virtual std::string getName();
		
		
};

#endif /*__YOUARE_H__*/
