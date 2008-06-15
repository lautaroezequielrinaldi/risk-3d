#ifndef __STATE_H__
#define __STATE_H__

#include <string>
#include "../smartpointer/referencecountptr.h"

class Attack;
class Defend;
class JoinGame;
class Move;
class SelectMap;
class Populate;
class ReadyToPlay;

class State {

	private:
	
		std::string name;


	public:
		
		/**
		 * Constructor de la clase
		 */
		State();
		
		/**
		 * Destructor de la clase
		 */
		virtual ~State();


		virtual State * getNext()=0;
		std::string getName();


	    virtual bool attack(Attack & command) = 0;
	    
	    virtual bool defend(Defend & command) = 0;
	    virtual bool joinGame(JoinGame & command) = 0;
	    //bool kill(Kill & move);
	    virtual bool move(Move & command) = 0;
	    virtual bool selectMap(SelectMap & command) = 0;
	    //bool setOwner(SetOwner & command);
	    virtual bool populate(Populate & command) = 0;
	    virtual bool readyToPlay(ReadyToPlay & command) = 0;
};

#endif /** __STATE_H__ */

