#include "filedicebattle.h"
#include <iostream>
#include <stdlib.h>


FileDiceBattle::FileDiceBattle(const std::string & fileName): Dice()
{
	std::string pathName = "/home/analia/Escritorio/risk3d/source/common/model/"+fileName;
	//abro archivo del cual se levantaran los valores que toma el dado
	this->file.open(pathName.c_str());
	this->posicionADevolverAt =0;
	this->posADevolverDef =0;
	this->atacante = true;	
	//cargo los vectores que almacenaran los valores de los dados tomados del archivo
	this->loadDiceValue();
	
}


FileDiceBattle::~FileDiceBattle()
{
	// si el archivo esta abierto, lo cierro- verificacion automatica.
	this->file.close();
}

int FileDiceBattle::roll(){
	
	int valor=0;
	
	// si la ultima pos devuelta es diferente de la ultima pos. del vector del atacante
	if ( this->posicionADevolverAt < this->dadosAtacante.size() && this->atacante){
		// devuelvo el valor correspondente a la pos que le toca
		valor = this->dadosAtacante[this->posicionADevolverAt];
		this->posicionADevolverAt++;
	}
	else{
		// seteo atacante en false para que entre siempre aca y devuelva los valores del defensor
		this->atacante=false;
		
		if ( this->posADevolverDef != this->dadosDefensor.size() ){
			// devuelvo valor correspondiente a pos que le toca
			valor =  this->dadosDefensor[this->posADevolverDef];
			this->posADevolverDef++;
		}
	}

	return valor;
}

void FileDiceBattle::loadDiceValue(){
		
	std::string linea;
	char coma = ',';
	const char* valor=NULL;
	
	dadosAtacante.clear();
	dadosDefensor.clear();
	
	//repito proceso para las dos lineas
	for (unsigned int j=0; j<2 ; j++){
		linea.clear();
		//leo linea j del archivo
		getline(this->file, linea);
		
		// cargo vec correspondiente con datos de linea leida
		for(unsigned int i=0; i < linea.length();i++){
			// si lo que leo del string no es una coma
			if ( linea[i] != coma ){
				valor = new char ( linea[i] );
				if( j==0 )
					//lo almaceno en el vector del atacante
					this->dadosAtacante.push_back( atoi (valor ) );				
				else
					this->dadosDefensor.push_back( atoi (valor) );
				
				valor=NULL;
				delete valor;
			}
		}
	}

}

int FileDiceBattle::roll(int maxLimit){
}



