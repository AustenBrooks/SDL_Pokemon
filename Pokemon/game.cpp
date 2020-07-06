#include "game.h"

using std::vector;


bool canMoveUp(sprite source, sprite target) {
	if (target.getCollision() == false) {
		return true;
	}
	if (((source.getRectangle().x + source.getRectangle().w) <= target.getRectangle().x) || (source.getRectangle().x >= (target.getRectangle().x + target.getRectangle().w))) {
		return true;
	}
	if (((source.getRectangle().y) <= target.getRectangle().y) || (source.getRectangle().y - 16) >= (target.getRectangle().y + target.getRectangle().h)) {
		return true;
	}
	else {
		return false;
	}
}

bool canMoveDown(sprite source, sprite target) {
	if (target.getCollision() == false) {
		return true;
	}
	if (((source.getRectangle().x + source.getRectangle().w) <= target.getRectangle().x) || (source.getRectangle().x >= (target.getRectangle().x + target.getRectangle().w))) {
		return true;
	}
	if (((source.getRectangle().y + 16) < target.getRectangle().y) || (source.getRectangle().y) >= (target.getRectangle().y + target.getRectangle().h)) {
		return true;
	}
	else {
		return false;
	}
}

bool canMoveLeft(sprite source, sprite target) {
	if (target.getCollision() == false) {
		return true;
	}
	if (((source.getRectangle().x + source.getRectangle().w) <= target.getRectangle().x) || ((source.getRectangle().x - 16) >= (target.getRectangle().x + target.getRectangle().w))) {
		return true;
	}
	if (((source.getRectangle().y) < target.getRectangle().y) || (source.getRectangle().y) >= (target.getRectangle().y + target.getRectangle().h)) {
		return true;
	}
	else {
		return false;
	}
}

bool canMoveRight(sprite source, sprite target) {
	if (((source.getRectangle().x + source.getRectangle().w + 16) <= target.getRectangle().x) || ((source.getRectangle().x) >= (target.getRectangle().x + target.getRectangle().w))) {
		return true;
	}
	if (((source.getRectangle().y) < target.getRectangle().y) || (source.getRectangle().y) >= (target.getRectangle().y + target.getRectangle().h)) {
		return true;
	}
	else {
		return false;
	}
}


