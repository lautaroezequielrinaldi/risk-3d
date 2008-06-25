#ifndef __PROXY_H__
#define __PROXY_H__
#include "../common/thread/threaded.h"
#include "../common/smartpointer/referencecountptr.h"
#include "../common/net/sockets/socket.h"

class GameManager;
class Command;

/**
 *
 *
 */
class Proxy:public Threaded {
	protected:
	Socket * socket;
	ReferenceCountPtr<GameManager> gameManager;
	protected:
	virtual void * run()=0;

	public:
	Proxy(Socket * socket,  ReferenceCountPtr< GameManager> & gameManager);
	void notify(Command * command);
	virtual ~Proxy();

};


#endif /** __PROXY_H__ */
