#include "filediceplayerturn.h"
#include <iostream>
using namespace std;

#include<iostream>

using namespace std;

FileDicePlayerTurn::FileDicePlayerTurn(const std::string & fileName):Dice()
{
			
	std::string pathName = "/home/analia/Escritorio/risk3d/source/common/model/"+fileName;
	//abro archivo del cual se levantaran los valores que toma el dado
	this->file.open(pathName.c_str());
	
	
}
FileDicePlayerTurn::~FileDicePlayerTurn()
{
	// si el archivo esta abierto, lo cierro- verificacion automatica.
	this->file.close();
}

int FileDicePlayerTurn::roll(){
	
	
	std::string linea;
	int valor;
	const char *strValor= NULL;

	
	// obtengo valor del archivo
	getline(this->file, linea);

	strValor = new char ( linea[0] ); 
	valor = atoi (strValor);
	
	cout<<"EMPIEZA JUGADOR: "<<valor<<endl;
	
	//libero memoria
	strValor=NULL;
	delete strValor;

	return valor;

}




