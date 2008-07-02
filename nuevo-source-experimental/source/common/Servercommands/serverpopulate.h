#ifndef SERVERPOPULATE_H_
#define SERVERPOPULATE_H_

#include "servercommand.h"
#include "../commands/populate.h"

class ServerPopulate : public ServerCommand, public Populate

{
public:

		ServerPopulate();
        ServerPopulate(const std::string& xml);		
		~ServerPopulate();
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state);

		/**
		 * Metodo cuyo proposito es validar la accion de ocupar un territorio vacio.
		 */
		bool validateOccupy(ReferenceCountPtr<GameManager>& gameManager);
};

#endif /*SERVERPOPULATE_H_*/
