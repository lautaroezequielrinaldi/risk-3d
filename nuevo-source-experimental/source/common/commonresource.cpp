#include "commonresource.h"

CommonResource::CommonResource()
{
}

CommonResource::~CommonResource()
{
}

bool CommonResource::getUIupdate(){
	return this->updateUI;
}		
	
void CommonResource::setUIupdate(bool update){
	this->updateUI = update;	
}
		
Command* CommonResource::getCommandWrite(){
	return this->cmdWrite;
}		

Command* CommonResource::getCommandRead(){
	return this->cmdRead;		
}
		
void CommonResource::setCommandWrite( Command *cmd){
	this->cmdWrite = cmd;
}
	
void CommonResource::setCommandRead( Command *cmd){
	this->cmdRead = cmd ;	
	
}
		
		/*
Condition_Variable& CommonResource::getSendConditionVariable(){
	return this->condSend;
	
}
		
Condition_Variable& CommonResource::getReceiveConditionVariable(){
	return this->condRec;
	
}*/

