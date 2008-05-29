

//#include "game.h"

class GameManager {
	public:
	GameManager();
	void addPlayer(Socket & socket);


};

class ConnManager:public Cancelable {
	public:
	ConnManager();

	private:
	GameManager & gameManager;





};