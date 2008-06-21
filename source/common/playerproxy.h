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
	ReferenceCountPtr<GameManager> gameManager;
	ReferenceCountPtr<Player> player;
	protected:
	void * run();

	public:
	PlayerProxy(Socket * socket, ReferenceCountPtr<GameManager>& gameManager);
	void setPlayer(ReferenceCountPtr<Player> & player);
	ReferenceCountPtr<Player> & getPlayer();
	void notify(const std::string & msg);
	virtual ~PlayerProxy();

};


#endif /** __PLAYERPROXY_H__ */
