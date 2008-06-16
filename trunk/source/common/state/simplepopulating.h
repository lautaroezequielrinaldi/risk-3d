#ifndef SIMPLEPOPULATING_H_
#define SIMPLEPOPULATING_H_

#include "state.h"

class Attack;
class Defend;
class JoinGame;
class Move;
class SelectMap;
class Populate;
class ReadyToPlay;

class SimplePopulating : public State
{
	
	public:
	
		SimplePopulating();
	
		~SimplePopulating();
/*
		State * getNext();
		
	    bool attack(Attack & command);
	    
	    bool defend(Defend & command);
	    
	   	//void occupy(Occupy & command)
	    
	    bool joinGame(JoinGame & command);
	    //bool kill(Kill & move);
	    bool move(Move & command);
	    bool selectMap(SelectMap & command);
	    //bool setOwner(SetOwner & command);
	    bool populate(Populate & command);
	    bool readyToPlay(ReadyToPlay & command);
*/
	    
};

#endif /*SIMPLEPOPULATING_H_*/
