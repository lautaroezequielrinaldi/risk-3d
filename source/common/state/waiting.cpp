#include "waiting.h"
#include "stateobserver.h"


#include "../commands/uichat.h"
#include "../commands/chat.h"
#include "../commands/uireadytoplay.h"
#include "../commands/readytoplay.h"
#include "../commands/uiquit.h"
#include "../commands/quit.h"
#include "../commands/uinomore.h"
#include "../commands/nomore.h"
#include "../commands/uisurrender.h"
#include "../commands/surrender.h"
#include "../commands/uididiwin.h"
#include "../commands/didiwin.h"
#include "../commands/selectmap.h"
#include "../commands/uiselectmap.h"
#include "../commands/battleresult.h"

#include "../commands/youare.h"

#include <sstream>
using namespace std;

Waiting::Waiting(ReferenceCountPtr<GameManager>&gameManager, std::string name):State(gameManager,name)
{
}

Waiting::~Waiting()
{
}

bool Waiting::attack(Attack & command){
	std::cerr << "Evento Waiting::attack" << std::endl;
	/*

	 if (isForMe()) {
		// pasar a modo Defending

	}
	

	*/
	return false;
}

bool Waiting::mapList(MapList & command){
	
	std::cerr << "Evento Waiting::mapList" << std::endl;
	/* Debe hace aparecer un dialogo en la presala
	 *
	 *
	 */

	return false;
}
bool Waiting::noMore(NoMore & command){
	return false;
}

bool Waiting::surrender(Surrender & command){
	return false;
}

bool Waiting::didIWin(DidIWin & command){
	return false;
}
bool Waiting::readyToPlay(ReadyToPlay & command) {
	return false;
}

bool Waiting::quit(Quit & command) {
	std::cerr << "Evento Waiting::Quit" << std::endl;
	// si es valido
	if (command.isValid() && command.getFrom() == gameManager->getMe()) {
		// cerrar la aplicacion de un modo mas elegante...
		throw 20;
	} else {
		// notificar a la interfaz que el usuario tal se fue del juego
	}
	return false;
}

bool Waiting::youAre(YouAre & command){
	std::cerr << "Evento Waiting::youAre : " << command.getTo() << std::endl;
	gameManager->setMe(command.getTo());
	
	return false;
}

bool Waiting::turnToAttack(TurnToAttack & command){
	std::cerr << "Evento Waiting::turnToAttack" << std::endl;

	/*
	if (isForMe()) {
		pasar a modo Attacking
	}
	*/
	return false;
}


bool Waiting::move(Move & command){
	std::cerr << "Evento Waiting::move" << std::endl;

	return false;
}

bool Waiting::lose(Lose & command){
	std::cerr << "Evento Waiting::lose" << std::endl;

	
	//if (isForMe()) {
		//pasar a modo Observing, no implementado aun
	//}
	
	return false;
}
bool Waiting::map(Map & command){
	std::cerr << "Evento Waiting::map" << std::endl;

	return false;
}
bool Waiting::turnToMove(TurnToMove & command){
	std::cerr << "Evento Waiting::turnToMove" << std::endl;

	/*
	if (isForMe()) {
		pasar a modo Moving
	}
	*/
	return false;
}
bool Waiting::turnToOccupy(TurnToOccupy & command){
	std::cerr << "Evento Waiting::turnToOccupy" << std::endl;

	/*
	if (isForMe()) {
		pasar a modo Occupying
	}
	*/
	return false;
}

