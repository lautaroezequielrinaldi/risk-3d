#include "Guarda_Generica.h" 
#include "Buffer.h"

Buffer::Buffer(int topeMaximo, int cantidadProductores)
{
	this->topeMaximo = topeMaximo;
	this->cantElementos=0;
	this->productores = cantidadProductores;
}

Buffer::~Buffer()
{
	this->topeMaximo = -1;
	this->cantElementos=0;
}

void Buffer::put(string elemento){

	Guarda_Generica<Mutex,int,int> guarda( this->mutex,& Mutex::lock, & Mutex::unlock);

	if (bufferLleno()){
	
		/*el thread actual espera hasta recibir senial de que el buffer tiene lugar disponible*/
		this->cond_buflleno.wait(this->mutex);
	}
	
	cola.push(elemento);
	cantElementos++;
		
	/*si hay un thread esperando la condicion del buffer vacio, se lo despierta indicando que ya hay elementos*/
	cond_buffVacio.signal();
			
}

string Buffer::get(){
	
	string primerElem;
	
	Guarda_Generica<Mutex,int,int> guarda ( this->mutex,& Mutex::lock, & Mutex::unlock);
	

	/*sino hay elem. en buffer pero quedan productores por producir elementos*/
	if( bufferVacio() && this->productores!=0 )
		
		/*el thread actual espera hasta recibir senial de que el buffer tiene al menos un elem.*/
		this->cond_buffVacio.wait(this->mutex);		
	
	
	if ( !cola.empty() ){
		primerElem = cola.front();
		cola.pop();
		cantElementos--;
		
		/*si hay un thread esperando la condicion del buffer lleno, se lo despiera indicando que el buffer ya no esta lleno*/
		this->cond_buflleno.signal();
	}

	return primerElem;
}


bool Buffer::bufferLleno(){

	if(	cantElementos== topeMaximo)
		return true;
	else
		return false;
}

bool Buffer::bufferVacio(){
	
	if(	cantElementos==0)
		return true;
	else
		return false;
}

void Buffer::terminoProductor(){
	

	Guarda_Generica<Mutex,int,int> guarda( this->mutex,& Mutex::lock, & Mutex::unlock );
	
	/*decremento cant de productores*/
	this->productores--;
	/*inicio señal por si hay algun thread esperando*/
	this->cond_buffVacio.signal();
	
	
}
	
int Buffer::getCantidadProductores(){
	return this->productores;
}
	
