#ifndef __POPULATEFACTORY__
#define __POPULATEFACTORY__
#include "commandfactory.h"
#include "populate.h"


class PopulateFactory : public CommandFactory{
	
	PopulateFactory();

	~PopulateFactory();

	
	/**
	 * Metodo cuyo proposito es crear un comando a partir de una lista de parametros.
	 */
	ReferenceCountPtr<Command> createCommand(std::vector<std::string> &parameterList);
		
	/**
	 * Metodo cuyo proposito es crear un comando a partir de un xml almacenado en un String.
	 */
	ReferenceCountPtr<Command> createCommand(std::string & xml );
	
	
	
	
	
};








#endif /* __POPULATEFACTORY__*/
