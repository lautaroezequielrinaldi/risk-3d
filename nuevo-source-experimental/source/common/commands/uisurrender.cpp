#include "uisurrender.h"

UISurrender::UISurrender(std::vector<std::string> & parameterList):UICommand ()
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/

	//this->numeroJugador = atoi (parameterList[0].c_str() );
}

UISurrender::UISurrender(){

}

UISurrender::~UISurrender(){

}

std::string UISurrender::serialize(){
	return "<?xml version=\"1.0\"?><UISurrender>"+serializeCommon(0,0)+"</UISurrender>";
	
}
bool UISurrender::validate(ReferenceCountPtr<GameManager>& gameManager){
	return false;
}


void UISurrender::execute(ReferenceCountPtr<State>& state){
	
	state->uiSurrender(*this);
	
}
std::string UISurrender::getName() {
	return "uiSurrender";
}
