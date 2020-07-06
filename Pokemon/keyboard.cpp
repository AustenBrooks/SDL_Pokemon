#include "keyboard.h"


keyboard::keyboard() {
}


bool keyboard::isKeyPressed(SDL_Scancode key) {
	return keyPressed[key];
}

bool keyboard::isKeyReleased(SDL_Scancode key) {
	return keyReleased[key];
}

bool keyboard::isKeyHeld(SDL_Scancode key) {
	return keyHeld[key];
}

void keyboard::clearKeys() {
	for (int i = 0; i < 284; i++) {
		keyPressed[i] = false;
		keyReleased[i] = false;
	}
}

void keyboard::clearAll() {
	for (int i = 0; i < 284; i++) {
		keyPressed[i] = false;
		keyReleased[i] = false;
		keyHeld[i] = false;
	}
}

void keyboard::pressKey(SDL_Scancode key) {
	keyPressed[key] = true;
	keyHeld[key] = true;
}
void keyboard::releaseKey(SDL_Scancode key) {
	keyReleased[key] = true;
	keyHeld[key] = false;
}

