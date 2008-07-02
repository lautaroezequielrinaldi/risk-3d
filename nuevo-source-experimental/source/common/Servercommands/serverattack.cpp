#include "serverattack.h"
#include "../commands/attack.h"
#include<sstream>
#include<iostream>

using namespace std;

ServerAttack::ServerAttack(): ServerCommand(),  Attack()
{
}

ServerAttack::ServerAttack( const std::string & xml ):ServerCommand(),Command (), Attack(xml) {
}

ServerAttack::~ServerAttack()
{
}

bool ServerAttack::validate(ReferenceCountPtr<GameManager>& gameManager){
	
	bool ataqueValido=false;
	ReferenceCountPtr<Game> game = gameManager->getGame();
	ReferenceCountPtr<Mapa> map = game->getMapa();
	ReferenceCountPtr<Pais> paisAtaca =	map->obtenerPais(this->getAttackerLand());
	ReferenceCountPtr<TurnManager> turnManager = gameManager->getTurnManager();
	ReferenceCountPtr<Player> jugadorActual = game->getPlayer( turnManager->getCurrentPlayer());
	
	std::string paisAt = this->getAttackerLand();
	std::string paisAtacad = this->getAttackedLand();
	
	//si el pais atacante es del jugador actual
	if( jugadorActual->landOwner(paisAt) ){
	//si el pais defensor NO es del jugador actual
		if( !jugadorActual->landOwner(paisAtacad) ){	
			/*si pais atacante es adyacente al pais atacado*/
			if( paisAtaca->esAdyacente(this->getAttackedLand())){
				/*si pais atacante ataca con 3 o menos ejercitos Y ataca con menos ejercitos de los que tiene*/
				if ( this->getArmyCount() <= 3  && this->getArmyCount() < paisAtaca->getArmyCount() )
					ataqueValido = true;
				else
					cerr<<"CANTIDAD DE EJERCITOS ATACANTES ( "<<this->getArmyCount() <<" ) INVALIDA -"<<endl;
			}
			else
				cerr<<"EL PAIS QUE ATACA NO ES ADYACENTE AL ATACADO"<<endl;
		}
		else
			cerr<<"ESTA INTENTANDO ATACAR UN PAIS SUYO"<<endl;
	}
	else
		cerr<<"EL PAIS CON EL QUE INTENTA ATACAR NO ES DEL JUGADOR ACTUAL"<<endl;
	
	
	
	return ataqueValido;
}

void ServerAttack::execute(ReferenceCountPtr<State>& state){
	
	state->attack(*this);
	
}

