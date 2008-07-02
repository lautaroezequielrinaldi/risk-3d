#include "surrender.h"
#include "commandobserver.h"

Surrender::Surrender(std::vector<std::string> & parameterList):Command ()
{
	//no realiza ninguna accion
}

Surrender::Surrender(){

}

Surrender::~Surrender(){

}

std::string Surrender::serialize(){
	return "<?xml version=\"1.0\"?><surrender>"+serializeCommon(getFrom(),getTo())+"</surrender>";
	
}

std::string Surrender::getName() {
	return "surrender";
}

void Surrender::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}
