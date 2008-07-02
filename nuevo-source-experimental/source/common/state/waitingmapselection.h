#ifndef __WAITINGMAPSELECTION_H__
#define __WAITINGMAPSELECTION_H__

#include "state.h"

class WaitingMapSelection : public State
{

	public:

	WaitingMapSelection(ReferenceCountPtr<GameManager>&gameManager, std::string name);
		
	virtual ~WaitingMapSelection();
		
	virtual bool selectMap(ServerSelectMap & command); 
	virtual bool joinGame(ServerJoinGame & command);
	virtual bool readyToPlay(ServerReadyToPlay & command);
	virtual void accept(StateObserver* observer);
};

#endif /*__WAITINGMAPSELECTION_H__*/
