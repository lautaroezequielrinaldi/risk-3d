#include "../model/armyBonusCalculator.h"
#include "populate.h"

Populate::Populate(std::vector<std::string> &parameterList, Mapa &mapa, Player& player) : Command (player,  mapa)
{
	this->paisDestino = parameterList[0];
	this->cantidadEjercitos = atoi( parameterList[1].c_str() );
}

Populate::~Populate()
{
}

std::string Populate::serialize(){
	
	
	std::string s;
	
	return s;
}

void* Populate::hydrate(ReferenceCountPtr<Mapa>& mapa,std::string fileName){
	
	
	return NULL;
}
		
bool Populate::validate(){
	
	/*creo un calculador de ejercitos extras correspondientes el jugador para verificar que no use mas de los debidos*/
	ArmyBonusCalculator calculadorBonus(this->jugador, this->mapa);
	
	if (this->cantidadEjercitos <= calculadorBonus.getArmyBonus() )
		return true;
	else
		return false;
	
}

