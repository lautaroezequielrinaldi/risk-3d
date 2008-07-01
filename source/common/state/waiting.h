#ifndef __WAITING_H__
#define __WAITING_H__

#include "state.h"

class Waiting : public State
{

	public:

	Waiting(ReferenceCountPtr<GameManager>&gameManager, std::string name);
	
	virtual ~Waiting();
	
	bool attack(Attack & command);
	bool youAre(YouAre & command);
	bool turnToAttack(TurnToAttack & command);
	bool mapList(MapList & command);
	bool quit(Quit & command);
	bool move(Move & command);
	
	bool lose(Lose & command);
	bool map(Map & command);
	bool turnToMove(TurnToMove & command);
	bool turnToOccupy(TurnToOccupy & command);
	bool uiReadyToPlay(UIReadyToPlay & command);
	bool uiNoMore(UINoMore & command);
	bool uiSurrender(UISurrender & command);
	bool uiQuit(UIQuit & command);
	bool uiDidIWin(UIDidIWin & command);
	bool uiSelectMap(UISelectMap & command);
	bool uiChat(UIChat & command);
	virtual void accept(StateObserver* observer);
};

#endif /*__WAITING_H__*/
