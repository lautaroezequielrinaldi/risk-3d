#include "serverdefend.h"
#include<sstream>
#include<iostream>

using namespace std;
ServerDefend::ServerDefend() : Defender()
{
}
ServerDefend::ServerDefend(const std::string & xml): Defender ( xml )
{
}

ServerDefend::~ServerDefend()
{
}

bool ServerDefend::validate(ReferenceCountPtr<GameManager>& gameManager){
	
	bool defensaValida = false;
	ReferenceCountPtr<Game> game = gameManager->getGame();
	ReferenceCountPtr<Mapa> map = game->getMapa();
	ReferenceCountPtr<Pais> paisDefiende = map->obtenerPais(this->getDefenderdLand());
	
	//obtengo jugador defensor ( al que atacaron en el ataque )
	ReferenceCountPtr<Player> playerDef = game->getPlayer( gameManager->getTurnManager()->getDefenderPlayer() );
	
	// si el jugador seteado como defensor, es el dueño del pais con el que se mando la defensa
	std::string pDef = this->getDefenderdLand();
	if( playerDef->landOwner( pDef ) ){
		
		//si el pais que fue atacado es igual al pais con el que se esta defendiendo el defensor
		if( gameManager->getAttack().getAttackedLand() == this->getDefenderdLand()){
			
			// si pais defensor defiende con 2 o menos ejercitos Y 
			// defiende con menos o igual ejercitos de los que tiene y
			// defiende con una cantidad de ejercitos <= que la cant de ejercitos con los que se ataco			
			if ( this->getArmyCount() <= 2  && this->getArmyCount() <= paisDefiende->getArmyCount()
			     && this->getArmyCount() <= gameManager->getAttack().getArmyCount() )
				
				defensaValida = true;
			else
				cerr<<"CANTIDAD DE EJERCITOS DEFENSORES INVALIDA"<<endl;
		}
		else
			cerr<<"DEFENSOR: TE ESTAS DEFENDIENDO CON UN PAIS TUYO QUE NO ES EL ATACADO"<<endl;
	}
	else
		cerr<<"DEFENSOR: POR QUE INTENTAS DEFENDERTE CON UN PAIS QUE NO ES TUYO? ES INVALIDO."<<endl;
	
	
	return defensaValida;
}

void ServerDefend::execute(ReferenceCountPtr<State>& state){
	
	state->defend(*this);
}

