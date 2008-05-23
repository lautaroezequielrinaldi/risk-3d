#include "commandfactoryfactory.h"


/*
 * 
 *
 *
 *
 */


CommandFactoryFactory::CommandFactoryFactory() {
	// crea una instancia de cada objeto y
	//  lo guarda en un map con el nombre de la clase
	//  como clave
	ReferenceCountPtr<Command> attack(new Attack());

	objectmap->put("Attack", attack);
}	


ReferenceCountPtr<CommandFactory> CommandFactoryFactory::build(const std::String& type, const std::String& xml) { 
	dom=libxml(xml);
	message = objectmap->get(type); 
	message->load(dom, map); 
	return message;
}


