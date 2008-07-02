#ifndef __STATE_H__
#define __STATE_H__

#include <string>
#include "../smartpointer/referencecountptr.h"
#include <iostream>

class GameManager;

class ServerAttack;
class ServerChat;
class ServerDefend;
class ServerDidIWin;
class ServerJoinGame;
class ServerMove;
class ServerMapList;
class ServerSelectMap;
class ServerPopulate;
class ServerReadyToPlay;
class ServerNoMore;
class ServerNoRoom;
class ServerSurrender;
class ServerQuit;
class ServerYouAre;
class ServerMap;
class ServerLose;
class ServerWin;
class ServerTurnToAttack;
class ServerTurnToMove;
class ServerTurnToOccupy;
class ServerTurnToPopulate;
class ServerBattleResult;

class UIReadyToPlay;
class UIQuit;
class UIChat;
class UISurrender;
class UINoMore;
class UIDidIWin;
class UIJoinGame;
class UISelectMap;

class UICountrySelect;
class UIQuantitySelect;


class StateObserver;

class State {

	private:
	
		std::string name;
		
	protected:
		
		ReferenceCountPtr<GameManager>&gameManager;

	public:

		/**
		 * Constructor de la clase
		 */

		State(ReferenceCountPtr<GameManager>&gameManager, std::string name);
		
		/**
		 * Destructor de la clase
		 */
		virtual ~State();

		/**
		 * @return nombre del estado
		 *
		 */
		std::string getName();

		
		/*
		 * Comandos generados exclusivamente por el cliente
		 */
		virtual bool attack(ServerAttack & command);
		virtual bool defend(ServerDefend & command);
		virtual bool joinGame(ServerJoinGame & command);
		virtual bool move(ServerMove & command);
		virtual bool selectMap(ServerSelectMap & command);
		virtual bool populate(ServerPopulate & command) ;
		virtual bool readyToPlay(ServerReadyToPlay & command);
		virtual bool noMore(ServerNoMore & command);
		virtual bool surrender(ServerSurrender & command);
		virtual bool quit(ServerQuit & command);
		virtual bool chat(ServerChat & command);
		virtual bool didIWin(ServerDidIWin & command);

		/*
		 * Comandos generados exclusivamente por el servidor
		 */
		virtual bool battleResult(ServerBattleResult & command);
		virtual bool lose(ServerLose & command);
		virtual bool map(ServerMap & command);
		virtual bool mapList(ServerMapList & command);
		virtual bool turnToAttack(ServerTurnToAttack & command);
		virtual bool turnToMove(ServerTurnToMove & command);
		virtual bool turnToOccupy(ServerTurnToOccupy & command);
		virtual bool turnToPopulate(ServerTurnToPopulate & command);
		virtual bool win(ServerWin & command);
		virtual bool youAre(ServerYouAre & command);
		virtual bool noRoom(ServerNoRoom & command);

		/*
		 * Comandos generados exclusivamente por la UI
		 */
		virtual bool uiReadyToPlay(UIReadyToPlay & command);
		virtual bool uiDidIWin(UIDidIWin & command);
		virtual bool uiQuit(UIQuit & command);
		virtual bool uiChat(UIChat & command);
		virtual bool uiSurrender(UISurrender & command);
		virtual bool uiNoMore(UINoMore & command);
		virtual bool uiJoinGame(UIJoinGame & command);
		virtual bool uiSelectMap(UISelectMap & command);
		virtual bool uiCountrySelect(UICountrySelect & command);
		virtual bool uiQuantitySelect(UIQuantitySelect & command);


		virtual void accept(StateObserver* observer) = 0;



};


#endif /** __STATE_H__ */

