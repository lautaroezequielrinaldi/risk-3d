#include "Attack.h"
#include "ChatCommand.h"
#include "Defend.h"
#include "Init.h"
#include "Join.h"
#include "KeepAlive.h"
#include "Lose.h"
#include "MapReceive.h"
#include "MapSend.h"
#include "CommandFactory.h"
#include "Command.h"
#include "Populate.h"
#include "Surrender.h"
#include "TurnToAttack.h"
#include "TurnToDefend.h"
#include "TurnToPopulate.h"
#include "Win.h"

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

