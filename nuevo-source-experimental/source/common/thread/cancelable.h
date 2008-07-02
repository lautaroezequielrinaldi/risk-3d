#ifndef __CANCELABLE__
#define __CANCELABLE__
/**
 * TP4 - 2008.1
 * Taller de programación - 7542
 * @author Carlos Pantelides 74901
 */
#include "lockeable.h"
class Cancelable: public Lockeable {
	public:
	Cancelable();
	virtual void cancel();
	bool isCanceled();
	virtual ~Cancelable();

	private:
	bool canceled;
};
#endif /* __CANCELABLE__*/
