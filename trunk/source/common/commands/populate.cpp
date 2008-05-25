#include "populate.h"

Populate::Populate(std::vector<std::string> &parameterList, Mapa &mapa) : Command ( mapa)
{
}

Populate::~Populate()
{
}

std::string& Populate::serialize(){
	
	
	std::string s;
	
	return s;
}

void* Populate::hydrate(ReferenceCountPtr<Mapa>& mapa,std::string fileName){
	
	
	return NULL;
}
		
bool Populate::validate(){
	
	return true;
	
}

