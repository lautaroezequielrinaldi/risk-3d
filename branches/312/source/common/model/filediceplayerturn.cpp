#include "filediceplayerturn.h"

fileDicePlayerTurn::fileDicePlayerTurn(std::string fileName)
{
	
	//abro archivo del cual se levantaran los valores que toma el dado
	this->file.open(fileName.c_str());
}

fileDicePlayerTurn::~fileDicePlayerTurn()
{
	// si el archivo esta abierto, lo cierro- verificacion automatica.
	this->file.close();
}

int fileDicePlayerTurn::roll(){
	
	std::string linea;
	int valor;
	char * strValor=NULL;
	
	
	// obtengo valor del archivo
	getline(this->file, linea);
	
	strValor = new char (linea[0]);
	valor = atoi (strValor);
	
	//libero memoria
	delete strValor;

	return valor;
	
}




