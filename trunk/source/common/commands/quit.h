#ifndef __QUIT_H__
#define __QUIT_H__
#include "command.h"
class Quit: public Command {
	public:
	Quit();
	virtual ~Quit();
	virtual void execute(ReferenceCountPtr<State>& state);

};

#endif /* __QUIT_H__*/
