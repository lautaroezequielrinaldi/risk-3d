#include "serverbattleresult.h"

ServerBattleResult::ServerBattleResult() : BattleResult(), ServerCommand()
{
}

ServerBattleResult::ServerBattleResult(const std::string & xml) : ServerCommand(),BattleResult( xml )
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


