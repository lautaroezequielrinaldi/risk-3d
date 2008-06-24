#ifndef __SERVERPROXY_H__
#define __SERVERPROXY_H__
#include "../common/thread/threaded.h"
#include "../common/smartpointer/referencecountptr.h"
#include "../common/net/sockets/socket.h"
class ServerProxy;

#include "../common/model/gamemanager.h"
/**
 *
 * @todo usar & en lugar de *
 */
class ServerProxy:public Threaded {
	private:
	Socket & socket;
	ReferenceCountPtr<GameManager> gameManager;

	protected:
	void * run();

	public:
	ServerProxy(Socket & socket, ReferenceCountPtr<GameManager>& gameManager);

	void notify(const std::string & msg);
	virtual ~ServerProxy();

};


#endif /** __SERVERPROXY_H__ */
