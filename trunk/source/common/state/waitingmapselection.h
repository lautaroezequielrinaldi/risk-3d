#ifndef WAITINGMAPSELECTION_H_
#define WAITINGMAPSELECTION_H_

#include "state.h"

class WaitingMapSelection : public State
{

	public:

		WaitingMapSelection();
		
		~WaitingMapSelection();
		
	                   virtual bool selectMap(SelectMap & command); 
};

#endif /*WAITINGMAPSELECTION_H_*/
