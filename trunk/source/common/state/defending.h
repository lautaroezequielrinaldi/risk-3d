#ifndef DEFENDING_H_
#define DEFENDING_H_

#include "state.h"

class Attack;
class Defend;
class JoinGame;
class Move;
class SelectMap;
class Populate;
class ReadyToPlay;

class Defending : public State
{

	public:
	
		Defending();
	
		~Defending();
		
		bool defend(Defend & command);
		
/*
		State * getNext();
		
	    bool attack(Attack & command);
	    
	    
	    
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

#endif /*DEFENDING_H_*/
