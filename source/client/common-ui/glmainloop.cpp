#include "glmainloop.h"
#include<iostream>
bool GLMainLoop::running = true;

void GLMainLoop::dispatchMouseButtonDownEvent(const SDL_MouseButtonEvent& event) {
    // Obtengo iterador para los widgets 2d registrados
    GLWidgetManager::WidgetIterator2D iterator2D;

	for (iterator2D = GLWidgetManager::first2DWidget(); iterator2D != GLWidgetManager::last2DWidget();
		++iterator2D) {
		ReferenceCountPtr<GL2DWidget> widget = *iterator2D;
		widget->handleMouseButtonDownEvent(event);
    }

   // Obtengo iterador para los widgets 3d registrados
   GLWidgetManager::WidgetIterator3D iterator3D;

	for (iterator3D = GLWidgetManager::first3DWidget(); iterator3D != GLWidgetManager::last3DWidget();
		++iterator3D) {
		ReferenceCountPtr<GL3DWidget> widget = *iterator3D;
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

   // Obtengo iterador para los widgets 3d registrados
   GLWidgetManager::WidgetIterator3D iterator3D;

   for (iterator3D = GLWidgetManager::first3DWidget(); iterator3D != GLWidgetManager::last3DWidget();
		++iterator3D) {
        ReferenceCountPtr<GL3DWidget> widget = *iterator3D;
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

   // Obtengo iterador para los widgets 3d registrados
   GLWidgetManager::WidgetIterator3D iterator3D;

   for (iterator3D = GLWidgetManager::first3DWidget(); iterator3D != GLWidgetManager::last3DWidget();
		++iterator3D) {
        ReferenceCountPtr<GL3DWidget> widget = *iterator3D;
		widget->handleMouseMotionEvent(event);
	}
}

void GLMainLoop::dispatchKeyDownEvent(const SDL_KeyboardEvent& event) {
	// Obtengo iterador para los widgets 2d registrados
    GLWidgetManager::WidgetIterator2D iterator2D;

    for (iterator2D = GLWidgetManager::first2DWidget(); iterator2D != GLWidgetManager::last2DWidget();
        ++iterator2D) {
        ReferenceCountPtr<GL2DWidget> widget = *iterator2D;
		std::cout << "Enviando key down a widget 2d" << std::endl;
        widget->handleKeyDownEvent(event);
    }

	// Obtengo iterador para los widgets 3d registgrados.
	GLWidgetManager::WidgetIterator3D iterator3D;

	for (iterator3D = GLWidgetManager::first3DWidget(); iterator3D != GLWidgetManager::last3DWidget();
        ++iterator3D) {
        ReferenceCountPtr<GL3DWidget> widget = *iterator3D;
        std::cout << "Enviando key down a widget 3d" << std::endl;
        widget->handleKeyDownEvent(event);
    }
}

void GLMainLoop::dispatchKeyUpEvent(const SDL_KeyboardEvent& event) {
	// Obtengo iterador para los widgets 2d registrados
    GLWidgetManager::WidgetIterator2D iterator2D;

    for (iterator2D = GLWidgetManager::first2DWidget(); iterator2D != GLWidgetManager::last2DWidget();
        ++iterator2D) {
        ReferenceCountPtr<GL2DWidget> widget = *iterator2D;
        std::cout << "Enviando key up a widget 2d" << std::endl;
        widget->handleKeyUpEvent(event);
    }

    // Obtengo iterador para los widgets 3d registgrados.
    GLWidgetManager::WidgetIterator3D iterator3D;

	for (iterator3D = GLWidgetManager::first3DWidget(); iterator3D != GLWidgetManager::last3DWidget();
		++iterator3D) {
		ReferenceCountPtr<GL3DWidget> widget = *iterator3D;
        std::cout << "Enviando key up a widget 3d" << std::endl;
		widget->handleKeyUpEvent(event);
	}
}

void GLMainLoop::updateScene() {
    // Obtengo iterador para los widgets 3d registrados
    GLWidgetManager::WidgetIterator3D iterator3D;

	for (iterator3D = GLWidgetManager::first3DWidget(); iterator3D != GLWidgetManager::last3DWidget();
		++iterator3D) {
		ReferenceCountPtr<GL3DWidget> widget = *iterator3D;
		widget->update();
    }

	// Obtengo iterador para los widgets 2d registrados
    GLWidgetManager::WidgetIterator2D iterator2D;

	for (iterator2D = GLWidgetManager::first2DWidget(); iterator2D != GLWidgetManager::last2DWidget();
		++iterator2D) {
		ReferenceCountPtr<GL2DWidget> widget = *iterator2D;
		widget->update();
	}                                                                             
}

void GLMainLoop::renderScene() {
	// Obtengo iterador para los widgets 3d registrados
	GLWidgetManager::WidgetIterator3D iterator3D;

	for (iterator3D = GLWidgetManager::first3DWidget(); iterator3D != GLWidgetManager::last3DWidget();
		++iterator3D) {
        ReferenceCountPtr<GL3DWidget> widget = *iterator3D;
		widget->update();
        widget->draw();
	}	
   
	// Obtengo iterador para los widgets 2d registrados
	GLWidgetManager::WidgetIterator2D iterator2D;

	for (iterator2D = GLWidgetManager::first2DWidget(); iterator2D != GLWidgetManager::last2DWidget();
		++iterator2D) {
		ReferenceCountPtr<GL2DWidget> widget = *iterator2D;
		widget->update();
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
		if( SDL_PollEvent(&event) ) {
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
					// Establezco la tecla como presionada.
					GLKeyManager::pressKey(event.key.keysym.sym);
					// Despacha el evento.
					GLMainLoop::dispatchKeyDownEvent(event.key);
					break;
				// En caso de tecla liberada
				case SDL_KEYUP:
					// Establezco la tecla como liberada.
					GLKeyManager::releaseKey(event.key.keysym.sym);
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

