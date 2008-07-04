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

std::string UIQuit::getName() {
	return "uiQuit";
}
