#include "glwidgetmanager.h"

std::list< ReferenceCountPtr<GL3DWidget> > GLWidgetManager::widgetList3D;
std::list< ReferenceCountPtr<GL2DWidget> > GLWidgetManager::widgetList2D;

void GLWidgetManager::register2DWidget(const ReferenceCountPtr<GL2DWidget>& widget) {
	GLWidgetManager::widgetList2D.push_back(widget);
}

void GLWidgetManager::unregister2DWidget(const ReferenceCountPtr<GL2DWidget>& widget) {
	GLWidgetManager::widgetList2D.remove(widget);
}

void GLWidgetManager::register3DWidget(const ReferenceCountPtr<GL3DWidget>& widget) {
	GLWidgetManager::widgetList3D.push_back(widget);
}

void GLWidgetManager::unregister3DWidget(const ReferenceCountPtr<GL3DWidget>& widget) {
	GLWidgetManager::widgetList3D.remove(widget);
}

GLWidgetManager::WidgetIterator2D GLWidgetManager::first2DWidget() {
	return GLWidgetManager::widgetList2D.begin();
}

GLWidgetManager::WidgetIterator2D GLWidgetManager::last2DWidget() {
	return GLWidgetManager::widgetList2D.end();
}

GLWidgetManager::WidgetIterator3D GLWidgetManager::first3DWidget() {
	return GLWidgetManager::widgetList3D.begin();
}

GLWidgetManager::WidgetIterator3D GLWidgetManager::last3DWidget() {
	return GLWidgetManager::widgetList3D.end();
}

