#include "uichat.h"
#include "commandobserver.h"

UIChat::UIChat(std::vector<std::string> &parameterList) : UICommand ()
{

	
}

UIChat::UIChat(){

}
UIChat::~UIChat(){

}

std::string UIChat::serialize(){
	return "<?xml version=\"1.0\"?><uichat>"+serializeCommon(0,0)+"</uichat>";
}
bool UIChat::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}

void UIChat::execute(ReferenceCountPtr<State>& state){
	
	state->uiChat(*this);
	
}

std::string UIChat::getName() {
	return "uiChat";
}

