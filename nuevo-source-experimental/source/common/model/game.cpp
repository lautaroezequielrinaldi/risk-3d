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

int Game::getPlayerCount(){
	return this->playerList.size();	
}

/**
  * @todo falta logica creacion jugador
  *
  */
ReferenceCountPtr<Player> & Game::addPlayer() {
	
	ReferenceCountPtr<Player> player = new Player();
	playerList.push_back(player);
	return playerList.back();
}

ReferenceCountPtr<Player> & Game::addPlayer(int color){
	
	ReferenceCountPtr<Player> player = new Player(color);
	playerList.push_back(player);
	return playerList.back();	
}

void Game::removePlayer(const ReferenceCountPtr<Player>& player) {
    playerList.remove(player);
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

void Game::remove(int color) {
	playerList.remove(getPlayer(color));
/*
	ReferenceCountPtr<Player> actual;
	std::list<ReferenceCountPtr<Player >::iterator it;
	it =this->playerList.begin();

	while ( it != this->playerList.end()) {
		actual = *it;
		if (actual->getColor() == color) {
			playerList.remove(it);
			break;
		}
		
		++it;
	}

*/	
}

         
Dice& Game::getDice(){
	
	return this->dado;	
}
      	

void Game::setDice( Dice& dice ){

	this->dado = dice;	
}

int Game::getCountryOwner( std::string & countryName){
	
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

std::vector<std::string> Game::conformContinent(const std::list<std::string>& countryList){


	ReferenceCountPtr<Mapa> map = this->getMapa();
	std::string paisActual;

	std::vector<std::string> vecContinentesConquist;
	int cantPaisesPertenecientes=0;

	//std::list<Continente>::iterator itContinente;
	Mapa::IteradorContinente itContinente;
	itContinente = map->primerContinente();
	std::list<std::string>::const_iterator itPais;

	std::string nomContinente="";

	//recorro lista de continentes
	while ( itContinente != map->ultimoContinente() ){
		//obtengo continente actual
		ReferenceCountPtr<Continente> continente = *itContinente;
		
		//me posiciono en 1er pais de los pasados
		itPais = countryList.begin();
			
		cantPaisesPertenecientes = 0;

		//mientras la cant de paises de la lista pasada,pertenecientes al continente actual sea != de la cant de paises del continente
		// y no haya terminado la lista de paises consultados
		while ( cantPaisesPertenecientes != continente->getCountryCount() && itPais != countryList.end() ){
			
			//ontengo pais actual de la lista de paises pasada
			paisActual = *itPais;

			// si el continente  encuentra el pais pedido
			if ( continente->obtenerPais(paisActual) != NULL )
				cantPaisesPertenecientes++;
	
			//avanzo en lista de paises
			++itPais;
	
	
		}
		
		//si la cantidad de paises pasados que pertenecen al continente actual es igual a la cant total de paises q tiene el conti
		if ( cantPaisesPertenecientes == continente->getCountryCount() )
			//agrego el continente actual a la lista de continentes conquistados.
			vecContinentesConquist.push_back( continente->getNombre() );

		++itContinente;
	}
	
	
	return vecContinentesConquist;
	

}


std::string Game::serialize() {
    std::string resultado;
    return resultado;
}

void* Game::hydrate(const std::string & filename) {
    return NULL;
}

Game::~Game() {
    // No realiza ninguna acciòn.
}

