#include "sprite.h"

sprite::sprite() {
	r.x = 0;
	r.y = 0;
	r.w = 16;
	r.h = 16;
	hasCollision = true;
	filepath = "";
	spriteX = 16;
	spriteY = 0;
	currentAnimation = none;
	direction = down;
	animationFrame = 0;
	doesSpriteNeedUpdate = false;
}

sprite::sprite(int x, int y, int w, int h, bool hasCollision, string filename, int spriteSheetX, int spriteSheetY) {
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	this->hasCollision = hasCollision;
	filepath = filename;
	spriteX = spriteSheetX;
	spriteY = spriteSheetY;
	currentAnimation = none;
	direction = down;
	animationFrame = 0;
	doesSpriteNeedUpdate = true;
	loadedSprite = IMG_Load(filepath.c_str());
}

sprite::~sprite() {
	
}

void sprite::walkUp() {
	currentAnimation = walkingUp;
	r.y -= 1;
	spriteY = 0;
	if (animationFrame < 8) {
		spriteX = 48;
	}
	else if (animationFrame < 16) {
		spriteX = 64;
	}
	else if (animationFrame < 24) {
		spriteX = 80;
	}
	else if (animationFrame < 32) {
		spriteX = 64;
	}
	++animationFrame;
	if (animationFrame == 16) {
		currentAnimation = none;
	}
	if (animationFrame > 31) {
		currentAnimation = none;
		animationFrame = 0;
	}
}

void sprite::walkDown() {
	currentAnimation = walkingDown;
	r.y += 1;
	spriteY = 0;
	if (animationFrame < 8) {
		spriteX = 0;
	}
	else if (animationFrame < 16) {
		spriteX = 16;
	}
	else if (animationFrame < 24) {
		spriteX = 32;
	}
	else if (animationFrame < 32) {
		spriteX = 16;
	}
	++animationFrame;
	if (animationFrame == 16) {
		currentAnimation = none;
	}
	if (animationFrame > 31) {
		currentAnimation = none;
		animationFrame = 0;
	}
}

void sprite::walkLeft() {
	currentAnimation = walkingLeft;
	r.x -= 1;
	spriteY = 20;
	if (animationFrame < 8) {
		spriteX = 0;
	}
	else if (animationFrame < 16) {
		spriteX = 16;
	}
	else if (animationFrame < 24) {
		spriteX = 32;
	}
	else if (animationFrame < 32) {
		spriteX = 16;
	}
	++animationFrame;
	if (animationFrame == 16) {
		currentAnimation = none;
	}
	if (animationFrame > 31) {
		currentAnimation = none;
		animationFrame = 0;
	}
}

void sprite::walkRight() {
	currentAnimation = walkingRight;
	r.x += 1;
	spriteY = 20;
	if (animationFrame < 8) {
		spriteX = 48;
	}
	else if (animationFrame < 16) {
		spriteX = 64;
	}
	else if (animationFrame < 24) {
		spriteX = 80;
	}
	else if (animationFrame < 32) {
		spriteX = 64;
	}
	++animationFrame;
	if (animationFrame == 16) {
		currentAnimation = none;
	}
	if (animationFrame > 31) {
		animationFrame = 0;
		currentAnimation = none;
	}
}

void sprite::turnUp() {
	spriteX = 64;
	spriteY = 0;
	direction = up;
}

void sprite::turnDown() {
	spriteX = 16;
	spriteY = 0;
	direction = down;
}

void sprite::turnLeft() {
	spriteX = 16;
	spriteY = 20;
	direction = left;
}

void sprite::turnRight() {
	spriteX = 64;
	spriteY = 20;
	direction = right;
}

bool sprite::continueAnimation() {
	if (currentAnimation == none) {
		return false;
	}
	else if (currentAnimation == walkingUp) {
		walkUp();
	}
	else if (currentAnimation == walkingDown) {
		walkDown();
	}
	else if (currentAnimation == walkingLeft) {
		walkLeft();
	}
	else if (currentAnimation == walkingRight) {
		walkRight();
	}
	return true;
}

void sprite::createTexture(SDL_Renderer* renderer) {
	SDL_Texture* spriteSheet = SDL_CreateTextureFromSurface(renderer, loadedSprite);
	this->spriteSheet = spriteSheet;
	doesSpriteNeedUpdate = false;
}

SDL_Rect sprite::getRectangle() {
	return r;
}

bool sprite::getCollision() {
	return hasCollision;
}

string sprite::getFilePath() {
	return filepath;
}

int sprite::getSpriteX() {
	return spriteX;
}

int sprite::getSpriteY() {
	return spriteY;
}

SDL_Texture* sprite::getSpriteSheet() {
	return spriteSheet;
}

bool sprite::getNeedsUpdate() {
	return doesSpriteNeedUpdate;
}

facing sprite::getDirection() {
	return direction;
}

void sprite::setSpriteSheet(SDL_Texture* spriteSheet) {
	this->spriteSheet = spriteSheet;
}

