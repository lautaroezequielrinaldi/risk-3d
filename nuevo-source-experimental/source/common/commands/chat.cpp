#include "chat.h"
#include "commandobserver.h"

Chat::Chat(std::vector<std::string> &parameterList) : Command ()
{

	//this->numeroJugador = atoi (parameterList[0].c_str() );
}

Chat::Chat(){

}
Chat::Chat(const std::string& xml): Command() {
    hydrate(xml);
}

Chat::~Chat(){

}

std::string Chat::serialize(){
	return "<?xml version=\"1.0\"?><chat>"+serializeCommon(getFrom(),0)+"</chat>";
}


std::string Chat::getName() {
	return "chat";
}

void Chat::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}
