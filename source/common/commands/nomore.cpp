#include "nomore.h"
#include "commandobserver.h"

NoMore::NoMore(std::vector<std::string> &parameterList) : Command ()
{

	this->numeroJugador = atoi (parameterList[0].c_str() );
}


NoMore::NoMore(){

}

NoMore::~NoMore(){

}

std::string NoMore::serialize(){
	return "<?xml version=\"1.0\"?><nomore>"+serializeCommon(getFrom(),getTo())+"</nomore>";
}
bool NoMore::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}



void NoMore::execute(ReferenceCountPtr<State>& state){
	
	state->noMore(*this);
	
}
std::string NoMore::getName() {
	return "noMore";
}

void NoMore::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}

