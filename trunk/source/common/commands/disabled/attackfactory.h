#ifndef __ATTACKFACTORY__
#define __ATTACKFACTORY__

#include "commandfactory.h"
#include "attack.h"

class AttackFactory : public CommandFactory{
	
	
		AttackFactory();

		~AttackFactory();
	
		/**
		 * Metodo cuyo proposito es crear un comando a partir de una lista de parametros.
		 */
		ReferenceCountPtr<Command> createCommand(std::vector<std::string> &parameterList);
		
		/**
		 * Metodo cuyo proposito es crear un comando a partir de un xml almacenado en un String.
		 */
		ReferenceCountPtr<Command> createCommand(std::string & xml );
	
	
	
	
};




#endif /* __ATTACKFACTORY__*/
