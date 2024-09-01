#pragma once
#include <vector>
#include "Cell.h"

class Grid
{
private:
	unsigned short width;
	unsigned short height;
	std::vector<std::vector<Cell>> grid;



	std::vector<Cell> openList;
	std::vector<Cell> closedList;

public:

	Grid(unsigned short width, unsigned short height);
	~Grid();

	void Draw();
};

