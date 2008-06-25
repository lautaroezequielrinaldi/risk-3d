#include "glwidgetmanager.h"

std::list< ReferenceCountPtr<GL2DWidget> > GLWidgetManager::widgetList2D;

void GLWidgetManager::registerWidget(const ReferenceCountPtr<GL2DWidget>& widget) {
	GLWidgetManager::widgetList2D.push_back(widget);
}

void GLWidgetManager::unregisterWidget(const ReferenceCountPtr<GL2DWidget>& widget) {
	GLWidgetManager::widgetList2D.remove(widget);
}

GLWidgetManager::WidgetIterator2D GLWidgetManager::first2DWidget() {
	return GLWidgetManager::widgetList2D.begin();
}

GLWidgetManager::WidgetIterator2D GLWidgetManager::last2DWidget() {
	return GLWidgetManager::widgetList2D.end();
}

