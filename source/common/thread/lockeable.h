#ifndef __LOCKEABLE__
#define __LOCKEABLE__

#include<string> // Para definiciòn de std::string

/*
 * @todo convertir ese private mutex a map<string,Mutex*>
 * @todo convertir getMutex() a getMutex(string)
 * @todo implementar addMutex(), que es llamado desde el constructor de la subclase implementante
 */

#include "mutex.h"
class Lockeable {
        public:
        Lockeable();
        Mutex * getMutex();
	void addMutex(const std::string & name);

        ~Lockeable();

        private:
        Mutex * mutex;
	
};
#endif /* __LOCKEABLE__*/

