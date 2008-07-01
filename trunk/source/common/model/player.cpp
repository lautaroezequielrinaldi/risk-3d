#include "player.h"


// definicion del atributo estatico para que el linker lo encuentre.
int Player::ultimoColorAsignado = 0;

Player::Player(int color, int armyCount)
{
	this->color = color;
	this->ejercitosAUbicar = armyCount;
		
}

Player::Player()
{
	this->color = getNewColor();
}


Player::~Player()
{
}

int Player::getNewColor(){
	
	//genero un nuevo numero que represente a un color
	Player::ultimoColorAsignado++;	
	return Player::ultimoColorAsignado;
}

int Player::getColor(){
	return this->color;
}

void Player::setColor(int color){
	this->color = color;
}

int Player::getArmyCount(){
	return this->ejercitosAUbicar;
}

void Player::setArmyCount(int armyCount){
	this->ejercitosAUbicar = armyCount;
}

std::list<std::string>& Player::getConqueredLandList(){
	
	return this->listaPaisesConquistados;	
}		

std::list<std::string>& Player::getConqueredContinentList(){
	return this->listaContinentesConquistados;
}

unsigned int Player::getConqueredLands(){
	return this->listaPaisesConquistados.size();
	
}
		
unsigned int Player::getConqueredContinents(){
	return this->listaContinentesConquistados.size();
}
		 		 
void Player::addConqueredLand(std::string& landName){
	this->listaPaisesConquistados.push_back(landName);
}		 

void Player::addConqueredContinent(std::string& continenName){
	this->listaContinentesConquistados.push_back(continenName);
}
	 
void Player::removeConqueredLand(std::string &landName){
	this->listaPaisesConquistados.remove(landName);
}
		 
void Player::removeConqueredContinent(std::string& continenName){
	this->listaContinentesConquistados.remove(continenName);
}

bool Player::landOwner(std::string& landName ){
	
    std::list< std::string>::iterator it;

    /* Itero por cada pais */
    for (it = this->listaPaisesConquistados.begin(); it != this->listaPaisesConquistados.end();++it) {
        /*obtengo pais actual*/
        std::string paisActual = *it;

		/*si el pais buscado esta en la lista de paises conquistados*/
		if ( paisActual == landName )
			return true;
	}
	
	return false;
}
	  
bool Player::continentOwner(std::string& continentName ){

	std::list< std::string>::iterator it;

    /* Itero por cada continente */
    
    for (it = this->listaContinentesConquistados.begin(); it != this->listaContinentesConquistados.end();++it) {
        //obtengo continente actual
        std::string continenteActual = *it;

		//si el continente buscado esta en la lista de continentes conquistados
		if ( continenteActual == continentName )
			return true;
 	}	
	
	return false;
}



