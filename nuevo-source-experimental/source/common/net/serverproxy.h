#ifndef __SERVERPROXY_H__
#define __SERVERPROXY_H__

#include "proxy.h"

class Game;
class ClientCommand;
class Command;
class CommandObserver;
/**
 *
 * 
 */
class ServerProxy:public CommandObserver, public Proxy {
    private:
        ReferenceCountPtr<Game> game;
        ClientCommandHydrator commandHydrator;
        MessageHydrator messageHydrator;
	protected:
	void * run();

	public:
	ServerProxy(const ReferenceCountPtr<Socket>& socket, const ReferenceCountPtr<Game>& game);
    ReferenceCountPtr<Game> getGame();
	virtual ~ServerProxy();

};


#endif /** __SERVERPROXY_H__ */

