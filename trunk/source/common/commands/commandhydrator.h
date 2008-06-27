#ifndef __COMMANDHYDRATOR_H__
#define __COMMANDHYDRATOR_H__

#include "attack.h"
#include "chat.h"
#include "defend.h"
#include "joingame.h"
#include "kill.h"
#include "lose.h"
#include "map.h"
#include "move.h"
#include "nomore.h"
#include "populate.h"
#include "quit.h"
#include "readytoplay.h"
#include "selectmap.h"
#include "setowner.h"
#include "surrender.h"
#include "turntoattack.h"
#include "turntomove.h"
#include "turntooccupy.h"
#include "win.h"
#include "youare.h"


#include <map>
#include <string>


class CommandHydrator {
	
	public:
		
		/**
		 * Constructor de la clase
		 */
		CommandHydrator();
		
		/**
		 * Destructor de la clase
		 */
		virtual ~CommandHydrator();
		
		/**
		 * Metodo cuyo proposito es obtener un comando a partir del nombre proporcionado,
		 * hidratado a partir del xml proporcionado.
		 */
		Command * getCommand(std::string name, std::string xml);
	
	
	private:
	
		std::map <std::string, Command * > commands;

};
#endif /*__COMMANDHYDRATOR_H__*/
