#ifndef SELECTMAP_H_
#define SELECTMAP_H_

/**
 * client => server
 */

#include "command.h"

class SelectMap : public Command
{

	
	private:
	
		std::string nombreMapa;
		int numeroJugador;

	
	public:
	
		/*
		 * Constructor de la clase
		 */
		SelectMap(std::vector<std::string> &parameterList);
		
		/**
		 * Constructor de la clase.
		 * La misma se construye a partir del Xml especificado.
		 */
		SelectMap(const std::string &xml);

		SelectMap();
		
		/*
		 * Destructor de la clase
		 */		
		virtual ~SelectMap();
		
		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();
		/**
		 * Metodo cuyo proposito es hidratar  un objeto a partir del Xml especificado.
		 */
		void* hydrate(const std::string &xml);
		
		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		bool validate(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion que realice el comando.
		 */
		void execute(ReferenceCountPtr<State>& state);
		
		virtual std::string getName();

		/**
		 * Notiifca que se ejecuto un comando.
		 */
		virtual void accept(CommandObserver* observer);
};

#endif /*SELECTMAP_H_*/
