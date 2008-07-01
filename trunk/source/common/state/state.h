#ifndef __STATE_H__
#define __STATE_H__

#include <string>
#include "../smartpointer/referencecountptr.h"
#include <iostream>

class GameManager;

class Attack;
class Chat;
class Defend;
class DidIWin;
class JoinGame;
class Move;
class MapList;
class SelectMap;
class Populate;
class ReadyToPlay;
class NoMore;
class NoRoom;
class Surrender;
class Quit;
class YouAre;
class Map;
class Lose;
class Win;
class TurnToAttack;
class TurnToMove;
class TurnToOccupy;
class TurnToPopulate;
//class BattleResult;

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

		
		
		virtual bool attack(Attack & command);
		virtual bool defend(Defend & command);
		virtual bool joinGame(JoinGame & command);
		virtual bool move(Move & command);
		virtual bool selectMap(SelectMap & command);
		virtual bool populate(Populate & command) ;
		virtual bool readyToPlay(ReadyToPlay & command);
		virtual bool noMore(NoMore & command);
		virtual bool surrender(Surrender & command);
		virtual bool quit(Quit & command);
		virtual bool chat(Chat & command);
		virtual bool youAre(YouAre & command);

		//virtual bool battleResult(BattleResult & command);
		virtual bool lose(Lose & command);
		virtual bool map(Map & command);
		virtual bool mapList(MapList & command);
		virtual bool turnToAttack(TurnToAttack & command);
		virtual bool turnToMove(TurnToMove & command);
		virtual bool turnToOccupy(TurnToOccupy & command);
		virtual bool turnToPopulate(TurnToPopulate & command);
		virtual bool win(Win & command);
		virtual bool didIWin(DidIWin & command);
		virtual bool noRoom(NoRoom & command);

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

