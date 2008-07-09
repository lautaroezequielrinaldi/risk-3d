#ifndef COMMONRESOURCE_H_
#define COMMONRESOURCE_H_

#include "thread/Condition_Variable.h"
#include "thread/mutex.h"
#include "commands/command.h"

/**
 * Clase compartida por La preGameWindow, GameWindow y ServerProxy.
 */
class CommonResource
{
	private:
	
		/**
		 * Indica si hay cambios para hacer en la vista grafica de los clientes.
		 */
		bool updateUI;
		
		/**
		 * Almacena un comando que debe ser escrito en el socket.
		 */
		Command * cmdWrite;
		/**
		 * Almacena un comando que debe ser leido por el socket.
		 */
		Command * cmdRead;
		
		/**
		 * Condition variable para poder hacer esperar al thread que envia datos.
		 */
		Condition_Variable condSend;
		/**
		 * Condition variable para poder hacer esperar al thread que recibe datos.
		 */
		Condition_Variable condRec;
		
		/**
		 * Mutex para proteger por accesos simultaneos.
		 */
		 Mutex mutex;
	
	public:
	
		/**
		 * Contructor de la clase.
		 */
		CommonResource();
		/**
		 * Destructor de la clase.
		 */
		~CommonResource();
		/**
		 * Metodo cuyo proposito es obtener el estado de la UI con respecto a cambios a realizarle.
		 */
		bool getUIupdate();
		/**
		 * Metodo cuyo propisito es establecer el estado de la UI con respecto a cambios.
		 */
		void setUIupdate(bool update);
		
		/**
		 * Metodo cuyo propisto es obtener el command wrte.
		 */
		Command* getCommandWrite();
		
		/**
		 * Metodo cuyo proposito es obtener  el commando read.
		 */
		Command* getCommandRead();
		
		/**
		 * Metodo cuyo proposito es establecer un comando a escribir.
		 */
		void setCommandWrite( Command *cmd);
		/**
		 * Metodo cuyo proposito es obtener el comando a enviar.
		 */
		void setCommandRead( Command *cmd);
		
		/**
		 * Metodo cuyo proposito es obtener una variable de condicion.
		 */
		//Condition_Variable& getSendConditionVariable();
		/**
		 * Metodo cuyo proposito es obtener una variable de condicion.
		 */		
		//Condition_Variable& getReceiveConditionVariable();
		
		
};

#endif /*COMMONRESOURCE_H_*/

