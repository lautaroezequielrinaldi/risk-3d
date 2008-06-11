#ifndef __STATE_H__
#define __STATE_H__

#include <string>
/**
 *
 * 
 */
class State {
	public:
	State();
	virtual ~State();
	virtual State * getNext()=0;
	std::string getName();

	private:
	std::string name;

};
#endif /** __STATE_H__ */
