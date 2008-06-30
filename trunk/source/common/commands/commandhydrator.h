#ifndef __COMMANDHYDRATOR_H__
#define __COMMANDHYDRATOR_H__

#include "attack.h"
#include "chat.h"
#include "defend.h"
#include "didiwin.h"
#include "joingame.h"
#include "lose.h"
#include "map.h"
#include "maplist.h"
#include "move.h"
#include "nomore.h"
#include "noroom.h"
#include "populate.h"
#include "quit.h"
#include "readytoplay.h"
#include "selectmap.h"
#include "surrender.h"
#include "turntoattack.h"
#include "turntomove.h"
#include "turntooccupy.h"
#include "win.h"
#include "youare.h"
/*
#include "uireadytoplay.h"
#include "uiquit.h"
#include "uisurrender.h"
#include "uinomore.h"
#include "uididiwin.h"
#include "uijoingame.h"
*/
/*
#include "uicountryselect.h"
#include "uiquantityselect.h"
*/


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
