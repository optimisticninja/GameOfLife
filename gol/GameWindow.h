#pragma once

#include <SDL.h>
#include <vector>

#include "Life.h"

using namespace std;

const int DEFAULT_WIDTH = 800;
const int DEFAULT_HEIGHT = 600;
const int CELL_PIXELS = 4;
const int X_BEGIN = 0;
const int X_END = DEFAULT_WIDTH / CELL_PIXELS;
const int Y_BEGIN = 0;
const int Y_END = DEFAULT_HEIGHT / CELL_PIXELS;

class GameWindow
{
private:
	const char* TITLE = "Game of Life";

	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	GameWindow();
	~GameWindow();

	void runHandler(Life* life);
	void flipCell(Cell* life);
	void renderCell(Cell* rect);
	void renderBoard(Life* life);
};

