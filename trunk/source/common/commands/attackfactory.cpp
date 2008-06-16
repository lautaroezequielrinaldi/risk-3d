#include "attackfactory.h"


AttackFactory::AttackFactory(){
}

AttackFactory::~AttackFactory(){
}
	
ReferenceCountPtr<Command> AttackFactory::createCommand(std::vector<std::string> &parameterList){

	ReferenceCountPtr<Command> ataque(new Attack(parameterList));
	return ataque;
}
		
ReferenceCountPtr<Command> AttackFactory::createCommand(std::string & xml ){
	
	ReferenceCountPtr<Command> ataque(new Attack(xml));
	return ataque;
}

