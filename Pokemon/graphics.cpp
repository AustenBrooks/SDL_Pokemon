#include "graphics.h"
#include <iostream>

graphics::graphics() {
	 windowWidth = 240;
	 windowHeight = 160;

	 SDL_CreateWindowAndRenderer(windowWidth, windowHeight, 0, &window, &renderer);
	 SDL_SetWindowTitle(window, "Default");
}

graphics::graphics(int width, int height) {
	windowWidth = width;
	windowHeight = height;

	SDL_CreateWindowAndRenderer(windowWidth, windowHeight, SDL_WINDOW_RESIZABLE, &window, &renderer);
	SDL_SetWindowTitle(window, "Pokemon");

	SDL_RenderSetLogicalSize(renderer, width, height);
}

graphics::~graphics() {
	SDL_DestroyWindow(window);
}

void graphics::drawFrame(vector<sprite> sprites, sprite map) {
	SDL_RenderClear(renderer);
	renderSprite(map, map.getSpriteX(), map.getSpriteY());

	for (int i = 0; i < sprites.size(); i++) {
		renderSprite(sprites.at(i), sprites.at(i).getSpriteX(), sprites.at(i).getSpriteY());
	}

	SDL_RenderPresent(renderer);
}

void graphics::renderSprite(sprite s, int spriteX, int spriteY) {
	SDL_Rect r;
	r.x = spriteX;
	r.y = spriteY;
	r.w = s.getRectangle().w;
	r.h = s.getRectangle().h;
	
	SDL_RenderCopy(renderer, s.getSpriteSheet(), &r, &s.getRectangle());
}

SDL_Renderer* graphics::getRenderer() {
	return renderer;
}


