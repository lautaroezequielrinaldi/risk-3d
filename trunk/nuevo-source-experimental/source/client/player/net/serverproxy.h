#ifndef __SERVERPROXY_H__
#define __SERVERPROXY_H__

#include "../../../common/net/proxy.h"
#include "../../../common/commands/commandobservable.h"
#include "../commands/clientcommandhydrator.h"
#include "../../../common/commands/messagehydrator.h"

class Game;
class ClientCommand;
class Command;

/**
 *
 * 
 */
class ServerProxy:public CommandObservable, public Proxy {
    
    private:
    		/**
    		 * Almacena una referencia al juego"
    		 */
    	    ReferenceCountPtr<Game> game;
    	    
    	    /**
    	     * Almacena un commandHydrator del Cliente.
    	     */
        	ClientCommandHydrator commandHydrator;
        	
        	/**
        	 * Almacena un messageHydrator.
        	 */
        	MessageHydrator messageHydrator;
	
	protected:
	
			void * run();

	public:
			
			/**
			 * Constructor de la clase.
			 */
			ServerProxy(const ReferenceCountPtr<Socket>& socket, const ReferenceCountPtr<Game>& game);
    
    		/**
    		 * Metodo cuyo proposito es obtener el juego.
    		 */
    		ReferenceCountPtr<Game> getGame();
	
			/**
			 * Destructor de la clase.
			 */
			virtual ~ServerProxy();

};


#endif /** __SERVERPROXY_H__ */

