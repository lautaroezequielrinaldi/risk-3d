#ifndef __COMMANDHYDRATOR_H__
#define __COMMANDHYDRATOR_H__

class GameManager;
class ServerCommand;

#include <map>
#include <string>


class CommandHydrator {
	
	public:
		
		/**
		 * Constructor de la clase
		 */
		CommandHydrator();
		
		/**
		 * Destructor de la clase
		 */
		virtual ~CommandHydrator();
		
		/**
		 * Metodo cuyo proposito es obtener un comando a partir del nombre proporcionado,
		 * hidratado a partir del xml proporcionado.
		 */
		ServerCommand * getCommand(const std::string &name, const std::string & xml);
	
	
	private:
	
		std::map <std::string, ServerCommand * > commands;

};
#endif /*__COMMANDHYDRATOR_H__*/
