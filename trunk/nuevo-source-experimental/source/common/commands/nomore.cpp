#include "nomore.h"
#include "commandobserver.h"

NoMore::NoMore(std::vector<std::string> &parameterList) : Command ()
{

	this->numeroJugador = atoi (parameterList[0].c_str() );
}


NoMore::NoMore(){

}
NoMore::NoMore(const std::string& xml) {
    hydrate(xml);
}

NoMore::~NoMore(){

}

std::string NoMore::serialize(){
	return "<?xml version=\"1.0\"?><nomore>"+serializeCommon(getFrom(),getTo())+"</nomore>";
}

std::string NoMore::getName() {
	return "noMore";
}

void NoMore::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}

