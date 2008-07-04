#include "uiquantityselect.h"
#include "commandobserver.h"

UIQuantitySelect::UIQuantitySelect(std::vector<std::string> &parameterList) : UICommand ()
{

	
}

UIQuantitySelect::UIQuantitySelect(){

}
UIQuantitySelect::~UIQuantitySelect(){

}

std::string UIQuantitySelect::serialize(){
	return "<?xml version=\"1.0\"?><uiquantityselect>"+serializeCommon(0,0)+"</uiquantityselect>";
}

std::string UIQuantitySelect::getName() {
	return "uiQuantitySelect";
}

