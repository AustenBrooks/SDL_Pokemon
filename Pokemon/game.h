#ifndef GAME_H
#define GAME_H

#define FPS 60
#define FRAME_TIME (float)(1000 / FPS)

#include <SDL.h>
#include <vector>
#include "keyboard.h"
#include "graphics.h"

bool canMoveUp(sprite source, sprite target);

bool canMoveDown(sprite source, sprite target);

bool canMoveRight(sprite source, sprite target);

bool canMoveLeft(sprite source, sprite target);

void mainGameLoop(graphics& newWindow, SDL_Event& events, keyboard& input);

#endif