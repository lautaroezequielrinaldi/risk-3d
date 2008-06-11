#include "battleResult.h"

BattleResult::BattleResult(std::string attackerLand,std::string defenderLand):
paisAtacante(attackerLand),
paisDefensor(defenderLand)
{
	this->resultadoAtacante=0;
	this->resultadoDefensor=0;
}

BattleResult::BattleResult()
{
	//no realiza ninguna accion
}

BattleResult::~BattleResult()
{
	
	//no realiza ninguna accion
}

std::string BattleResult::getAttackerLand(){
	return this->paisAtacante;
}
		
std::string BattleResult::getDefenderLand(){
	return this->paisDefensor;	
}
				
int BattleResult:: getAttackerResult(){
	return this->resultadoAtacante;
}
		
int BattleResult::getDefenderResult(){
	return this->resultadoDefensor;
}
				
void BattleResult::deletetAttackerArmy(){
	this->resultadoAtacante--;	
}
			
void BattleResult::deletetDefenderArmy(){
	this->resultadoDefensor--;	
}

std::string BattleResult::serialize(){
	
}

void* BattleResult::hydrate(std::string fileName){
	
}

