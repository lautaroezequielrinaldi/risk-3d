#include "subject.h"
#include "observer.h"

Subject::Subject():
    observerList() {
    // No realiza ninguna acciòn.
}
 
void Subject::registerObserver(Observer* observer) {
    this->observerList.push_back(observer);
}

void Subject::unregisterObserver(Observer* observer) {
    this->observerList.remove(observer);
}

void Subject::notify() {
    // Define iterador de observadores.
    std::list<Observer*>::iterator observerIter;
    // Itera por cada observador.
    for (observerIter = this->observerList.begin();
        observerIter != this->observerList.end(); ++observerIter) {
        // Obtiene observador actual.
        Observer* observer = *observerIter;
        // Notifica observador.
        observer->update(this);
    }
}

Subject::~Subject() {
    // No realiza ninguna acciòn.
}

