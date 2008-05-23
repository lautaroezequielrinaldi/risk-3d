#include "Attack.h"
#include "ChatMessage.h"
#include "Defend.h"
#include "Init.h"
#include "Join.h"
#include "KeepAlive.h"
#include "Lose.h"
#include "MapReceive.h"
#include "MapSend.h"
#include "MessageFactory.h"
#include "Message.h"
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


class MessageFactory {
	MessageFactory::MessageFactory() {
		// crea una instancia de cada objeto y
		//  lo guarda en un map con el nombre de la clase
		//  como clave
		ReferenceCountPtr<Message> attack(new Attack())
		objectmap->put("Attack", attack);
	}	


	ReferenceCountPtr<Message> MessageFactory::build(const std::String& type, const std::String& xml) { 
		dom=libxml(xml);
		message = objectmap->get(type); 
		message->load(dom, map); 
		return message;
	}
};

