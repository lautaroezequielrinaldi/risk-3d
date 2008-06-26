#include "commandhydrator.h"
#include<iostream>
CommandHydrator::CommandHydrator(){
	commands.insert(std::make_pair("attack",new Attack()));
	commands.insert(std::make_pair("defend",new Defend()));
	commands.insert(std::make_pair("joinGame",new JoinGame()));
	commands.insert(std::make_pair("move",new Move()));
	commands.insert(std::make_pair("selectmap",new SelectMap()));
	commands.insert(std::make_pair("populate",new Populate()));
	commands.insert(std::make_pair("readytoplay",new ReadyToPlay()));
	commands.insert(std::make_pair("nomore",new NoMore()));
	commands.insert(std::make_pair("surrender",new Surrender()));
	commands.insert(std::make_pair("quit",new Quit()));

}

CommandHydrator::~CommandHydrator(){

}

/**
 * Es
 */
Command * CommandHydrator::getCommand(std::string name, std::string xml){
	Command * command = commands[name];
	std::cout << "El nombre del comando es: " << name << std::endl;
	command->hydrate(xml);
	return command;
}
