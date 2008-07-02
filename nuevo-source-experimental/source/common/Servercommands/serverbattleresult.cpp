#include "serverbattleresult.h"

ServerBattleResult::ServerBattleResult() : BattleResult()
{
}

ServerBattleResult::ServerBattleResult(const std::string & xml) : BattleResult( xml )
{
}



ServerBattleResult::~ServerBattleResult()
{
}

bool ServerBattleResult::validate(ReferenceCountPtr<GameManager>& gameMAnager){
	return true;
}
		
void ServerBattleResult::execute(ReferenceCountPtr<State>& state){

	state->battleResult(*this);
}


