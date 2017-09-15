#include "Life.h"

#include <algorithm>
#include <cstdlib>
#include <vector>

#include "GameWindow.h"

using namespace std;

Life::Life()
{
	for (int row = 0; row < Y_END; row++) {
		vector<Cell*> boardRow;

		for (int column = 0; column < X_END; column++) {
			boardRow.push_back(
				new Cell({
					column * CELL_PIXELS,
					row * CELL_PIXELS,
					CELL_PIXELS,
					CELL_PIXELS
				},
					rand() % 2)
			);
		}
		this->board.push_back(boardRow);
	}

	for (int i = 0; i < Y_END; i++) {
		for (int j = 0; j < X_END; j++) {
			setupNeighbors(i, j);
		}
	}
}

Life::~Life()
{
	for (vector<Cell*> row : this->board)
		for (Cell* cell : row)
			delete cell;
}

vector<vector<Cell*>> Life::getBoard()
{
	return this->board;
}

void Life::updateCell(Cell* cell)
{
	bool initial = cell->alive;
	int live = 0;

	for (Cell* neighbor : cell->neighbors) {
		if (neighbor->alive)
			live += 1;
	}

	if (cell->alive) {
		if (live < 2 || live >= 3)
			cell->alive = false;
		if (live == 2 || live == 3)
			;
	} else {
		if (live == 3)
			cell->alive = true;
	}

	if (cell->alive != initial)
		cell->changed = true;
}

void Life::setupNeighbors(int i, int j)
{
	int rowLimit = Y_END - 1;
	int columnLimit = X_END - 1;

	for (int x = max(0, i - 1); x <= min(i + 1, rowLimit); x++) {
		for (int y = max(0, j - 1); y <= min(j + 1, columnLimit); y++) {
			if (x != i || y != j) {
				this->board[i][j]->neighbors.push_back(this->board[x][y]);
			}
		}
	}
}