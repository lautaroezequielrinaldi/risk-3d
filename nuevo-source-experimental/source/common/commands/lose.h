#ifndef __LOSE_H__
#define __LOSE_H__


/**
 * server => client
 * 
 * Mensaje que se envia a todos los clientes informando quien perdio
 */

#include <string>
#include <vector>
#include "command.h"

class Lose : virtual public Command
{
	
	private:
		int numeroJugador;

	public:
		
		/*
		 * Constructor de la clase
		 * la idea es que reciba una lista de parametros y con ellos arme el ataque que se validara, en ppio
		 * sera una lista de strings y en el caso de necesitar convertir un elemento a int usare atoi.
		 */
		Lose(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		Lose(const std::string & xml);
		

		Lose();
		/*
		 * Destructor de la clase
		 */
		 
		virtual ~Lose();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();

		
		virtual std::string getName();

		/**
		 * Notifica que se ejecuto el comando.
		 */
		virtual void accept(CommandObserver* observer);		
		
};

#endif /*__lose_H__*/
