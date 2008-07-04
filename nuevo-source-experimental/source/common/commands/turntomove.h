#ifndef __TURNTOMOVE_H__
#define __TURNTOMOVE_H__

/**
 * server => client
 *
 * Indicacion del servidor de pasaje a estado Moving
 */

#include <string>
#include <vector>
#include "command.h"

class TurnToMove : virtual public Command
{
	
	
	private:
		int numeroJugador;
	public:
		
		/*
		 * Constructor de la clase
		 * la idea es que reciba una lista de parametros y con ellos arme el ataque que se validara, en ppio
		 * sera una lista de strings y en el caso de necesitar convertir un elemento a int usare atoi.
		 */
		TurnToMove(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		TurnToMove(const std::string & xml);
		

		TurnToMove();
		/*
		 * Destructor de la clase
		 */
		 
		virtual ~TurnToMove();
		
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

#endif /*__TURNTOMOVE_H__*/
