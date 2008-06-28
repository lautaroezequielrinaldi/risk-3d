#include "didiwin.h"

DidIWin::DidIWin(){

}
DidIWin::~DidIWin(){

}

std::string DidIWin::serialize(){
	return "<?xml version=\"1.0\"?><didiwin><from>$player</player><to>0</to><msg>$message></msg></didiwin>";
}
bool DidIWin::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}
void* DidIWin::hydrate(std::string xml){

	return NULL;
}

void DidIWin::execute(ReferenceCountPtr<State>& state){
	
	state->didIWin(*this);
	
}

std::string DidIWin::getName() {
	return "DidIWin";
}
