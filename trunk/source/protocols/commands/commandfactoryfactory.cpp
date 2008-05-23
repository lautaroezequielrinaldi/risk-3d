#include "commandfactoryfactory.h"


/*
 * esto es muy borrador
 *
 *
 *
 */


CommandFactoryFactory::CommandFactoryFactory() {
	// crea una instancia de cada objeto y
	//  lo guarda en un map con el nombre de la clase
	//  como clave
	ReferenceCountPtr<CommandFactory> attackfactory();
	objectmap->put("Attack", attackfactory);


}	
/*
 * Esto es muy borrador
 *
 */

ReferenceCountPtr<CommandFactory> CommandFactoryFactory::build(const std::String& type, const std::String& xml) {
	dom=libxml(xml);
	commandfactory = objectmap->get(type); 
	commandfactory->getCommand(type,dom);
	return commandfactory;
}


