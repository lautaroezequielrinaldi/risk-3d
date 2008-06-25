#include "glwidgetmanager.h"

GLWidgetManager GLWidgetManager::singleton;

GLWidgetManager::GLWidgetManager() {
	// No realiza ninguna accion.
}

GLWidgetManager& GLWidgetManager::getInstance() {
	return GLWidgetManager::singleton;
}

