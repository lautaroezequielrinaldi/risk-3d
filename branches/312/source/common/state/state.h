#ifndef __STATE_H__
#define __STATE_H__

#include <string>
#include "../smartpointer/referencecountptr.h"

#include "../model/gamemanager.h"

/*
#include "../commands/attack.h"
#include "../commands/defend.h"
#include "../commands/joingame.h"
#include "../commands/move.h"
#include "../commands/selectmap.h"
#include "../commands/populate.h"
#include "../commands/readytoplay.h"
#include "../commands/nomore.h"
#include "../commands/surrender.h"
#include "../commands/quit.h"
*/

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
/* comentado por charli para compilar 313
		ReferenceCountPtr<GameManager> gameManager;
*/
	public:
		
		/**
		 * Constructor de la clase
		 */
		State(ReferenceCountPtr<GameManager>& gameManager);
		

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

