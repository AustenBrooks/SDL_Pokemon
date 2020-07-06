#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

using std::string;

enum animation {none,
				walkingUp, walkingDown, walkingLeft, walkingRight,
				runningUp, runningDown, runningLeft, runningRight};

enum facing {up, down, left, right};

class sprite {
private:
	SDL_Rect r;

	bool hasCollision;

	string filepath;

	int spriteX;
	int spriteY;

	int animationFrame;

	animation currentAnimation;
	facing direction;

	SDL_Surface* loadedSprite;
	SDL_Texture* spriteSheet;
	
	bool doesSpriteNeedUpdate;

public:

	sprite();
	sprite(int x, int y, int w, int h, bool hasCollision, string filename, int spriteSheetX, int spriteSheetY);
	~sprite();

	void walkUp();
	void walkDown();
	void walkLeft();
	void walkRight();

	void turnUp();
	void turnDown();
	void turnLeft();
	void turnRight();

	bool continueAnimation();

	void createTexture(SDL_Renderer* renderer);

	SDL_Rect getRectangle();
	bool getCollision();
	string getFilePath();
	int getSpriteX();
	int getSpriteY();
	SDL_Texture* getSpriteSheet();
	bool getNeedsUpdate();
	facing getDirection();

	void setSpriteSheet(SDL_Texture* spriteSheet);
};


#endif
