#ifndef __PLAYERPROXY_H__
#define __PLAYERPROXY_H__
#include "proxy.h"

class GameManager;
class Player;

/**
 *
 * 
 */
class PlayerProxy: public Proxy {
	protected:
    ReferenceCountPtr<GameManager> gameManager;
	ReferenceCountPtr<Player> player;
	protected:
	void * run();

	public:
	PlayerProxy(const ReferenceCountPtr<Socket>& socket, const ReferenceCountPtr<GameManager>& gameManager);
	void setPlayer(ReferenceCountPtr<Player> & player);
	ReferenceCountPtr<Player> & getPlayer();
	virtual ~PlayerProxy();

};


#endif /** __PLAYERPROXY_H__ */
