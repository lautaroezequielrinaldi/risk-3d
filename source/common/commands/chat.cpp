#include "chat.h"

Chat::Chat(){

}
Chat::~Chat(){

}

std::string Chat::serialize(){
	return "<?xml version=\"1.0\"?>";
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
