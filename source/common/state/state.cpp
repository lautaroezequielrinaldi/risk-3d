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
#include "../commands/surrender.h"
#include "../commands/quit.h"
#include "../model/gamemanager.h"

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
//virtual bool State::kill(Kill & move);
bool State::move(Move & command){
	command.setMainMsg("Intento de movimiento en momento inoportuno");
	command.setSecMsg("El jugador ... intentó moverse cuando no le tocaba");

	return false;
}
bool State::selectMap(SelectMap & command){
	command.setMainMsg("Intento de selección de mapa en momento inoportuno");
	command.setSecMsg("El jugador ... intentó seleccionar mapa cuando no le tocaba");

        return false;
}

//bool virtual setOwner(SetOwner & command);
bool State::populate(Populate & command){
	command.setMainMsg("Intento de poblar en momento inoportuno");
	command.setSecMsg("El jugador ... intentó poblar cuando no le tocaba");

     return false;
}

bool State::readyToPlay(ReadyToPlay & command){
	command.setMainMsg("Intento de aceptar el juego en momento inoportuno");
	command.setSecMsg("El jugador ... intentó aceptar el juego cuando no le tocaba");

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


