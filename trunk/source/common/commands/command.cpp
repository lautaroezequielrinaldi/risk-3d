#include "command.h"
Command::Command():Serializable()
{
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


bool Command::isForMe(int me){
	return false;
}

bool Command::isFromMe(int me){
	return false;
}

void Command::setMainMsg(std::string msg){
	mainMsg = msg;
}

void Command::setSecMsg(std::string msg){
	secMsg = msg;
}

std::string Command::getMainMsg(){
	return mainMsg;
}

std::string Command::getSecMsg(){
	return secMsg;
}

std::string Command::getName(){
	return name;
}