bool Waiting::battleResult( BattleResult & command ){
	
	// att que necesito para luego de ejecutar la batalla, se actualice el modelo con el resultado
	ReferenceCountPtr<Game> game = this->gameManager->getGame();
	ReferenceCountPtr<Mapa> map = game->getMapa();
	ReferenceCountPtr<Pais> paisAtacante = map->obtenerPais( command.getAttackerLand() );
	ReferenceCountPtr<Pais> paisDefensor = map->obtenerPais( command.getDefenderLand() );	

	ReferenceCountPtr<Player> playerAtacante = game->getPlayer( command.getAttackercolor() );
	ReferenceCountPtr<Player> playerDefensor = game->getPlayer( command.getDefenderColor() );
	
		
	// actualizacion del modelo con respecto al resultado de la batalla

	// elimina del pais atacante, los ejercitos perdidos en la batalla . si perdio 0 ejercitos no modifica nada.
	paisAtacante->removeArmies(command.getAttackerResult());

	// elimina del pais defensor, los ejercitos perdidos en la batalla . si perdio 0 ejercitos no modifica nada.
	paisDefensor->removeArmies(command.getDefenderResult());


	// verifico si hubo conquista de pais defensor

	// si pais defensor se quedo con cero ejercitos
	if ( paisDefensor->getArmyCount() == 0  ){
		
		cerr<<"PAIS CONQUISTADO"<<endl;
		
		// elimino al pais defensor de la lista de paises del player defensor
		std::string defLand = command.getDefenderLand();
		playerDefensor->removeConqueredLand(defLand);
		
		// agrego pais conquistado a la lista de paises del jugador atacante
		playerAtacante->addConqueredLand(defLand );
				
		// remuevo del pais atacante tantos ejercitos como dados usados en la batalla ( = dant ejercitos defensores )
		// para "moverlos" al pais conquistado.
		paisAtacante->removeArmies( command.getConquest() );
		// agrego al pais defensor que fue conquistado por el atacante los ejercitos "movidos"
		paisDefensor->addArmies(  command.getConquest() );

		cerr<<"EL ATACANTE MOVIO "<<command.getDefenderResult()<<" ejercitos para conquistar."<<endl;
		cerr<<"el pais "<<command.getAttackerLand()<<"que ataco, se quedo con ejercitos: "<<paisAtacante->getArmyCount()<<endl;
	

		//verifico si hubo conquista de continente a partir de la conquista de un nuevo pais
	
		//  obtengo lista de continentes conquistados, si los hay, a partir de los paises conquistados.
		std::vector<std::string> vecContinentes = game->conformContinent(playerAtacante->getConqueredLandList() );
			
		//veo si la lista de continentes conquistados tiene alguno que no este seteado en los continentes del jugador ( nuevo continente //conquistado.
		for ( unsigned int i=0; i<vecContinentes.size();i++){
			//si playerAtacante no es dueño todavia de uno de los continentes conquistados segun vecContinentes
			if ( !playerAtacante->continentOwner( vecContinentes[i] ) )
				//seteo al continente actual como conquistado por el player atacante
				playerAtacante->addConqueredContinent(vecContinentes[i] );
		}
	}
	
	//falta notificar mensajes que trae battleResult- PARA TODOS el mismo
}

bool Waiting::uiReadyToPlay(UIReadyToPlay & command){
	ReadyToPlay * cmd = new ReadyToPlay();
	cmd->setFrom(gameManager->getMe());
	this->gameManager->notify(cmd);
	delete(cmd);
	return false;
}

bool Waiting::uiQuit(UIQuit & command){
	std::cerr << "Evento Waiting::uiQuit from: "<< gameManager->getMe() << std::endl;

	Quit * cmd = new Quit();
	cmd->setFrom(gameManager->getMe());

	std::cerr << "Evento Waiting::uiQuit Quit->from: "<< cmd->getFrom() << std::endl;


	this->gameManager->notify(cmd);
	delete(cmd);
	return false;
}

bool Waiting::uiNoMore(UINoMore & command){
	std::cerr << "Evento Waiting::uiNoMore" << std::endl;

	NoMore * cmd = new NoMore();
	cmd->setFrom(gameManager->getMe());
	this->gameManager->notify(cmd);
	delete(cmd);
	return false;
}

bool Waiting::uiSurrender(UISurrender & command){
	Surrender * cmd = new Surrender();
	cmd->setFrom(gameManager->getMe());
	this->gameManager->notify(cmd);
	delete(cmd);
	return false;
}

bool Waiting::uiDidIWin(UIDidIWin & command){
	DidIWin * cmd = new DidIWin();
	cmd->setFrom(gameManager->getMe());
	this->gameManager->notify(cmd);
	delete(cmd);
	return false;

}

bool Waiting::uiSelectMap(UISelectMap & command){
	std::cerr << "Waiting::uiSelectMap me: " << gameManager->getMe() << std::endl;

	SelectMap * cmd = new SelectMap();
	cmd->setFrom(gameManager->getMe());
	cmd->setMapName(command.getMapName());
	this->gameManager->notify(cmd);
	delete(cmd);
	return false;


}

bool Waiting::uiChat(UIChat & command){
	std::cerr << "Waiting::uiChat me: " << gameManager->getMe() << std::endl;

	Chat * cmd = new Chat();
	cmd->setFrom(gameManager->getMe());
	cmd->setMainMsg(command.getMainMsg());
	this->gameManager->notify(cmd);
	delete(cmd);
	return false;


}
void Waiting::accept(StateObserver* observer) {
	observer->stateChanged(*this);
}

bool Waiting::uiCountrySelect(UICountrySelect & command){
	return false;
}

bool Waiting::uiQuantitySelect(UIQuantitySelect & command){
	return false;
}
