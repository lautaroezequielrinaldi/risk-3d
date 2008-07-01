#ifndef __WAITING_H__
#define __WAITING_H__

#include "state.h"

class Waiting : public State
{

	public:

	Waiting(ReferenceCountPtr<GameManager>&gameManager, std::string name);
	
	virtual ~Waiting();


	/*
	* Comandos generados exclusivamente por el cliente
	*/	
	bool attack(Attack & command);
	bool move(Move & command);
	bool noMore(NoMore & command);
	bool surrender(Surrender & command);
	bool quit(Quit & command);
	bool didIWin(DidIWin & command);
	bool readyToPlay(ReadyToPlay & command);
	/*
	 * Comandos generados exclusivamente por el servidor
	 */
	bool youAre(YouAre & command);
	bool turnToAttack(TurnToAttack & command);
	bool mapList(MapList & command);
	bool battleResult( BattleResult & command );
	bool lose(Lose & command);
	bool map(Map & command);
	bool turnToMove(TurnToMove & command);
	bool turnToOccupy(TurnToOccupy & command);

	/*
	 *  Comandos generados exclusivamente por la UI
	 */
	bool uiReadyToPlay(UIReadyToPlay & command);
	bool uiNoMore(UINoMore & command);
	bool uiSurrender(UISurrender & command);
	bool uiQuit(UIQuit & command);
	bool uiDidIWin(UIDidIWin & command);
	bool uiSelectMap(UISelectMap & command);
	bool uiChat(UIChat & command);
	bool uiCountrySelect(UICountrySelect & command);
	bool uiQuantitySelect(UIQuantitySelect & command);

	virtual void accept(StateObserver* observer);
};

#endif /*__WAITING_H__*/
