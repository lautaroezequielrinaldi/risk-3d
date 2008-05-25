#include "defend.h"

Defend::Defend(std::vector<std::string> &parameterList, Mapa &mapa) : Command (mapa)
{
}

Defend::~Defend()
{
}

std::string& Defend::serialize(){
	
	
	std::string s;
	
	return s;
}

void* Defend::hydrate(ReferenceCountPtr<Mapa>& mapa,std::string fileName){
	
	
	return NULL;
}
		
bool Defend::validate(){
	
	bool defensaValida = false;
	ReferenceCountPtr<Pais> paisDefiende = this->mapa.obtenerPais(this->paisDefensor);
	
	/*si pais atacante defiende con 2 o menos ejercitos Y defiende con menos ejercitos de los que tiene*/
	if ( paisDefiende->getArmyCount() <= 2  && this->cantidadEjercitos < paisDefiende->getArmyCount() )
		defensaValida = true;
	
	return defensaValida;
}

