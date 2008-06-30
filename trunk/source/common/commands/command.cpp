#include "command.h"
#include <sstream>

Command::Command():Serializable() {
	valid = 0;
}

Command::~Command()
{
}

int Command::isValid() {
	return valid;
}
void Command::setValid(int valid){
	this->valid = valid;
}


int Command::getFrom(){
	return from;
}

int Command::getTo(){
	return to;
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

void* Command::hydrate(std::string xml){
	xmlDocPtr document =hydrateCommon(xml);
	xmlFreeDoc(document);
	xmlCleanupParser();
	return NULL;
}

xmlDocPtr Command::hydrateCommon(std::string xml){
	xmlChar* field;
	xmlXPathObjectPtr objetoXPath;
	xmlNodeSetPtr setNodo;
	xmlNodePtr nodo;

	xmlDocPtr document = xmlParseMemory(xml.c_str(), xml.size());

	xmlXPathContextPtr contextoXPath = xmlXPathNewContext(document);

	objetoXPath = xmlXPathEvalExpression(BAD_CAST "//*/from", contextoXPath);
	setNodo = objetoXPath->nodesetval;
	nodo = setNodo->nodeTab[0];
	field = xmlNodeGetContent(nodo);
	this->from = atoi((char*)field);	
	xmlXPathFreeObject(objetoXPath);
	
	objetoXPath = xmlXPathEvalExpression(BAD_CAST "//*/to", contextoXPath);
	setNodo = objetoXPath->nodesetval;
	nodo = setNodo->nodeTab[0];
	field = xmlNodeGetContent(nodo);
	this->to = atoi((char*)field);
	xmlXPathFreeObject(objetoXPath);

	objetoXPath = xmlXPathEvalExpression(BAD_CAST "//*/valid", contextoXPath);
	setNodo = objetoXPath->nodesetval;
	nodo = setNodo->nodeTab[0];
	field = xmlNodeGetContent(nodo);
	this->valid = atoi((char*)field);
	xmlXPathFreeObject(objetoXPath);
	
	objetoXPath = xmlXPathEvalExpression(BAD_CAST "//*/mainmsg", contextoXPath);
	setNodo = objetoXPath->nodesetval;
	nodo = setNodo->nodeTab[0];
	field = xmlNodeGetContent(nodo);
	this->mainmsg.assign( (char*) field );
	xmlXPathFreeObject(objetoXPath);	


	objetoXPath = xmlXPathEvalExpression(BAD_CAST "//*/secmsg", contextoXPath);
	setNodo = objetoXPath->nodesetval;
	nodo = setNodo->nodeTab[0];
	field = xmlNodeGetContent(nodo);
	this->mainmsg.assign( (char*) field );
	xmlXPathFreeObject(objetoXPath);
	

	xmlFree(field);
	xmlXPathFreeObject(objetoXPath);
	xmlXPathFreeContext(contextoXPath);
	return document;
}
