#ifndef __COMMANDHYDRATOR_H__
#define __COMMANDHYDRATOR_H__

#include "attack.h"
#include "defend.h"
#include "joingame.h"
#include "move.h"
#include "selectmap.h"
#include "populate.h"
#include "readytoplay.h"
#include "nomore.h"
#include "surrender.h"
#include "quit.h"


#include <map>
#include <string>


class CommandHydrator {
	public:
		CommandHydrator();
		virtual ~CommandHydrator();
		Command * getCommand(std::string name, std::string xml);
	private:
		std::map <std::string, Command * > commands;

};
#endif /*__COMMANDHYDRATOR_H__*/
