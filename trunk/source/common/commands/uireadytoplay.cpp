#include "uireadytoplay.h"

UIReadyToPlay::UIReadyToPlay(std::vector<std::string> &parameterList) : UICommand()
{

	//this->numeroJugador = atoi (parameterList[0].c_str() );
}


UIReadyToPlay::UIReadyToPlay(){

}

UIReadyToPlay::~UIReadyToPlay()
{
}

std::string UIReadyToPlay::serialize(){
	return "<?xml version=\"1.0\"?><uireadytoplay>"+serializeCommon(0,0)+"</uireadytoplay>";
}


bool UIReadyToPlay::validate(ReferenceCountPtr<GameManager>& gameManager){
    return false;
	
}

void UIReadyToPlay::execute(ReferenceCountPtr<State>& state){
    state->uiReadyToPlay(*this);
	
}

std::string UIReadyToPlay::getName() {
	return "uiReadyToPlay";
}


