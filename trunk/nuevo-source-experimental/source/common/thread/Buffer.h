#ifndef BUFFER_H_
#define BUFFER_H_

#include <string>
#include <queue>
#include "Mutex.h"
#include "Condition_Variable.h"

using namespace std;

class Buffer
{
	private:
	
		queue<string> cola;
		Mutex mutex;
		int cantElementos;
		int topeMaximo;
		int productores;

		Condition_Variable cond_buflleno;
		Condition_Variable cond_buffVacio;
			
	
	public:
	
		Buffer(int topeMaximo, int cantidadProductores);
		virtual ~Buffer();
		
		/* inserta un elemento al final del buffer*/
		void put(string);
		/*Devuelve el primer elemento del buffer y lo elimina del mismo*/
		string get();
		
		/*Verifica si el buffer esta lleno, depende de la cantidad maxima de elementos del buffer*/
		bool bufferLleno();
		/*Verifica si el buffer esta vacio, depende de la cantidad de elementos del buffer*/
		bool bufferVacio();
		
		/*Devuelve la cantidad de productores con los que esta trabajando el buffer*/
		int getCantidadProductores();	
		
		/* Baja de un productor*/
		void terminoProductor();
		
		
};

#endif /*BUFFER_H_*/
