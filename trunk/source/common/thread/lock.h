#ifndef __LOCK__
#define __LOCK__
/**
 * TP3 - 2008.1
 * Taller de programación - 7542
 * @author Carlos Pantelides 74901
 */
#include "mutex.h"

class Lock {
	public:
	Lock(Mutex &mutex);
	~Lock();

	private:
	Mutex & mutex;
	Lock(const Lock&);
	Lock& operator=(const Lock&);
};

#endif /* __LOCK__*/
