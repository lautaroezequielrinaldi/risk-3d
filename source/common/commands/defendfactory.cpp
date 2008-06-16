#include "defendfactory.h"

DefendFactory::DefendFactory(): CommandFactory(){
}

DefendFactory::~DefendFactory(){
}

ReferenceCountPtr<Command> DefendFactory::createCommand(std::vector<std::string> &parameterList){

	ReferenceCountPtr<Command> defensa(new Defend(parameterList));
	return defensa;

}
		
ReferenceCountPtr<Command> DefendFactory::createCommand(std::string & xml ){

	ReferenceCountPtr<Command> defensa(new Defend(xml));
	return defensa;
}

