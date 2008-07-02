#ifndef __SERVERPROXY_H__
#define __SERVERPROXY_H__

#include "proxy.h"

/**
 *
 * 
 */
class ServerProxy:public Proxy {

	protected:
	void * run();

	public:
	ServerProxy(Socket * socket, ReferenceCountPtr<GameManager>& gameManager);
	virtual ~ServerProxy();

};


#endif /** __SERVERPROXY_H__ */
