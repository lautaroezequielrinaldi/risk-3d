#ifndef __STATEMACHINE_H__ 
#define __STATEMACHINE_H__ 
#include <map>
#include "../smartpointer/referencecountptr.h"


class StateMachine {
    public: 
     StateMachine();
     ~StateMachine();

    private:
    ReferenceCountPtr<State> state;
    map<std::string,ReferenceCountPtr<State> > currentState;

};
#endif /** __STATEMACHINE_H__ */

