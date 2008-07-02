#ifndef __SERVERPROXY_H__
#define __SERVERPROXY_H__

#include "proxy.h"

class GameManager;
/**
 *
 * 
 */
class ServerProxy:public Proxy {
    private:
        ReferenceCountPtr<GameManager> gameManager;
	protected:
	void * run();

	public:
	ServerProxy(const ReferenceCountPtr<Socket>& socket, const ReferenceCountPtr<GameManager>& gameManager);
	virtual ~ServerProxy();

};


#endif /** __SERVERPROXY_H__ */
