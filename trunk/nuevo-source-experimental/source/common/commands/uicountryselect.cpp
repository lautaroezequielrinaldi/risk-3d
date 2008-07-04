#include "uicountryselect.h"
#include "commandobserver.h"

UICountrySelect::UICountrySelect(std::vector<std::string> &parameterList) : UICommand ()
{

	
}

UICountrySelect::UICountrySelect(){

}
UICountrySelect::~UICountrySelect(){

}

std::string UICountrySelect::serialize(){
	return "<?xml version=\"1.0\"?><uicountryselect>"+serializeCommon(0,0)+"</uicountryselect>";
}

std::string UICountrySelect::getName() {
	return "uiCountrySelect";
}