void mainGameLoop(graphics& newWindow, SDL_Event& events, keyboard& input) {
	sprite map(0, 0, 384, 320, false, "Sprites/Pallet Town.png", 0, 0);
	sprite player(96, 128+48, 16, 20, true, "Sprites/Hero.png", 16, 0);
	vector<sprite> actors;
	actors.push_back(player);
	sprite leftTrees(0, 0, 32, 320, true, "Sprites/Collision.png", 0, 0);
	sprite topLeftTrees(0, 0, 192, 32, true, "Sprites/Collision.png", 0, 0);
	sprite topRightTrees(224, 0, 160, 32, true, "Sprites/Collision.png", 0, 0);
	sprite rightTrees(352, 0, 32, 320, true, "Sprites/Collision.png", 0, 0);
	sprite bottomRightTrees(288, 320, 96, 32, true, "Sprites/Collision.png", 0, 0);
	sprite bottomLeftTrees(0, 320, 96, 32, true, "Sprites/Collision.png", 0, 0);
	actors.push_back(leftTrees);
	actors.push_back(topLeftTrees);
	actors.push_back(topRightTrees);
	actors.push_back(rightTrees);
	actors.push_back(bottomRightTrees);
	actors.push_back(bottomLeftTrees);
	//sprite target1(160, 64, 16, 20, true, "Sprites/Hero.png", 16, 0);
	//sprite target2(96, 80, 16, 20, true, "Sprites/Hero.png", 16, 0);
	//sprite target3(80, 80, 16, 20, true, "Sprites/Hero.png", 16, 0);
	//sprite target4(16, 96, 16, 20, true, "Sprites/Hero.png", 16, 0);
	//sprite target5(32, 32, 16, 20, true, "Sprites/Hero.png", 16, 0);
	//sprite target6(64, 80, 16, 20, true, "Sprites/Hero.png", 16, 0);
	//sprite target7(128, 96, 16, 20, true, "Sprites/Hero.png", 16, 0);
	//sprite target8(256, 80, 16, 20, true, "Sprites/Hero.png", 16, 0);
	sprite target9(48, 112, 48, 48, true, "Sprites/Hero.png", 16, 0);
	//actors.push_back(target1);
	//actors.push_back(target2);
	//actors.push_back(target3);
	//actors.push_back(target4);
	//actors.push_back(target5);
	//actors.push_back(target6);
	//actors.push_back(target7);
	//actors.push_back(target8);
	//actors.push_back(target9);
	map.createTexture(newWindow.getRenderer());
	
	int playerIndex = 0;

	while (1) {
		int timeStart = SDL_GetTicks();
		int elapsedTime = SDL_GetTicks() - timeStart;
		bool animating = false;
		while (elapsedTime < FRAME_TIME) {
			input.clearKeys();
			SDL_PollEvent(&events);

			if (events.type == SDL_KEYDOWN && events.key.repeat == false) {
				input.pressKey(events.key.keysym.scancode);
			}
			if (events.type == SDL_KEYUP) {
				input.releaseKey(events.key.keysym.scancode);
			}
			if (events.type == SDL_QUIT || input.isKeyPressed(SDL_SCANCODE_ESCAPE)) {
				return;
			}

			if (actors.at(playerIndex).continueAnimation()) {
				input.clearKeys();
				animating = true;
			}
			else if (input.isKeyPressed(SDL_SCANCODE_W) || input.isKeyHeld(SDL_SCANCODE_W)) {
				bool canMove = true;
				if (actors.at(playerIndex).getDirection() != up) {
					canMove = false;
					actors.at(playerIndex).turnUp();
				}
				for (int i = 0; i < actors.size(); i++) {
					if (i == playerIndex);
					else if (canMoveUp(actors.at(playerIndex), actors.at(i)) == false) {
						canMove = false;
					}
				}
				if (canMove) {
					actors.at(playerIndex).walkUp();
				}
			}
			else if (input.isKeyPressed(SDL_SCANCODE_S) || input.isKeyHeld(SDL_SCANCODE_S)) {
				bool canMove = true;
				if (actors.at(playerIndex).getDirection() != down) {
					canMove = false;
					actors.at(playerIndex).turnDown();
				}
				for (int i = 0; i < actors.size(); i++) {
					if (i == playerIndex);
					else if (canMoveDown(actors.at(playerIndex), actors.at(i)) == false) {
						canMove = false;
					}
				}
				if (canMove) {
					actors.at(playerIndex).walkDown();
				}	
			}
			else if (input.isKeyPressed(SDL_SCANCODE_A) || input.isKeyHeld(SDL_SCANCODE_A)) {
				bool canMove = true;
				if (actors.at(playerIndex).getDirection() != left) {
					canMove = false;
					actors.at(playerIndex).turnLeft();
				}
				for (int i = 0; i < actors.size(); i++) {
					if (i == playerIndex);
					else if (canMoveLeft(actors.at(playerIndex), actors.at(i)) == false) {
						canMove = false;
					}
				}
				if (canMove) {
					actors.at(playerIndex).walkLeft();
				}
			}
			else if (input.isKeyPressed(SDL_SCANCODE_D) || input.isKeyHeld(SDL_SCANCODE_D)) {
				bool canMove = true;
				if (actors.at(playerIndex).getDirection() != right) {
					canMove = false;
					actors.at(playerIndex).turnRight();
				}
				for (int i = 0; i < actors.size(); i++) {
					if (i == playerIndex);
					else if (canMoveRight(actors.at(playerIndex), actors.at(i)) == false) {
						canMove = false;
					}
				}
				if (canMove) {
					actors.at(playerIndex).walkRight();
				}
			}
			elapsedTime = SDL_GetTicks() - timeStart;
			if (elapsedTime < FRAME_TIME) {
				SDL_Delay(FRAME_TIME - elapsedTime);
			}
		}
		for (int i = 0; i < actors.size(); i++) {
			if (actors.at(i).getNeedsUpdate()) {
				actors.at(i).createTexture(newWindow.getRenderer());
			}
		}
		

		//create an index order based on Ypos of sprites
		vector<int> spritePosY;
		vector<int> indexOrder;
		for (int i = 0; i < actors.size(); i++) {
			int rectY = actors.at(i).getRectangle().y;
			bool isHigher = false;
			int indexHigher = -1;
			int j;
			for (j = 0; j < spritePosY.size(); j++) {
				if (rectY < spritePosY.at(j)) {
					isHigher = true;
					indexHigher = j;
					break;
				}
			}
			if (isHigher) {
				spritePosY.insert(spritePosY.begin() + j, rectY);
				indexOrder.insert(indexOrder.begin() + j, i);
			}
			else {
				spritePosY.push_back(rectY);
				indexOrder.push_back(i);
			}
		}
		
		//reaarange actors based on indexOrder
		for (int i = 0; i < actors.size(); ++i) {
			while (i != indexOrder.at(i)) {
				int newIndex = indexOrder.at(i);
				sprite temp = actors.at(i);
				actors.at(i) = actors.at(newIndex);
				actors.at(newIndex) = temp;

				indexOrder.at(i) = indexOrder.at(newIndex);
				indexOrder.at(newIndex) = newIndex;

				if (i == playerIndex) {
					playerIndex = newIndex;
				}
				else if (newIndex == playerIndex) {
					playerIndex = i;
				}
			}
		}
		
		/*if (!animating) {
			for (int i = 0; i < actors.size(); ++i) {
				// while the element i is not yet in place 
				while (i != indexOrder[i]) {
					// swap it with the element at its final place

					int alt = indexOrder[i];
					std::swap(actors[i], actors[alt]);
					std::swap(indexOrder[i], indexOrder[alt]);
					if (i == playerIndex) {
						playerIndex = alt;
					}
					else if (alt == playerIndex) {
						playerIndex = i;
					}
				}
			}
		}*/
		newWindow.drawFrame(actors, map);
	}
}