#include "commandhydrator.h"
#include<iostream>

CommandHydrator::CommandHydrator(){
	commands.insert(std::make_pair("attack",new ServerAttack()));
	commands.insert(std::make_pair("chat",new ServerChat()));
	commands.insert(std::make_pair("defend",new ServerDefend()));
	commands.insert(std::make_pair("battleResult",new ServerBattleResult()));
	commands.insert(std::make_pair("didIWin",new ServerDidIWin()));
	commands.insert(std::make_pair("joinGame",new ServerJoinGame()));
	
	commands.insert(std::make_pair("lose",new ServerLose()));
	commands.insert(std::make_pair("map",new ServerMap()));
	commands.insert(std::make_pair("mapList",new ServerMapList()));
	commands.insert(std::make_pair("move",new ServerMove()));
	commands.insert(std::make_pair("noMore",new ServerNoMore()));
	commands.insert(std::make_pair("noRoom",new ServerNoRoom()));
	commands.insert(std::make_pair("populate",new ServerPopulate()));
	commands.insert(std::make_pair("quit",new ServerQuit()));
	commands.insert(std::make_pair("readyToPlay",new ServerReadyToPlay()));
	commands.insert(std::make_pair("selectMap",new ServerSelectMap()));
	
	commands.insert(std::make_pair("surrender",new ServerSurrender()));
	commands.insert(std::make_pair("turnToAttack",new ServerTurnToAttack()));
	commands.insert(std::make_pair("turnToMove",new ServerTurnToMove()));
	commands.insert(std::make_pair("turnToOccupy",new ServerTurnToOccupy()));
	commands.insert(std::make_pair("win",new ServerWin()));
	commands.insert(std::make_pair("youAre",new ServerYouAre()));


}

CommandHydrator::~CommandHydrator(){

}

/**
 *
 */
ServerCommand * CommandHydrator::getCommand(const std::string &name, const std::string &xml){
	
	std::cout << "CommandHydrator::getCommand(" << name << ")" << std::endl;
	//obtengo el comando a partir del nombre, del map.
	ServerCommand * sCommand = commands[name];
	
	std::cout << "El comando es de tipo: " << name << std::endl;	
	//hidrato a partir del xml el serverComand del map
	sCommand->hydrate(xml);
	
	return sCommand;
}
