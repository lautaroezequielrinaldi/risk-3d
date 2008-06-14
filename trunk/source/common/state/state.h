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




     bool Attack(Attack * command);
     bool Defend(Defend * command);
     bool JoinGame(JoinGame * command);
     //bool Kill(Kill * move);
     bool Move(Move * command);
     bool SelectMap(SelectMap * command);
     //bool SetOwner(SetOwner * command);
     bool Populate(Populate * command);
     bool ReadyToPlay(ReadyToPlay * command);

    
    





};
#endif /** __STATE_H__ */

