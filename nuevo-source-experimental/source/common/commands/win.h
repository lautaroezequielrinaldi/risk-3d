#ifndef __WIN_H__
#define __WIN_H__

/**
 * server => client
 * 
 * Mensaje que se envia a todos los clientes informando quien gano
 */

#include <string>
#include <vector>
#include "command.h"
#include "../model/gamemanager.h"

class Win : public Command
{
	
	
	private:
		int numeroJugador;
	public:
		
		/*
		 * Constructor de la clase
		 * la idea es que reciba una lista de parametros y con ellos arme el ataque que se validara, en ppio
		 * sera una lista de strings y en el caso de necesitar convertir un elemento a int usare atoi.
		 */
		Win(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		Win( const std::string &xml);
		

		Win();
		/*
		 * Destructor de la clase
		 */
		 
		virtual ~Win();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();

		
		virtual std::string getName();

		/**
		 * Notifica que se ejecuto un comando.
		 */
		virtual void accept(CommandObserver* observer); 		
		
};

#endif /*__WIN_H__*/
