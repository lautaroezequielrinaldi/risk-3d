#include "surrender.h"

Surrender::Surrender(){

}

Surrender::~Surrender(){

}


void Surrender::execute(ReferenceCountPtr<State>& state){
	
	state->surrender(*this);
	
}
