#ifndef __COMMANDFACTORY__
#define __COMMANDFACTORY__


#include "command.h"

class CommandFactory{
	
	public:
	
		CommandFactory();

		virtual ~CommandFactory();

		/**
		 * Metodo cuyo proposito es crear un comando a partir de una lista de parametros.
		 */
		virtual ReferenceCountPtr<Command> createCommand(std::vector<std::string> &parameterList)=0;
		
		/**
		 * Metodo cuyo proposito es crear un comando a partir de un xml almacenado en un String.
		 */
		virtual ReferenceCountPtr<Command> createCommand(std::string & xml ) =0;
	
	
	
	
	
};





#endif /*__COMMANDFACTORY__*/
