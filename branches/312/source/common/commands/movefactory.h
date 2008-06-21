#ifndef __MOVEFACTORY__
#define __MOVEFACTORY__

#include "commandfactory.h"
#include "move.h"

class MoveFactory : public CommandFactory{
	
	
		MoveFactory();

		~MoveFactory();
	
		/**
		 * Metodo cuyo proposito es crear un comando a partir de una lista de parametros.
		 */
		ReferenceCountPtr<Command> createCommand(std::vector<std::string> &parameterList);
		
		/**
		 * Metodo cuyo proposito es crear un comando a partir de un xml almacenado en un String.
		 */
		ReferenceCountPtr<Command> createCommand(std::string & xml );
	
	
	
	
};


#endif /* __MOVEFACTORY__*/

