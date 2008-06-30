#include "glkeymanager.h"

bool GLKeyManager::keyboard[SDLK_LAST];

void GLKeyManager::pressKey(const SDLKey& key) {
	GLKeyManager::keyboard[key] = true;
}

void GLKeyManager::releaseKey(const SDLKey& key) {
	GLKeyManager::keyboard[key] = false;
}

bool GLKeyManager::isKeyPressed(const SDLKey& key) {
	return GLKeyManager::keyboard[key];
}

