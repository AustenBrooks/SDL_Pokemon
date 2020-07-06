#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SDL.h>

class keyboard {
private:
	bool keyPressed[284] = { false };
	bool keyReleased[284] = { false };
	bool keyHeld[284] = { false };

public:
	keyboard();

	bool isKeyPressed(SDL_Scancode key);
	bool isKeyReleased(SDL_Scancode key);
	bool isKeyHeld(SDL_Scancode key);
	
	void clearKeys();
	void clearAll();
	void pressKey(SDL_Scancode key);
	void releaseKey(SDL_Scancode key);

	
};




#endif
