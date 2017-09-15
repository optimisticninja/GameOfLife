#pragma once

#include <vector>

#include "Cell.h"

using namespace std;

class Life
{
private:
	vector<vector<Cell*>> board;
	int x;
	int y;

public:
	Life();
	~Life();
	vector<vector<Cell*>> getBoard();
	void updateCell(Cell* cell);
	void setupNeighbors(int i, int j);
	vector<Cell*> Life::getNeighbors(int x, int y);

};

