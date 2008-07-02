#ifndef __PROXY_H__
#define __PROXY_H__
#include "../thread/threaded.h"
#include "../thread/cancelable.h"
#include "../smartpointer/referencecountptr.h"
#include "sockets/socket.h"

class GameManager;
class Command;

/**
 *
 *
 */
class Proxy:public Threaded, public Cancelable {
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
