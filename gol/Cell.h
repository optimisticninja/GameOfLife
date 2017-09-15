#pragma once

#include <SDL.h>
#include <vector>

using namespace std;

struct Cell
{
	SDL_Rect rect;
	vector<Cell*> neighbors;
	bool alive;
	int* const x = &this->rect.x;
	int* const y = &this->rect.y;
	bool changed;

	Cell(SDL_Rect rect, bool alive)
	{
		this->rect = rect;
		this->alive = alive;
		this->changed = false;
	}
};