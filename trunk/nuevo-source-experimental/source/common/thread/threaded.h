#ifndef __THREADED__
#define __THREADED__

/**
 * TP3 - 2008.1
 * Taller de programación - 7542
 * @author dado en clase martes
 */

#include <pthread.h>

class Threaded {
	
	public:
		
		Threaded();
		
		
		virtual ~Threaded(){};
	
		int start();
	
		void * join();
		
		void kill();

	protected:
	
		virtual void * run()=0;
		
		int last_error;

	private:
	
		pthread_t thread;
	
		static void * start_routine(void * arg);
	
		Threaded(const Threaded&);
	
		Threaded& operator=(const Threaded&);
};
#endif /* __THREADED__*/
