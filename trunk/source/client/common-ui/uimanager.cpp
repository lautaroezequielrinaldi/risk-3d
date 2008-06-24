#include "uimanager.h"
#include "glwidget.h"

UIManager UIManager::singleton;

UIManager::UIManager():
	widgetList(),
	displayManager() {
	// No realiza ninguna accion.
}

UIManager& UIManager::getInstance() {
	return UIManager::singleton;
}

void UIManager::addWidget(const ReferenceCountPtr<GLWidget>& widget) {
	this->widgetList.push_back(widget);
}

void UIManager::removeWidget(const ReferenceCountPtr<GLWidget>& widget) {
	this->widgetList.remove(widget);
}

void UIManager::drawAllWidgets() {
	std::list< ReferenceCountPtr<GLWidget> >::iterator iterator;
	for ( iterator = this->widgetList.begin();
		iterator != this->widgetList.end(); ++iterator) {
		ReferenceCountPtr<GLWidget> widget = *iterator;
		if (widget->getVisible()) {
			widget->draw();
		}
	}
	this->displayManager.updateScreen();
}

DisplayManager& UIManager::getDisplayManager() {
	return this->displayManager;
}

UIManager::~UIManager() {
	// No realiza ninguna accion.
}
