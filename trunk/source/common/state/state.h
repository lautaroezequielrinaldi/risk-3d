#ifndef __STATE_H__
#define __STATE_H__

#include <string>
#include "../smartpointer/referencecountptr.h"
#include <iostream>

class State;
/*
#include "../commands/attack.h"
#include "../commands/defend.h"
#include "../commands/joingame.h"
#include "../commands/move.h"
#include "../commands/selectmap.h"
#include "../commands/populate.h"
#include "../commands/readytoplay.h"
#include "../commands/nomore.h"
#include "../commands/surrender.h"
#include "../commands/quit.h"
*/

class GameManager;

class Attack;
class Chat;
class Defend;
class JoinGame;
class Move;
class SelectMap;
class Populate;
class ReadyToPlay;
class NoMore;
class Surrender;
class Quit;
class YouAre;
class Map;
class Lose;
class Win;
class TurnToAttack;
class TurnToMove;
class TurnToOccupy;
class SetOwner;
class Kill;

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

		// virtual bool battleResult(BattleResult & command);
		virtual bool lose(Lose & command);
		virtual bool map(Map & command);
		virtual bool turnToAttack(TurnToAttack & command);
		virtual bool turnToMove(TurnToMove & command);
		virtual bool turnToOccupy(TurnToOccupy & command);
		virtual bool win(Win & command);
		virtual bool setOwner(SetOwner & command);
		virtual bool kill(Kill & command);


};


#endif /** __STATE_H__ */

