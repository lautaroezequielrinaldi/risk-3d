#include "joingame.h"


JoinGame::JoinGame(std::vector<std::string> &parameterList) : Command ()
{
}

JoinGame::JoinGame(std::string xml):Command (){

	// construye el objeto a partir del Xml recibido
	hydrate(xml);
}

JoinGame::JoinGame(){

}

JoinGame::~JoinGame()
{
}

std::string JoinGame::serialize(){
	return "<?xml version=\"1.0\"?><joingame><from>0</from><to>0</to><name>$name</name></joingame>";

	std::string joinGameSerializado;
	
	xmlDocPtr docJoinGame;

	xmlNodePtr nodoNombre;
	
	xmlChar *xmlbuff;
	int buffersize;
	
	docJoinGame = xmlNewDoc(BAD_CAST "1.0");
	
	nodoNombre = xmlNewNode(NULL, BAD_CAST "nombre");
	
	xmlDocSetRootElement(docJoinGame, nodoNombre);
	
	xmlDocDumpFormatMemory(docJoinGame, &xmlbuff, &buffersize, 1);
	
	joinGameSerializado.assign((char*)xmlbuff);
	
	xmlFree(xmlbuff);
	xmlFreeDoc(docJoinGame);
	xmlCleanupParser();
	
	return joinGameSerializado;
}

void* JoinGame::hydrate(std::string xml){
	

    return 0;	
}

bool JoinGame::validate(ReferenceCountPtr<GameManager>& gameManager){
    // evaluar si hay lugar	
		return false;
	
}

void JoinGame::execute(ReferenceCountPtr<State>& state){
    state->joinGame(*this);

    // pasar al state correspondiente
    // suscribir jugador
    // si es el primer jugador cambiar estado a "esperandoSeleccionMapa"
    //    enviar comando "offerMaps" a este jugador
    //    return
    //
    // si no hay mas lugar hacer auto listos
    //     return
    // enviar message("aguardando jugadores")


	
}

std::string JoinGame::getName() {
	return "joinGame";
}


