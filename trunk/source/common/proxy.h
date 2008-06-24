#ifndef __PROXY_H__
#define __PROXY_H__
#include "../common/thread/threaded.h"
#include "../common/smartpointer/referencecountptr.h"
#include "../common/net/sockets/socket.h"

class GameManager;


/**
 *
 *
 */
class Proxy:public Threaded {
	protected:
	Socket * socket;
	ReferenceCountPtr<GameManager> gameManager;
	protected:
	void * run();

	public:
	Proxy(Socket * socket,  ReferenceCountPtr< GameManager> & gameManager);
	void notify(const std::string & msg);
	virtual ~Proxy();

};


#endif /** __PROXY_H__ */
