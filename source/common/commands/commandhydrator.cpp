#include "commandhydrator.h"

CommandHydrator::CommandHydrator(){
	commands.insert(std::make_pair("attack",new Attack()));
	commands.insert(std::make_pair("defend",new Defend()));
	commands.insert(std::make_pair("joingame",new JoinGame()));
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
 * @todo Pablo o Analia:
 * que no sea local
 * que sea copia
 */
ReferenceCountPtr<Command> & CommandHydrator::getCommand(std::string name, std::string xml){
	ReferenceCountPtr<Command> command = commands[name]; // aca quiero una copia
	command->hydrate(xml);
	return command;
}
