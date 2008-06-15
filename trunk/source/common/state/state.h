#ifndef __STATE_H__
#define __STATE_H__

class Attack;
class Defend;
class JoinGame;
class Move;
class SelectMap;
class Populate;
class ReadyToPlay;

class State {
	public:
	State();
	virtual ~State();




     virtual bool attack(Attack & command);
     virtual bool defend(Defend & command);
     virtual bool joinGame(JoinGame & command);
     //bool kill(Kill & move);
     virtual bool move(Move & command);
     virtual bool selectMap(SelectMap & command);
     //bool setOwner(SetOwner & command);
     virtual bool populate(Populate & command);
     virtual bool readyToPlay(ReadyToPlay & command);

};
#endif /** __STATE_H__ */

