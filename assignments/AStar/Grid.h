#pragma once
#include <vector>
#include <memory>
#include "Cell.h"

class Grid
{
private:
	unsigned short width;
	unsigned short height;
	std::vector<std::vector<Cell>> grid;

	std::shared_ptr<std::vector<int>> startPoint;
	std::shared_ptr<std::vector<int>> endPoint;

	std::vector<Cell> openList;
	std::vector<Cell> closedList;

	void DrawPath(std::vector<Cell>);

public:

	Grid(unsigned short width, unsigned short height);
	~Grid();
	
	void SetStartPoint(std::shared_ptr<std::vector<int>> startPoint);
	void SetEndPoint(std::shared_ptr<std::vector<int>> endPoint);
	void GenerateObstacles(unsigned short count);

	void Draw();
	void FindPath();
	//void CalculateHueristicCosts();
};

