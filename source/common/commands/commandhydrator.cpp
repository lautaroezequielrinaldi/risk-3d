#include "commandhydrator.h"
#include<iostream>
CommandHydrator::CommandHydrator(){
	commands.insert(std::make_pair("attack",new Attack()));
	//commands.insert(std::make_pair("chat",new Chat()));
	commands.insert(std::make_pair("defend",new Defend()));
	commands.insert(std::make_pair("joingame",new JoinGame()));
	commands.insert(std::make_pair("kill",new Kill()));
	commands.insert(std::make_pair("lose",new Lose()));
	commands.insert(std::make_pair("map",new Map()));
	commands.insert(std::make_pair("move",new Move()));
	commands.insert(std::make_pair("nomore",new NoMore()));
	commands.insert(std::make_pair("populate",new Populate()));
	commands.insert(std::make_pair("quit",new Quit()));
	commands.insert(std::make_pair("readytoplay",new ReadyToPlay()));
	commands.insert(std::make_pair("selectmap",new SelectMap()));
	commands.insert(std::make_pair("setowner",new SetOwner()));
	commands.insert(std::make_pair("surrender",new Surrender()));
	commands.insert(std::make_pair("turntoattack",new TurnToAttack()));
	commands.insert(std::make_pair("turntomove",new TurnToMove()));
	commands.insert(std::make_pair("turntooccupy",new TurnToOccupy()));
	commands.insert(std::make_pair("win",new Win()));
	commands.insert(std::make_pair("youare",new YouAre()));


}

CommandHydrator::~CommandHydrator(){

}

/**
 *
 */
Command * CommandHydrator::getCommand(std::string name, std::string xml){
	std::cout << "CommandHydrator::getCommand(" << name << ")" << std::endl;
	Command * command = commands[name];
	
	command->hydrate(xml); // aca muere
	return command;
}
