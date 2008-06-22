#ifndef __DEFENDFACTORY__
#define __DEFENDFACTORY__

#include "commandfactory.h"
#include "defend.h"


class DefendFactory : public CommandFactory{
	
	
	DefendFactory();

	~DefendFactory();

	/**
	 * Metodo cuyo proposito es crear un comando a partir de una lista de parametros.
	 */
	ReferenceCountPtr<Command> createCommand(std::vector<std::string> &parameterList);
		
	/**
	 * Metodo cuyo proposito es crear un comando a partir de un xml almacenado en un String.
	 */
	ReferenceCountPtr<Command> createCommand(std::string & xml );
	
		
	
};














#endif /* __DEFENDFACTORY__*/
