#include "chat.h"

Chat::Chat(std::vector<std::string> &parameterList) : Command ()
{

	this->numeroJugador = atoi (parameterList[0].c_str() );
}

Chat::Chat(){

}
Chat::~Chat(){

}

std::string Chat::serialize(){
	return "<?xml version=\"1.0\"?><chat>"+Command::serialize(numeroJugador,0)+"</chat>";
}
bool Chat::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}
void* Chat::hydrate(std::string xml){

	return NULL;
}

void Chat::execute(ReferenceCountPtr<State>& state){
	
	state->chat(*this);
	
}

std::string Chat::getName() {
	return "chat";
}
