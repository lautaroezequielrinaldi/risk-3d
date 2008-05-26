#include "move.h"

Move::Move(std::vector<std::string> &parameterList, Mapa &mapa): Command ( mapa )
{
	this->paisOrigen = parameterList[0];
	this->paisDestino = parameterList[1];
	this->cantidadEjercitos = atoi( parameterList[2].c_str() );
	
}

Move::~Move()
{
}

std::string& Move::serialize(){
	
	
	std::string s;
	
	return s;
}

void* Move::hydrate(ReferenceCountPtr<Mapa>& mapa,std::string fileName){
	
	
	return NULL;
}
		
bool Move::validate(){
	
	bool movimValido=false;
	ReferenceCountPtr<Pais> paisO = this->mapa.obtenerPais(this->paisOrigen);
	
	/*si pais origen es adyacente al pais destino*/
	if( paisO->esAdyacente(this->paisDestino)){
		/*si la cantidad de ejercitos a mover es menor a la cantidad de ejercitos que tiene el pais origen*/
		if ( this->cantidadEjercitos < paisO->getArmyCount() )
			movimValido = true;
	}
	
	return movimValido;
	
}

