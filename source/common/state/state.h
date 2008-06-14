#ifndef __STATE_H__
#define __STATE_H__

#include "../commands/attack.h"
#include "../commands/defend.h"
#include "../commands/joingame.h"
#include "../commands/move.h"
#include "../commands/selectmap.h"
#include "../commands/populate.h"
#include "../commands/readytoplay.h"

class State {
	public:
	State();
	~State();




     bool attack(Attack * command);
     bool defend(Defend * command);
     bool joinGame(JoinGame * command);
     //bool kill(Kill * move);
     bool move(Move * command);
     bool selectMap(SelectMap * command);
     //bool setOwner(SetOwner * command);
     bool populate(Populate * command);
     bool readyToPlay(ReadyToPlay * command);

    
    





};
#endif /** __STATE_H__ */

