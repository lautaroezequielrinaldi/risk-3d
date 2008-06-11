#ifndef __PROXYPLAYER_H__
#define __PROXYPLAYER_H__
#include "../common/thread/threaded.h"

#include "../common/net/sockets/socket.h"
/**
 *
 * @todo usar & en lugar de *
 */
class PlayerProxy:public Threaded {
	private:
	Socket * socket;
	// State & state;
	// GameController & gamecontroller;

	protected:
	void * run();

	public:
	PlayerProxy(Socket * socket);

	~PlayerProxy();

};
#endif /** __PROXYPLAYER_H__ */
