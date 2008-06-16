#include "movefactory.h"

MoveFactory::MoveFactory(): CommandFactory(){
}

MoveFactory::~MoveFactory(){
}
	
ReferenceCountPtr<Command> MoveFactory::createCommand(std::vector<std::string> &parameterList){

	ReferenceCountPtr<Command> movimiento(new Move(parameterList));
	return movimiento;
}
		
ReferenceCountPtr<Command> MoveFactory::createCommand(std::string & xml ){

	ReferenceCountPtr<Command> movimiento(new Move(xml));
	return movimiento;
}

