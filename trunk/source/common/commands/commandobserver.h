#ifndef __COMMANDOBSERVER_H__
#define __COMMANDOBSERVER_H__

#include "attack.h"
#include "battleresult.h"
#include "chat.h"
#include "defend.h"
#include "didiwin.h"
#include "joingame.h"
#include "lose.h"
#include "map.h"
#include "maplist.h"
#include "move.h"
#include "nomore.h"
#include "noroom.h"
#include "populate.h"
#include "quit.h"
#include "readytoplay.h"
#include "selectmap.h"
#include "surrender.h"
#include "turntoattack.h"
#include "turntomove.h"
#include "turntooccupy.h"
#include "turntopopulate.h"
#include "win.h"
#include "youare.h"

class CommandObserver {
	/**
	 * Metodos protegidos de la clase CommandObserver.
	 */
	protected:
		/**
		 * Constructor de la clase CommandObserver.
		 */
		CommandObserver();
	/**
	 * Metodos publicos de la clase CommandObserver.
	 */
	public:
		virtual void commandExecuted(Attack& cmd);
		virtual void commandExecuted(BattleResult& cmd);
		virtual void commandExecuted(Chat& cmd);
		virtual void commandExecuted(Defend& cmd);
		virtual void commandExecuted(DidIWin& cmd);
		virtual void commandExecuted(JoinGame& cmd);
		virtual void commandExecuted(Lose& cmd);
		virtual void commandExecuted(Map& cmd);
		virtual void commandExecuted(MapList& cmd);
		virtual void commandExecuted(Move& cmd);
		virtual void commandExecuted(NoMore& cmd);
		virtual void commandExecuted(NoRoom& cmd);
		virtual void commandExecuted(Populate& cmd);
		virtual void commandExecuted(Quit& cmd);
		virtual void commandExecuted(ReadyToPlay& cmd);
		virtual void commandExecuted(SelectMap& cmd);
		virtual void commandExecuted(Surrender& cmd);
		virtual void commandExecuted(TurnToAttack& cmd);
		virtual void commandExecuted(TurnToMove& cmd);
		virtual void commandExecuted(TurnToOccupy& cmd);
		virtual void commandExecuted(TurnToPopulate& cmd);
		virtual void commandExecuted(Win& cmd);
		virtual void commandExecuted(YouAre& cmd);
		/**
		 * Destructor virtual de la clase CommandObserver.
		 */
		virtual ~CommandObserver();
};

#endif /** __COMMANDOBSERVER_H__ */

