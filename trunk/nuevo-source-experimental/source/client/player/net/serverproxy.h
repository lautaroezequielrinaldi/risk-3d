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

