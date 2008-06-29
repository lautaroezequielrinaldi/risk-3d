#include "game.h"

Game::Game(Dice& dice):
    Serializable(),
    mapa(),
    playerList(),
    dado(dice) {
    // No realiza ninguna acciòn.
}

Game::Game(const ReferenceCountPtr<Mapa>& mapa,Dice& dice):
    Serializable(),
    mapa(mapa),
    playerList(),
     dado(dice) {
    // No realiza ninguna acciòn.
}

Game::Game(const std::list< ReferenceCountPtr<Player> >& playerList,Dice& dice):
    Serializable(),
    mapa(),
    playerList(playerList),
     dado(dice) {
    // No realiza ninguna acciòn.
}

Game::Game(const ReferenceCountPtr<Mapa>& mapa,
    const std::list< ReferenceCountPtr<Player> >& playerList,
    Dice& dice):
    Serializable(),
    mapa(mapa),
    playerList(playerList),
    dado (dice) {
    // No realiza ninguna acciòn.
}

void Game::setMapa(const ReferenceCountPtr<Mapa>& mapa) {
    this->mapa = mapa;
}

ReferenceCountPtr<Mapa>& Game::getMapa() {
    return this->mapa;
}

void Game::setPlayerList(
    const std::list< ReferenceCountPtr<Player> >& playerList) {
    this->playerList = playerList;
}

std::list< ReferenceCountPtr<Player> >& Game::getPlayerList() {
    return this->playerList;
}

/**
  * @todo falta logica creacion jugador
  *
  */
ReferenceCountPtr<Player> & Game::addPlayer() {
	
	ReferenceCountPtr<Player> player = new Player(1,1);
	playerList.push_back(player);
	return playerList.back();
}


/**
 * @todo reimplementar utilizando un map <color, player>
 *
 */
ReferenceCountPtr<Player> Game::getPlayer(int color){

	bool encontrado = false;
	ReferenceCountPtr<Player> actualPlayer;
	std::list<ReferenceCountPtr<Player> >::iterator it;

	it =this->playerList.begin();
	/*busco en la lista de jugadores, al actual, usando el color del jugador q tiene el turno*/
	while ( it != this->playerList.end() && !encontrado) {
	
		actualPlayer = *it;
		
		/*comparo color del jugador especificado con color del jugador de la iteracion*/
		if ( color == actualPlayer->getColor() )
			encontrado=true;
		else
			++it;
	}
	
	if( !encontrado )
		actualPlayer = NULL;
		
	return actualPlayer;
	
	
}

         
Dice& Game::getDice(){
	
	return this->dado;	
}
      	

void Game::setDice( Dice& dice ){

	this->dado = dice;	
}

int Game::getCountryOwner(std::string countryName){
	
	std::list< ReferenceCountPtr<Player> >::iterator it;
	it = this->playerList.begin();
	
	while( it != this->playerList.end()){
		
		ReferenceCountPtr<Player> playerAct = *it;
		//si el jugador actual es el dueño del pais consultado
		if ( playerAct->landOwner(countryName) )
			return playerAct->getColor();
			
		++it;
	}
	//en caso de que ningun jugador sea el dueño, devuelve cero.
	return 0;
	
}

std::string Game::conformContinent(std::list<std::string> countryList){

	bool termino = false;
	bool contienePaises=true;
	ReferenceCountPtr<Mapa> map = this->getMapa();
	std::string paisActual;

	int cantPaisesPertenecientes=0;

	//std::list<Continente>::iterator itContinente;
	Mapa::IteradorContinente itContinente;
	itContinente = map->primerContinente();
	std::list<std::string>::iterator itPais;

	std::string nomContinente="";

	//recorro lista de continentes
	while ( itContinente != map->ultimoContinente() && !termino){
		//obtengo continente actual
		ReferenceCountPtr<Continente> continente = *itContinente;
		
		//me posiciono en 1er pais de los pasados
		itPais = countryList.begin();		
		
		//mientras la cant de paises de la lista pasada,pertenecientes al continente actual sea != de la cant de paises del continente
		// yno haya terminado la lista de paises consultados
		//while ( cantPaisesPertenecientes != continente->getCountryCount() && itPais != countryList.end() ){
			
			
	
	
	
	
	
	//	}
	
	
	
	
	
	
	
	
		//si la lista de paises pasada tiene la misma cantidad de paises que el continente actual
		if ( countryList.size() == continente->getCountryCount() ){

			
			
			while ( itPais != countryList.end() &&  contienePaises ){
				
				//ontengo pais actual de la lista de paises pasada
				paisActual = *itPais;				

				// si el continente no encuentra el pais pedido
				if ( continente->obtenerPais(paisActual) == NULL )
					contienePaises=false;
				else
					++itPais;
			}
		
			// si recorrio la lista de paises pasada y todos pertenecian al continente ( y las cant de paises fueron iguales
			// ---> la lista de paises pasada conforma el continente
			if ( contienePaises ){
				termino=true;
				//seteo nombre del continente que contiene todos los paises consultados
				nomContinente=continente->getNombre();
			}
		}
		++itContinente;
		
	}
	
	//salio del while de continente porque encontro q la lista de paises pasada conforman un continente
	return nomContinente;
	

}


std::string Game::serialize() {
    std::string resultado;
    return resultado;
}

void* Game::hydrate(std::string filename) {
    return NULL;
}

Game::~Game() {
    // No realiza ninguna acciòn.
}

