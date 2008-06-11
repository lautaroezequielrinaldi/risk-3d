#ifndef __PROXYPLAYER_H__
#define __PROXYPLAYER_H__
#include "../common/thread/threaded.h"

#include "../common/net/sockets/socket.h"

#include <vector>
/**
 *
 * @todo usar & en lugar de *
 */
class PlayerProxy:public Threaded {
	private:
	Socket * socket;
	// State & state;
	// GameController & gamecontroller;
	std::vector<PlayerProxy *> & players;

	protected:
	void * run();

	public:
	PlayerProxy(Socket * socket, std::vector<PlayerProxy *> & players);
	void notify(const std::string & msg);
	~PlayerProxy();

};
#endif /** __PROXYPLAYER_H__ */
