#ifndef COMMAND_H_
#define COMMAND_H_

#include "../parser/serializable.h"
//#include "../state/state.h"
#include "../model/gamemanager.h" // Para definiciòn de gameManager.
#include "../smartpointer/referencecountptr.h" // Para definiciòn de ReferenceCountPtr

class State;

/**
 * Clase abstracta cuyo proposito es brindar la interfaz de un comando serializable.
 */ 
class Command : public Serializable
{
		
	public:
		
		/*
		 * Constructor de la clase
		 */
		Command();
		/*
		 * Destructor de la clase
		 */
		virtual ~Command();
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameMAnager)=0;
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando
		 */
		virtual void execute(ReferenceCountPtr<State>& state)=0;
		
};

#endif /*COMMAND_H_*/
