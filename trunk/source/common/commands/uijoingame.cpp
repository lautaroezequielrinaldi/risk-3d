#include "uijoingame.h"


UIJoinGame::UIJoinGame(std::vector<std::string> &parameterList) : UICommand (){

	//this->numeroJugador = atoi (parameterList[0].c_str() );
}


UIJoinGame::UIJoinGame(){

}

UIJoinGame::~UIJoinGame(){
}

std::string UIJoinGame::serialize(){
	return "<?xml version=\"1.0\"?><uijoingame>"+serializeCommon(0,0)+"</uijoingame>";

}

bool UIJoinGame::validate(ReferenceCountPtr<GameManager>& gameManager){

		return false;
	
}

void UIJoinGame::execute(ReferenceCountPtr<State>& state){
    state->uiJoinGame(*this);


	
}

std::string UIJoinGame::getName() {
	return "uiJoinGame";
}


