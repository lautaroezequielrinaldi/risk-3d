#include <stdlib.h>
#include "attack.h"

Attack::Attack(std::vector<std::string> & parameterList, Mapa &mapa):Command ( mapa )
{
	/*construyo el objeto a partir de los parametros pasados en la lista*/
	this->paisAtacante = parameterList[0];
	this->paisAtacado = parameterList[1];
	this->cantidadEjercitos = atoi (parameterList[2].c_str() );
}

Attack::~Attack()
{
}

std::string Attack::serialize(){
	
	
  std::string s;
  return s;

}

void* Attack::hydrate(ReferenceCountPtr<Mapa>& mapa,std::string fileName){
	
	
	return NULL;
}
		
bool Attack::validate(){
	
	bool ataqueValido=false;
	ReferenceCountPtr<Pais> paisAtaca = this->mapa.obtenerPais(this->paisAtacante);
	
	/*si pais atacante es adyacente al pais atacado*/
	if( paisAtaca->esAdyacente(this->paisAtacado)){
		/*si pais atacante ataca con 3 o menos ejercitos Y ataca con menos ejercitos de los que tiene*/
		if ( paisAtaca->getArmyCount() <= 3  && this->cantidadEjercitos < paisAtaca->getArmyCount() )
			ataqueValido = true;
	}
	
	return ataqueValido;
}


