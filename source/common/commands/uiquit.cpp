#include "uiquit.h"


UIQuit::UIQuit(std::vector<std::string> &parameterList) : UICommand ()
{

	//this->numeroJugador = atoi (parameterList[0].c_str() );
}

UIQuit::UIQuit(){

}
UIQuit::~UIQuit(){

}

std::string UIQuit::serialize(){
	return "";
}
bool UIQuit::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}


void UIQuit::execute(ReferenceCountPtr<State>& state){
	
	state->uiQuit(*this);
	
}
std::string UIQuit::getName() {
	return "uiQuit";
}
