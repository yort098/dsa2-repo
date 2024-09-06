#pragma once
#include <vector>
#include "Cell.h"

class Grid
{
private:
	unsigned short width;
	unsigned short height;
	std::vector<std::vector<Cell>> grid;

	std::vector<unsigned short>* startPoint;
	std::vector<unsigned short>* endPoint;

	std::vector<Cell> openList;
	std::vector<Cell> closedList;

	void DrawPath();

public:

	Grid(unsigned short width, unsigned short height, std::vector<unsigned short>* startPoint, std::vector<unsigned short>* endPoint);
	~Grid();

	void Draw();
	void FindPath();
	//void CalculateHueristicCosts();
};

