#include "GameWindow.h"

#include <sstream>
#include <iomanip>

#include "Cell.h"

using namespace std;

GameWindow::GameWindow()
{
	SDL_Init(SDL_INIT_VIDEO);
	this->window = SDL_CreateWindow(
		this->TITLE,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		DEFAULT_WIDTH,
		DEFAULT_HEIGHT,
		0
	);
	this->renderer = SDL_CreateRenderer(
		window,
		-1,
		SDL_RENDERER_ACCELERATED
	);
	SDL_SetRenderDrawColor(this->renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(this->renderer);
}

GameWindow::~GameWindow()
{
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}

void GameWindow::runHandler(Life* life)
{
	SDL_Event event;
	bool quit = false;

	while (!quit) {
		stringstream ss;
		SDL_WaitEvent(&event);
		switch (event.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_MOUSEMOTION:
				ss  << this->TITLE 
					<< " [ X: " << setfill('0') << setw(3) << event.motion.x / CELL_PIXELS
					<< ", Y: "  << setfill('0') << setw(3) << event.motion.y / CELL_PIXELS << " ]";
				SDL_SetWindowTitle(this->window, ss.str().c_str());
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch (event.button.button) {
					case SDL_BUTTON_LEFT:
						SDL_ShowSimpleMessageBox(0, "Mouse", "Left button was pressed!", this->window);
						break;
					case SDL_BUTTON_RIGHT:
						SDL_ShowSimpleMessageBox(0, "Mouse", "Right button was pressed!", this->window);
						break;
					default:
						SDL_ShowSimpleMessageBox(0, "Mouse", "Some other button was pressed!", this->window);
						break;
				}
				break;
			default:
				break;
		}
		renderBoard(life);
	}
}

void GameWindow::flipCell(Cell* cell)
{

}

void GameWindow::renderCell(Cell* cell)
{
	if (cell->alive) {
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	} else {
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	}
	SDL_RenderFillRect(this->renderer, &cell->rect);
	SDL_RenderPresent(this->renderer);
}

void GameWindow::renderBoard(Life* life)
{
	for (vector<Cell*> row : life->getBoard()) {
		for (Cell* cell : row) {
			life->updateCell(cell);
			if (cell->changed == true)
				renderCell(cell);
		}
	}
}
