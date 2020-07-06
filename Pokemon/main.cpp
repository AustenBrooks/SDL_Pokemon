#include <SDL.h>
#include "graphics.h"
#include "keyboard.h"
#include "game.h"


#define WIDTH 240*2
#define HEIGHT 160*2

int main(int argc, char* args[]) {

	SDL_Init(SDL_INIT_EVERYTHING);
	graphics newWindow(WIDTH, HEIGHT);
	SDL_Event events;
	keyboard input;

	mainGameLoop(newWindow, events, input);
	
	return 0;
}
