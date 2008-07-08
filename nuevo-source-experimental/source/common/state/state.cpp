#include "state.h"
#include "../Servercommands/serverattack.h"
#include "../Servercommands/serverchat.h"
#include "../Servercommands/serverdefend.h"
#include "../Servercommands/serverJoingame.h"
#include "../Servercommands/servermove.h"
#include "../Servercommands/serverselectmap.h"
#include "../Servercommands/serverpopulate.h"
#include "../Servercommands/serverreadytoplay.h"
#include "../Servercommands/servernomore.h"
#include "../Servercommands/servernoroom.h"
#include "../Servercommands/serversurrender.h"
#include "../Servercommands/serverquit.h"
#include "../Servercommands/serverwin.h"
#include "../Servercommands/serverlose.h"
#include "../Servercommands/serveryouare.h"
#include "../Servercommands/servermap.h"
#include "../Servercommands/serverturntoattack.h"
#include "../Servercommands/serverturntomove.h"
#include "../Servercommands/serverturntooccupy.h"
#include "../Servercommands/serverturntopopulate.h"
#include "../Servercommands/serverdidiwin.h"
#include "../Servercommands/servermaplist.h"

#include "../commands/uireadytoplay.h"
#include "../commands/uididiwin.h"
#include "../commands/uiquit.h"
#include "../commands/uisurrender.h"
#include "../commands/uinomore.h"
#include "../commands/uijoingame.h"
#include "../commands/uiselectmap.h"

#include "../commands/uicountryselect.h"
#include "../commands/uiquantityselect.h"


#include "stateobserver.h"

#include "../model/gamemanager.h"
#include "../model/randomdice.h"
#include "../smartpointer/referencecountptr.h"

#include<iostream>
#include<sstream>

using namespace std;

/*State::State() {
    // No realiza ninguna acciòn.
}
*/
State::State(ReferenceCountPtr<GameManager>&gameManager, std::string name):gameManager(gameManager),name(name){

}

State::~State() {
    // No realiza ninguna acciòn,
}

std::string State::getName(){
	return name;

}


bool State::attack(ServerAttack & command){
	command.setMainMsg("Intento de ataque en momento inoportuno");
	command.setSecMsg("El jugador " + command.getStringFrom() + " intentó atacar cuando no le tocaba");
	//gameManager->notify(&command);
	return false;
}

bool State::defend(ServerDefend & command){
	command.setMainMsg("Intento de defensa en momento inoportuno");
	command.setSecMsg("El jugador " + command.getStringFrom() + " intentó defenderse cuando no le tocaba");
	//gameManager->notify(&command);

	return false;
}

bool State::joinGame(ServerJoinGame & command){
	command.setMainMsg("...");
	command.setSecMsg("Un jugador intentó conectarse con el partido iniciado");
	
	return false;
}

bool State::move(ServerMove & command){
	command.setMainMsg("Intento de movimiento en momento inoportuno");
	command.setSecMsg("El jugador " + command.getStringFrom() + " intentó moverse cuando no le tocaba");
	cout<<"	no es momento de mover"<<endl;

	//gameManager->notify(&command);

	return false;
}
bool State::selectMap(ServerSelectMap & command){
	if (! command.isValid()) {
		command.setMainMsg("Intento de selección de mapa en momento inoportuno");
		command.setSecMsg("El jugador " + command.getStringFrom() + " intentó seleccionar mapa cuando no le tocaba");
		gameManager->notify(&command);
	}
        return false;
}

//lo implementan:  Occuppying y Populating
bool State::populate(ServerPopulate & command){
	command.setMainMsg("Intento de poblar en momento inoportuno");
	command.setSecMsg("El jugador " + command.getStringFrom() + " intentó poblar cuando no le tocaba");
	//gameManager->notify(&command);
	return false;
}

bool State::readyToPlay(ServerReadyToPlay & command){
	if (! command.isValid()) {
		command.setMainMsg("Intento de aceptar el juego en momento inoportuno");
		command.setSecMsg("El jugador " + command.getStringFrom() + " intentó aceptar el juego cuando no le tocaba");
		gameManager->notify(&command);
	}
	return false;
}

bool State::didIWin(ServerDidIWin & command){
	if (! command.isValid()) {
		command.setMainMsg("Intento de ganar en momento inoportuno");
		command.setSecMsg("El jugador " + command.getStringFrom() + " intentó ganar cuando no le tocaba");
		gameManager->notify(&command);
	}
	return false;
}

