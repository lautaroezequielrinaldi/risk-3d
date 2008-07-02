#include "uinomore.h"

UINoMore::UINoMore(std::vector<std::string> &parameterList) : UICommand ()
{

	//this->numeroJugador = atoi (parameterList[0].c_str() );
}


UINoMore::UINoMore(){

}

UINoMore::~UINoMore(){

}

std::string UINoMore::serialize(){
	return "<?xml version=\"1.0\"?><uinomore>"+serializeCommon(0,0)+"</uinomore>";
}
bool UINoMore::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}



void UINoMore::execute(ReferenceCountPtr<State>& state){
	
	state->uiNoMore(*this);
	
}
std::string UINoMore::getName() {
	return "uiNoMore";
}
