#ifndef SERVERATTACK_H_
#define SERVERATTACK_H_

class Attack;

#include "servercommand.h"

#include "../commands/attack.h"

class ServerAttack : public ServerCommand, public Attack
{
	public:
	
		ServerAttack();
		
		ServerAttack( const std::string & xml );
		
		virtual ~ServerAttack();
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);		

};

#endif /*SERVERATTACK_H_*/

