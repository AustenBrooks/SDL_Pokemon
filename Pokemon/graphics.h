#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <string>
#include "sprite.h"


using std::vector;
using std::string;

class graphics {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	
	int windowWidth;
	int windowHeight;

	vector<SDL_Surface*> spriteSheets;
	vector<string> filePaths;

public:
	graphics();
	graphics(int width, int height);
	~graphics();

	void drawFrame(vector<sprite> sprites, sprite map);
	void renderSprite(sprite s, int spriteX, int spriteY);

	SDL_Renderer* getRenderer();
};


#endif
