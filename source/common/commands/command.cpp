#include "command.h"
#include <sstream>

Command::Command():Serializable() {
	
}

Command::~Command()
{
}

bool Command::isValid() {
	return valid;
}
void Command::setValid(bool valid){
	this->valid = valid;
}


int Command::from(){
	return false;
}

int Command::to(){
	return false;
}


std::string Command::getName(){
	return name;
}

void Command::setMainMsg(std::string msg) {
	mainmsg=msg;
}

void Command::setSecMsg(std::string msg) {
	secmsg=msg;
}

std::string Command::getMainMsg() {
	return mainmsg;
}

std::string Command::getSecMsg() {
	return secmsg;
}


std::string Command::serialize(int from, int to){
	std::ostringstream strFrom;
	std::ostringstream strTo;
	std::ostringstream strValid;

   	strFrom << from;
	strTo << to;
	strValid << isValid();
   	return "<from>"+strFrom.str()+"</from><to>"+strTo.str()+"</to><valid>"+ strValid.str()+"</valid><mainmsg>"+mainmsg+"</mainmsg><secmsg>"+secmsg+"</secmsg>";


	
}
