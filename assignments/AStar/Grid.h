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

	void DrawPath(std::vector<Cell>);

public:

	Grid(unsigned short width, unsigned short height);
	~Grid();
	
	void SetStartPoint(std::vector<unsigned short>* startPoint);
	void SetEndPoint(std::vector<unsigned short>* endPoint);
	void GenerateObstacles(unsigned short count);

	void Draw();
	void FindPath();
	//void CalculateHueristicCosts();
};

