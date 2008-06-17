#ifndef __PROXYPLAYER_H__
#define __PROXYPLAYER_H__
#include "../common/thread/threaded.h"
#include "../common/smartpointer/referencecountptr.h"
#include "../common/net/sockets/socket.h"
class GameManager;
/**
 *
 * @todo usar & en lugar de *
 */
class PlayerProxy:public Threaded {
	private:
	Socket * socket;
	ReferenceCountPtr<GameManager> gamemanager;
	protected:
	void * run();

	public:
	PlayerProxy(Socket * socket, ReferenceCountPtr<GameManager>);
	void notify(const std::string & msg);
	~PlayerProxy();

};

#include "../common/model/gamemanager.h"

#endif /** __PROXYPLAYER_H__ */
