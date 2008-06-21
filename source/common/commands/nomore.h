#ifndef __NOMORE_H__
#define __NOMORE_H__
#include "command.h"

class NoMore: public Command {
	public:
	NoMore();
	virtual ~NoMore();
	virtual void execute(ReferenceCountPtr<State>& state);
};

#endif /* __NOMORE_H__*/
