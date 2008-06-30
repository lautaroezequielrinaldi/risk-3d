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
		
		/**
		 * Este metodo debe evaluar el destino del mensaje segun jugador
		 */
		int getTo();

		/**
		 * Este metodo debe evaluar el origen del mensaje segun jugador
		 */
		int getFrom();

		int isValid();

		void setValid(int valid);

		void setMainMsg(std::string msg) ;

		void setSecMsg(std::string msg);

		std::string getMainMsg();

		std::string getSecMsg();

		virtual std::string serialize() = 0;

		std::string serialize(int from, int to);

		virtual std::string getName() = 0;

		void* hydrate(std::string xml);

	protected:
		xmlDocPtr hydrateCommon(std::string xml);

	

};

#include "../state/state.h"
#include "../model/gamemanager.h"


#endif /*COMMAND_H_*/
