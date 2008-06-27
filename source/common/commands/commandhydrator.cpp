#include "commandhydrator.h"
#include<iostream>
CommandHydrator::CommandHydrator(){
	commands.insert(std::make_pair("attack",new Attack()));
	//commands.insert(std::make_pair("chat",new Chat()));
	commands.insert(std::make_pair("defend",new Defend()));
	commands.insert(std::make_pair("joinGame",new JoinGame()));
	commands.insert(std::make_pair("kill",new Kill()));
	commands.insert(std::make_pair("lose",new Lose()));
	commands.insert(std::make_pair("map",new Map()));
	commands.insert(std::make_pair("move",new Move()));
	commands.insert(std::make_pair("noMore",new NoMore()));
	commands.insert(std::make_pair("populate",new Populate()));
	commands.insert(std::make_pair("quit",new Quit()));
	commands.insert(std::make_pair("readytoplay",new ReadyToPlay()));
	commands.insert(std::make_pair("selectMap",new SelectMap()));
	commands.insert(std::make_pair("setOwner",new SetOwner()));
	commands.insert(std::make_pair("surrender",new Surrender()));
	commands.insert(std::make_pair("turnToAttack",new TurnToAttack()));
	commands.insert(std::make_pair("turnTomMve",new TurnToMove()));
	commands.insert(std::make_pair("turnToOccupy",new TurnToOccupy()));
	commands.insert(std::make_pair("win",new Win()));
	commands.insert(std::make_pair("youAre",new YouAre()));


}

CommandHydrator::~CommandHydrator(){

}

/**
 *
 */
Command * CommandHydrator::getCommand(std::string name, std::string xml){
	std::cout << "CommandHydrator::getCommand(" << name << ")" << std::endl;
	Command * command = commands[name];
	std::cout << "El comando es de tipo: " << name << std::endl;	
	command->hydrate(xml); // aca muere
	return command;
}
