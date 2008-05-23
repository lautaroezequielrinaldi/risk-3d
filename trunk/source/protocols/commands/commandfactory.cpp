#include "attack.h"
#include "chatcommand.h"
#include "defend.h"
#include "init.h"
#include "join.h"
#include "keepalive.h"
#include "lose.h"
#include "mapreceive.h"
#include "mapsend.h"
#include "commandfactory.h"
#include "command.h"
#include "populate.h"
#include "surrender.h"
#include "turntoattack.h"
#include "turntodefend.h"
#include "turntopopulate.h"
#include "win.h"

#include <string>

/*
 * 
 *
 *
 *
 */


class CommandFactory {
	CommandFactory::CommandFactory() {
		// crea una instancia de cada objeto y
		//  lo guarda en un map con el nombre de la clase
		//  como clave
		ReferenceCountPtr<Command> attack(new Attack())
		objectmap->put("Attack", attack);
	}	


	ReferenceCountPtr<Command> CommandFactory::build(const std::String& type, const std::String& xml) { 
		dom=libxml(xml);
		message = objectmap->get(type); 
		message->load(dom, map); 
		return message;
	}
};

