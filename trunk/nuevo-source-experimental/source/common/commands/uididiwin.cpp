#include "uididiwin.h"


UIDidIWin::UIDidIWin(std::vector<std::string> &parameterList) : UICommand ()
{

//	this->numeroJugador = atoi (parameterList[0].c_str() );
}

UIDidIWin::UIDidIWin(){

}
UIDidIWin::~UIDidIWin(){

}

std::string UIDidIWin::serialize(){
	return "<?xml version=\"1.0\"?><uididiwin>"+serializeCommon(0,0)+"</uididiwin>";
}

std::string UIDidIWin::getName() {
	return "UIDidIWin";
}
