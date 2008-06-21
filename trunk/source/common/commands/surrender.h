#ifndef __SURRENDER__
#define __SURRENDER__
#include "command.h"
class Surrender:public Command{
	public:
	Surrender();
	
	virtual ~Surrender();
	virtual void execute(ReferenceCountPtr<State>& state);

};

#endif /* __SURRENDER__*/
