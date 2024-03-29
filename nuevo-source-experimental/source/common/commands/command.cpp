#include "command.h"
#include <sstream>

Command::Command():Serializable() {
	valid = 0;
	from = 0;
	to = 0;
}

Command::~Command()
{
}

int Command::isValid() {
	return valid;
}

int Command::getFrom(){
	return from;
}

std::string Command::getStringFrom() {
	std::ostringstream out;
	out << from;
	return out.str();

}

int Command::getTo(){
	return to;
}

std::string Command::getName(){
	return name;
}

std::string Command::getMainMsg() {
	return mainmsg;
}

std::string Command::getSecMsg() {
	return secmsg;
}

void Command::setValid(int valid){
	this->valid = valid;
}

void Command::setFrom(int from){
	this->from = from;
}
		
void Command::setTo(int to){
	this->to = to;	
}

void Command::setMainMsg( std::string  msg) {
	mainmsg=msg;
}

void Command::setSecMsg( std::string  msg) {
	secmsg=msg;
}


std::string Command::serializeCommon(int from, int to){
	std::ostringstream strFrom;
	std::ostringstream strTo;
	std::ostringstream strValid;

   	strFrom << from;
	strTo << to;
	strValid << isValid();
   	return "<from>"+strFrom.str()+"</from><to>"+strTo.str()+"</to><valid>"+ strValid.str()+"</valid><mainmsg>"+mainmsg+"</mainmsg><secmsg>"+secmsg+"</secmsg>";


	
}

void* Command::hydrate(const std::string &xml){
	xmlDocPtr document =hydrateCommon(xml);
	xmlFreeDoc(document);
	xmlCleanupParser();
	return NULL;
}

xmlDocPtr Command::hydrateCommon(const std::string& xml){
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
	xmlFree(field);	
	xmlXPathFreeObject(objetoXPath);
	
	objetoXPath = xmlXPathEvalExpression(BAD_CAST "//*/to", contextoXPath);
	setNodo = objetoXPath->nodesetval;
	nodo = setNodo->nodeTab[0];
	field = xmlNodeGetContent(nodo);
	this->to = atoi((char*)field);
	xmlFree(field);
	xmlXPathFreeObject(objetoXPath);

	objetoXPath = xmlXPathEvalExpression(BAD_CAST "//*/valid", contextoXPath);
	setNodo = objetoXPath->nodesetval;
	nodo = setNodo->nodeTab[0];
	field = xmlNodeGetContent(nodo);
	this->valid = atoi((char*)field);
	xmlFree(field);
	xmlXPathFreeObject(objetoXPath);
	
	objetoXPath = xmlXPathEvalExpression(BAD_CAST "//*/mainmsg", contextoXPath);
	setNodo = objetoXPath->nodesetval;
	nodo = setNodo->nodeTab[0];
	field = xmlNodeGetContent(nodo);
	this->mainmsg.assign( (char*) field );
	xmlFree(field);
	xmlXPathFreeObject(objetoXPath);	


	objetoXPath = xmlXPathEvalExpression(BAD_CAST "//*/secmsg", contextoXPath);
	setNodo = objetoXPath->nodesetval;
	nodo = setNodo->nodeTab[0];
	field = xmlNodeGetContent(nodo);
	this->secmsg.assign( (char*) field );
	xmlFree(field);
	xmlXPathFreeObject(objetoXPath);
	

	xmlXPathFreeContext(contextoXPath);
	return document;
}
