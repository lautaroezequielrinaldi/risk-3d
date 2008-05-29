
#include "../common/thread/threaded.h"
#include "../common/thread/cancelable.h"
#include "../common/net/sockets/socket.h"

class ProxyPlayer {
	public:
	ProxyPlayer(Socket & socket);
	private:
	ProxyPlayer(const ProxyPlayer&);
	ProxyPlayer& operator=(const ProxyPlayer&);

};

class GameManager {
	public:
	GameManager();
	~GameManager();
	void addPlayer(ProxyPlayer & proxyPlayer);

};



class ProxyPlayerFactory {
	public:
	ProxyPlayerFactory();
	static ProxyPlayer & getProxyPlayer(Socket * socket);
	~ProxyPlayerFactory();

};

class ConnManager:public Threaded, public Cancelable {
	public:
	void * run();
	ConnManager(GameManager & gameManager,ProxyPlayerFactory & proxyPlayerFactory);
	~ConnManager();
	private:
	GameManager & gameManager;
	ProxyPlayerFactory & proxyPlayerFactory;




};
