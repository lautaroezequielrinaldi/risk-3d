#include "state.h"
#include "../commands/attack.h"
#include "../commands/chat.h"
#include "../commands/defend.h"
#include "../commands/joingame.h"
#include "../commands/move.h"
#include "../commands/selectmap.h"
#include "../commands/populate.h"
#include "../commands/readytoplay.h"
#include "../commands/nomore.h"
#include "../commands/noroom.h"
#include "../commands/surrender.h"
#include "../commands/quit.h"
#include "../commands/win.h"
#include "../commands/lose.h"
#include "../commands/youare.h"
#include "../commands/map.h"
#include "../commands/turntoattack.h"
#include "../commands/turntomove.h"
#include "../commands/turntooccupy.h"
#include "../commands/turntopopulate.h"
#include "../commands/didiwin.h"
#include "../commands/maplist.h"

#include "../commands/uireadytoplay.h"
#include "../commands/uididiwin.h"
#include "../commands/uiquit.h"
#include "../commands/uisurrender.h"
#include "../commands/uinomore.h"
#include "../commands/uijoingame.h"
#include "../commands/uiselectmap.h"

/*
#include "../commands/ui.h"
#include "../commands/ui.h"
*/

#include "stateobserver.h"

#include "../model/gamemanager.h"



#include<iostream>

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


bool State::attack(Attack & command){
	command.setMainMsg("Intento de ataque en momento inoportuno");
	command.setSecMsg("El jugador ... intentó atacar cuando no le tocaba");
	return false;
}

bool State::defend(Defend & command){
	command.setMainMsg("Intento de defensa en momento inoportuno");
	command.setSecMsg("El jugador ... intentó defenderse cuando no le tocaba");

	return false;
}

//virtual void State::occupy(Occupy & command);

bool State::joinGame(JoinGame & command){
	command.setMainMsg("...");
	command.setSecMsg("Un jugador intentó conectarse con el partido iniciado");
	return false;
}

bool State::move(Move & command){
	command.setMainMsg("Intento de movimiento en momento inoportuno");
	command.setSecMsg("El jugador ... intentó moverse cuando no le tocaba");
	cout<<"	no es momento de mover"<<endl;
	return false;
}
bool State::selectMap(SelectMap & command){
	command.setMainMsg("Intento de selección de mapa en momento inoportuno");
	command.setSecMsg("El jugador ... intentó seleccionar mapa cuando no le tocaba");

        return false;
}


bool State::populate(Populate & command){
	command.setMainMsg("Intento de poblar en momento inoportuno");
	command.setSecMsg("El jugador ... intentó poblar cuando no le tocaba");
	cout<<"	no es momento de atacar"<<endl;
     return false;
}

bool State::readyToPlay(ReadyToPlay & command){
	command.setMainMsg("Intento de aceptar el juego en momento inoportuno");
	command.setSecMsg("El jugador ... intentó aceptar el juego cuando no le tocaba");

	return false;
}

bool State::didIWin(DidIWin & command){
	command.setMainMsg("Intento de terminar etapa en momento inoportuno");
	command.setSecMsg("El jugador ... intentó terminar etapa cuando no le tocaba");

	return false;
}

bool State::noMore(NoMore & command){
	command.setMainMsg("Intento de terminar etapa en momento inoportuno");
	command.setSecMsg("El jugador ... intentó terminar etapa cuando no le tocaba");

	return false;
}

bool State::surrender(Surrender & command){
	// debe deshabilitar al jugador y convertir sus paises en republicas independientes
	return true;
}

bool State::youAre(YouAre & command){
	// 
        return true;
}


bool State::quit(Quit & command){
	// debe aplicar surrender y ademas cortar la conexión
        return true;
}

bool State::chat(Chat & command) {
	return false;
}

bool State::lose(Lose & command) {
	return false;
}

bool State::map(Map & command) {
	return false;
}

bool State::turnToAttack(TurnToAttack & command) {
	return false;
}

bool State::turnToMove(TurnToMove & command) {
	return false;
}

bool State::turnToOccupy(TurnToOccupy & command) {
	return false;
}

bool State::turnToPopulate(TurnToPopulate & command) {
	return false;
}

bool State::win(Win & command) {
	return false;
}

bool State::noRoom(NoRoom & command){
	return false;
}

bool State::mapList(MapList & command){
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

