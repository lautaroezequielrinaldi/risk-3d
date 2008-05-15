#include "Lockeable.h"
/*
 * @todo adaptar segun lockeable.h
 *
 *
 *
 */
Lockeable::Lockeable(){
        mutex = new Mutex();
}

Mutex * Lockeable::getMutex(){
        return mutex;
}

Lockeable::~Lockeable(){
        delete(mutex);
}

