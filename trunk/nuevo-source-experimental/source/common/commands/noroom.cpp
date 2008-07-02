#include "noroom.h"
#include "commandobserver.h"

NoRoom::NoRoom(){

}
NoRoom::NoRoom(const std::string& xml) {
    hydrate(xml);
}

NoRoom::~NoRoom(){

}

std::string NoRoom::serialize(){
	return "<?xml version=\"1.0\"?><NoRoom>"+serializeCommon(0,0)+"</NoRoom>";
}


std::string NoRoom::getName() {
	return "NoRoom";
}

void NoRoom::accept(CommandObserver* observer) {
    observer->commandExecuted(*this);
}

