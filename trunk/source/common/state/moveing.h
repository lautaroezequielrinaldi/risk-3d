#ifndef MOVEING_H_
#define MOVEING_H_

#include "state.h"

class Attack;
class Defend;
class JoinGame;
class Move;
class SelectMap;
class Populate;
class ReadyToPlay;


class Moveing : public State
{
	public:
	
		/**
		 * Constructor de la clase
		 */
		Moveing();
		
		/**
		 * Destructor de la clase
		 */	
		~Moveing();
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion correspondiente al estado del juego y notificar 
		 * los cambios en el mismo.
		 */
		bool move(Move & command);
/*
		State * getNext();
		
	    bool attack(Attack & command);
	    
	    bool defend(Defend & command);
	    
	   	//void occupy(Occupy & command)
	    
	    bool joinGame(JoinGame & command);
	    //bool kill(Kill & move);
	    bool selectMap(SelectMap & command);
	    //bool setOwner(SetOwner & command);
	    bool populate(Populate & command);
	    bool readyToPlay(ReadyToPlay & command);.
*/   
	 
};

#endif /*MOVEING_H_*/
