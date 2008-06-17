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
class NoMore;
class Surrender;
class Quit;

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

		std::string getName();

		
		
	    virtual bool attack(Attack & command);
	    
	    virtual bool defend(Defend & command);
	    
	    //virtual void occupy(Occupy & command);
	    
	    virtual bool joinGame(JoinGame & command);
	    //virtual bool kill(Kill & move);
	    virtual bool move(Move & command);
	    virtual bool selectMap(SelectMap & command);
	    //bool virtual setOwner(SetOwner & command);
	    virtual bool populate(Populate & command) ;
	    virtual bool readyToPlay(ReadyToPlay & command);
            virtual bool noMore(NoMore & command);
            virtual bool surrender(Surrender & command);
     
            virtual bool quit(Quit & command);
};


#endif /** __STATE_H__ */
