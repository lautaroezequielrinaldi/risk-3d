#ifndef CONQUER_H_
#define CONQUER_H_

#include "command.h"

class Conquer : public Command
{
	
	public:
	
		/**
		 * Constructor de la clase
		 */
		Conquer();
	
		/**
		 * Destructor de la clase
		 */
		~Conquer();
		
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		bool validate(ReferenceCountPtr<GameManager>& gameMAnager);
		
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		void execute(ReferenceCountPtr<GameManager>& gameMAnager);
};

#endif /*CONQUER_H_*/
