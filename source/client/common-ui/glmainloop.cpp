#include "glmainloop.h"

bool GLMainLoop::running = true;

void GLMainLoop::dispatchMouseButtonDownEvent(const SDL_MouseButtonEvent& event) {
    // Obtengo iterador para los widgets 2d registrados
    GLWidgetManager::WidgetIterator2D iterator2D;

	for (iterator2D = GLWidgetManager::first2DWidget(); iterator2D != GLWidgetManager::last2DWidget();
		++iterator2D) {
		ReferenceCountPtr<GL2DWidget> widget = *iterator2D;
		widget->handleMouseButtonDownEvent(event);
    }
}

void GLMainLoop::dispatchMouseButtonUpEvent(const SDL_MouseButtonEvent& event) {
    // Obtengo iterador para los widgets 2d registrados
    GLWidgetManager::WidgetIterator2D iterator2D;

	for (iterator2D = GLWidgetManager::first2DWidget(); iterator2D != GLWidgetManager::last2DWidget();
		++iterator2D) {
		ReferenceCountPtr<GL2DWidget> widget = *iterator2D;
		widget->handleMouseButtonUpEvent(event);
	}
}

void GLMainLoop::dispatchMouseMotionEvent(const SDL_MouseMotionEvent& event) {
    // Obtengo iterador para los widgets 2d registrados
    GLWidgetManager::WidgetIterator2D iterator2D;

	for (iterator2D = GLWidgetManager::first2DWidget(); iterator2D != GLWidgetManager::last2DWidget();
		++iterator2D) {
		ReferenceCountPtr<GL2DWidget> widget = *iterator2D;
		widget->handleMouseMotionEvent(event);
    }
}

void GLMainLoop::dispatchKeyDownEvent(const SDL_KeyboardEvent& event) {

}

void GLMainLoop::dispatchKeyUpEvent(const SDL_KeyboardEvent& event) {

}

void GLMainLoop::renderScene() {
	// Obtengo iterador para los widgets 2d registrados
	GLWidgetManager::WidgetIterator2D iterator2D;

	for (iterator2D = GLWidgetManager::first2DWidget(); iterator2D != GLWidgetManager::last2DWidget();
		++iterator2D) {
		ReferenceCountPtr<GL2DWidget> widget = *iterator2D;
		widget->draw();
	}
	SDL_GL_SwapBuffers();
}

void GLMainLoop::run() {
	// Mientras el loop principal este corriendo.
	while( GLMainLoop::isRunning() ) {
		// Define el evento a escuchar
		SDL_Event event;
		// Procesa todos los eventos pendientes.
		while( SDL_PollEvent(&event) ) {
			// Verifica el tipo de evento.
			switch( event.type ) {
				// En caso de boton de mouse presionado
				case SDL_MOUSEBUTTONDOWN:
					// Despacha el evento.
					GLMainLoop::dispatchMouseButtonDownEvent(event.button);
					break;
				// En caso de boton de mouse liberado
				case SDL_MOUSEBUTTONUP:
					// Despacha el evento.
					GLMainLoop::dispatchMouseButtonUpEvent(event.button);
					break;
				// En caso de movimiento de mouse
				case SDL_MOUSEMOTION:
					// Despacha el evento.
					GLMainLoop::dispatchMouseMotionEvent(event.motion);
					break;
				// En caso de tecla presionada
				case SDL_KEYDOWN:
					// Despacha el evento.
					GLMainLoop::dispatchKeyDownEvent(event.key);
					break;
				// En caso de tecla liberada
				case SDL_KEYUP:
					// Despacha el evento.
					GLMainLoop::dispatchKeyUpEvent(event.key);
					break;
				// En caso de terminar aplicacion
				case SDL_QUIT:
					GLMainLoop::stopRunning();
					break;
			}
		}
		GLMainLoop::renderScene();
	}
}

bool GLMainLoop::isRunning() {
	return GLMainLoop::running;
}

void GLMainLoop::stopRunning() {
	GLMainLoop::running = false;
}

