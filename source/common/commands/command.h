#ifndef COMMAND_H_
#define COMMAND_H_

#include "../parser/serializable.h"
//#include "../state/state.h"
//#include "../model/gamemanager.h" // Para definiciòn de gameManager.
#include "../smartpointer/referencecountptr.h" // Para definiciòn de ReferenceCountPtr

/**
 * Forward declaration de la clase State.
 */
class State;
class GameManager;

/**
 * Clase abstracta cuyo proposito es brindar la interfaz de un comando serializable.
 */ 
class Command : public Serializable
{
	private:
	
		int to;
		int from;
		int valid;
		std::string name;
		std::string mainmsg;
		std::string secmsg;
			
	public:
		
		/*
		 * Constructor de la clase.
		 */
		Command();
		/*
		 * Destructor de la clase.
		 */
		virtual ~Command();
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		virtual bool validate(ReferenceCountPtr<GameManager>& gameMAnager)=0;
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		virtual void execute(ReferenceCountPtr<State>& state)=0;
		
		/**
		 * Metodo cuyo proposito es evaluar el destino del mensaje segun jugador.
		 */
		int getTo();

		/**
		 * Metodo cuyo proposito es evaluar el origen del mensaje segun jugador.
		 */
		int getFrom();

		/**
		 * Metodo cuyo proposito es verificar si el comando es valido.
		 */
		int isValid();
		
		/**
		 * Metodo cuyo proposito es obtener el mensaje principal 
		 */		
		std::string getMainMsg();
		
		/**
		 * Metodo cuyo proposito es obtener el mensaje secundario. 
		 */
		std::string getSecMsg();

		/**
		 * Metodo cuyo proposito es obtener el nombre del comando 
		 */
		virtual std::string getName() = 0;
		
		/**
		 * Metodo cuyo proposito es establecer si el comando es valido. 
		 */
		void setValid(int valid);
		
		/**
		 * Metodo cuyo proposito es establecer el origen del mensaje segun el jugador. 
		 */
		void setFrom(int from);
		
		/**
		 * Metodo cuyo proposito es establecer el destino del mensaje segun el jugador. 
		 */
		void setTo(int to);

		/**
		 * Metodo cuyo proposito es establecer el mensaje principal. 
		 */
		void setMainMsg( std::string  msg) ;

		/**
		 * Metodo cuyo proposito es establecer el mensaje secundario. 
		 */
		void setSecMsg( std::string  msg);
		
		/**
		 * Metodo cuyo proposito es serializar un comando a un string xml. 
		 */
		virtual std::string serialize() = 0;

		/**
		 * Metodo cuyo proposito es hidratar un comando. 
		 */
		void* hydrate(const std::string  & xml);

		/**
		 * Metodo cuyo proposito es serializar la parte comun que poseen todos los comandos. 
		 */
		std::string serialize(int from, int to);
				
	protected:

		/**
		 * Metodo cuyo proposito es hidratar la parte comun de los comandos. 
		 */
		xmlDocPtr hydrateCommon(const std::string & xml);

	

};

#include "../state/state.h"
#include "../model/gamemanager.h"


#endif /*COMMAND_H_*/
