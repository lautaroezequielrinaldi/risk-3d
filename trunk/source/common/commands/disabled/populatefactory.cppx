#include "populatefactory.h"

PopulateFactory::PopulateFactory(): CommandFactory(){
}

PopulateFactory::~PopulateFactory(){
}

	
ReferenceCountPtr<Command> PopulateFactory::createCommand(std::vector<std::string> &parameterList){

	ReferenceCountPtr<Command> populate(new Populate(parameterList));
	return populate;

}
		
ReferenceCountPtr<Command> PopulateFactory::createCommand(std::string & xml ){

	ReferenceCountPtr<Command> populate(new Populate(xml));
	return populate;
}



