#pragma once
#include <vector>
#include "Cell.h"

class Grid
{
private:
	unsigned short width;
	unsigned short height;
	std::vector<std::vector<Cell>> grid;

	std::vector<int>* startPoint;
	std::vector<int>* endPoint;

public:

	Grid(unsigned short width, unsigned short height, std::vector<int>* startPoint, std::vector<int>* endPoint);
	~Grid();

	void Draw();
	void FindPath(std::vector<unsigned short> start, std::vector<unsigned short> end);
	//void CalculateHueristicCosts();
};

