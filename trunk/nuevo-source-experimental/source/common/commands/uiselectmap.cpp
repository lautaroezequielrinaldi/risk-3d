#include "uiselectmap.h"


UISelectMap::UISelectMap(std::vector<std::string> &parameterList) : UICommand (){
	//this->numeroJugador = atoi (parameterList[0].c_str() );
	this->mapName = parameterList[1];
}


UISelectMap::UISelectMap() {

}

UISelectMap::~UISelectMap(){
}

std::string UISelectMap::serialize(){
	return "<?xml version=\"1.0\"?><UISelectMap>"+serializeCommon(0,0)+"<map>"+mapName+"</map></UISelectMap>";
  
}

bool UISelectMap::validate(ReferenceCountPtr<GameManager>& gameManager){
    // evaluar que el mapa exista	
		return false;
	
}

void UISelectMap::execute(ReferenceCountPtr<State>& state){
    state->uiSelectMap(*this);

	
}
std::string UISelectMap::getName() {
	return "uiSelectMap";
}

std::string UISelectMap::getMapName(){
	return mapName;
}

void UISelectMap::setMapName(const std::string & mapname){
	this->mapName = mapName;
}