bool State::noMore(ServerNoMore & command){
	if (! command.isValid()) {
		command.setMainMsg("Intento de terminar etapa en momento inoportuno");
		command.setSecMsg("El jugador " + command.getStringFrom() + " intentó terminar etapa cuando no le tocaba");
		gameManager->notify(&command);
	}
	return false;
}

bool State::surrender(ServerSurrender & command){
	
	std::ostringstream strComodin, strComodin2 ;
	
	//desactivo al jugador de la lista de turnos del juego - from: player q se rinde
	this->gameManager->getTurnManager()->deletePlayer(command.getFrom());
	
	//se sortea el jugador que se quedara con los paises conquistados por el jugador que se rinde.
	RandomDice dado; 
	
	//tiro dados pidiendo un numero entre 1 y la cantidd de players activos.
	int posRandom = dado.roll( this->gameManager->getTurnManager()->getActivePlayerCount() );
	
	/* obtengo el color del jugador de la posRandom que se obtuvo, del vector que maneja el turnManager
	   esto es necesario ya que pueden quedar jugadores con ids: 1 3 6 con lo cual no se puede pedir directo un
	   jugador random ya que solo podrian aceptarse esos 3 valores, en cambio al pedir la pos. del vector random
	   se puede pedir una posRandom con un limiteMaximo = cant jugadores activos que tiene el turnManager.
	 */ 
	int colorJugadorSuertudo = this->gameManager->getTurnManager()->getColorPlayer(posRandom);
	
	ReferenceCountPtr<Player> jugadorSuertudo = gameManager->getGame()->getPlayer(colorJugadorSuertudo);
	ReferenceCountPtr<Player> jugadorRendido =  gameManager->getGame()->getPlayer(command.getFrom());
	
	jugadorSuertudo->transferLandsFrom(jugadorRendido);
	
		// ---- mensajea al cliente --------------
		
		//seteo al commando como valido
		command.setValid(1);
		//command.setTo(colorJugadorSuertudo);
		//a todos
		command.setTo(0);
		//from queda igual
				
		//seteo mje principal
   		strComodin << gameManager->getTurnManager()->getCurrentPlayer();
		strComodin2 << colorJugadorSuertudo;
		
		//mje para el defensor, para TO
		std::string mainMsg = "El jugador * " +strComodin.str() +"se rindio y por sorteo, el jugador "+ strComodin2.str()+
							  "gano todos sus paises";
		
		command.setMainMsg(mainMsg);
		command.setSecMsg("");	
		
		//notifico cambios y mensajes
		gameManager->notify(&command);
		
		//------- fin notificacion para cliente ------------------------
	
	return true;
}

bool State::youAre(ServerYouAre & command){
	// 
        return true;
}


bool State::quit(ServerQuit & command){
	// se debe eliminar command.getStringFrom() del juego
	// se debe hacer algo con los ejercitos, que esto lo haga quit en el cliente
	command.setValid(1);
	std::cerr << "State::quit() to: "<< command.getTo() << " from: " << command.getFrom() << std::endl;
	gameManager->remove(command.getFrom());

	gameManager->notify(&command);

        return true;
}

bool State::chat(ServerChat & command) {
	if (! command.isValid()) {
		command.setValid(1);
		gameManager->notify(&command);
	}
	return true;


}

bool State::lose(ServerLose & command) {
	return false;
}

bool State::map(ServerMap & command) {
	return false;
}

bool State::turnToAttack(ServerTurnToAttack & command) {
	return false;
}

bool State::turnToMove(ServerTurnToMove & command) {
	return false;
}

bool State::turnToOccupy(ServerTurnToOccupy & command) {
	return false;
}

bool State::turnToPopulate(ServerTurnToPopulate & command) {
	return false;
}

bool State::win(ServerWin & command) {
	return false;
}

bool State::noRoom(ServerNoRoom & command){
	return false;
}

bool State::mapList(ServerMapList & command){
	return false;
}


bool State::battleResult(ServerBattleResult & command){
	return false;
}


bool State::uiChat(UIChat & command){
	return false;
}

bool State::uiReadyToPlay(UIReadyToPlay & command){
	return false;
}

bool State::uiSurrender(UISurrender & command){
	return false;
}

bool State::uiQuit(UIQuit & command){
	return false;
}

bool State::uiDidIWin(UIDidIWin & command){
	return false;
}

bool State::uiNoMore(UINoMore & command){
	return false;
}

bool State::uiJoinGame(UIJoinGame & command) {
	return false;
}

bool State::uiSelectMap(UISelectMap & command) {
	return false;
}
bool State::uiCountrySelect(UICountrySelect & command){
	return false;
}


bool State::uiQuantitySelect(UIQuantitySelect & command){
	return false;
}

