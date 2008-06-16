#ifndef ATTACKING_H_
#define ATTACKING_H_

#include "state.h"

class Attack;
class Defend;
class JoinGame;
class Move;
class SelectMap;
class Populate;
class ReadyToPlay;

class Attacking : public State
{

	public:

		Attacking();
		
		~Attacking();
		
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

#endif /*ATTACKING_H_*/
