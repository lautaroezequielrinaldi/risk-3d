#include "mouseobservable.h"
#include "mouseobserver.h"

MouseObservable::MouseObservable() {
	// No realiza ninguna accion.
}

void MouseObservable::notifyMouseButtonDownEvent(const SDL_MouseButtonEvent& event) {
	// Obtengo iterador para notificar eventos
	std::list<MouseObserver*>::iterator iter;

	for (iter = observerList.begin(); iter != observerList.end(); ++iter) {
		MouseObserver* actual = *iter;
		actual->mousePressed(event);
	}
}

void MouseObservable::notifyMouseButtonUpEvent(const SDL_MouseButtonEvent& event) {
    // Obtengo iterador para notificar eventos
    std::list<MouseObserver*>::iterator iter;

	for (iter = observerList.begin(); iter != observerList.end(); ++iter) {
		MouseObserver* actual = *iter;
		actual->mouseReleased(event);
    }
}

void MouseObservable::notifyMouseMotionEvent(const SDL_MouseMotionEvent& event) {
    // Obtengo iterador para notificar eventos
    std::list<MouseObserver*>::iterator iter;

	for (iter = observerList.begin(); iter != observerList.end(); ++iter) {
		MouseObserver* actual = *iter;
		actual->mouseMoved(event);
    }
}

void MouseObservable::addMouseObserver(MouseObserver* observer) {
	this->observerList.push_back(observer);
}

void MouseObservable::removeMouseObserver(MouseObserver* observer) {
	this->observerList.remove(observer);
}

MouseObservable::~MouseObservable() {
	// No realiza ninguna accion.
}

