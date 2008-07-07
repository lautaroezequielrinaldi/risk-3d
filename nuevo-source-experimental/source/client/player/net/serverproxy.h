#ifndef __SERVERPROXY_H__
#define __SERVERPROXY_H__

#include "../../../common/net/proxy.h"
#include "../../../common/commands/commandobservable.h"
#include "../commands/clientcommandhydrator.h"
#include "../../../common/commands/messagehydrator.h"

#include <glibmm.h>
using Glib::Dispatcher;

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
        	
        	/*
        	 *	Dispatcher encargado de notificar a la preGameWindow cuando recibe un mapList
        	 */
			Dispatcher dispatcherMapList;
			
			/*
        	 *	Dispatcher encargado de notificar a la preGameWindow cuando recibe un youAre
        	 */
			Dispatcher dispatcherYouAre;
        	
			/*
        	 *	Dispatcher encargado de notificar a la preGameWindow cuando recibe un readyToPlay
        	 */
			Dispatcher dispatcherReadyToPlay;        	
		
			/*
        	 *	Dispatcher encargado de notificar a la preGameWindow cuando recibe un readyToPlay
        	 */
			Dispatcher dispatcherNoRoom;    	

	
	protected:
			
			/**
			 * Metodo invocado al iniciarse el thread.
			 */
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
			 * Metodo cuyo proposito es obtener el dispatcher encargado de notificar sobre la lista de mapas.
			 */
			Dispatcher& getDispatcherMapList();
			
			/**
			 * Metodo cuyo proposito es obtener el dispatcher encargado de notificar quien es el jugador nuevo.
			 */
			Dispatcher& getDispatcherYouAre();
	
			/**
			 * Metodo cuyo proposito es obtener el dispatcher encargado de notificar que todos los jugadores estan listos.
			 */
			Dispatcher& getDispatcherReadyToPlay();
			
			/**
			 * Metodo cuyo proposito es obtener el dispatcher encargado de notificar que todos los jugadores estan listos.
			 */
			Dispatcher& getDispatcherNoRoom();		
			
			/**
			 * Destructor de la clase.
			 */
			virtual ~ServerProxy();

};


#endif /** __SERVERPROXY_H__ */

