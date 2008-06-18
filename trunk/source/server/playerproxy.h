#ifndef __PLAYERPROXY_H__
#define __PLAYERPROXY_H__
#include "../common/thread/threaded.h"
#include "../common/smartpointer/referencecountptr.h"
#include "../common/net/sockets/socket.h"
class PlayerProxy;

#include "../common/model/gamemanager.h"
#include "../common/model/player.h"
/**
 *
 * @todo usar & en lugar de *
 */
class PlayerProxy:public Threaded {
	private:
	Socket * socket;
	ReferenceCountPtr<GameManager> gamemanager;
	ReferenceCountPtr<Player> player;
	protected:
	void * run();

	public:
	PlayerProxy(Socket * socket, ReferenceCountPtr<GameManager>& gamemanager);
	void setPlayer(ReferenceCountPtr<Player> & player);
	void notify(const std::string & msg);
	~PlayerProxy();

};


#endif /** __PLAYERPROXY_H__ */
