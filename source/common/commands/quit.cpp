#include "quit.h"

Quit::Quit(){

}
Quit::~Quit(){

}


void Quit::execute(ReferenceCountPtr<State>& state){
	
	state->quit(*this);
	
}
