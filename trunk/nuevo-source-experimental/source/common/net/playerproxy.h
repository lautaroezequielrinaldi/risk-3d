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
		
		bool readyToPlay;
	
	protected:
	
		void * run();

	public:
	
		PlayerProxy(const ReferenceCountPtr<Socket>& socket, const ReferenceCountPtr<GameManager>& gameManager);
	
		void setPlayer(ReferenceCountPtr<Player> & player);
	
		ReferenceCountPtr<Player> & getPlayer();
	
		/**
		 * Metodo cuyo proposito es setear si un jugador esta listo para jugar.
		 */
		void setReadyToPlay(bool state);
		
		/**
		 * Metodo cuyo proposito es verificar si un jugador esta listo para jugar.
		 */
		bool isReadyToPlay();
		
	
		virtual ~PlayerProxy();

};


#endif /** __PLAYERPROXY_H__ */
