#include "nomore.h"

NoMore::NoMore(){

}

NoMore::~NoMore(){

}


void NoMore::execute(ReferenceCountPtr<State>& state){
	
	state->noMore(*this);
	
}
