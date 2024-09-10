#pragma once
#include <vector>
#include <memory>
#include <windows.h>
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

	HANDLE console_color;

	void DrawPath(std::vector<Cell>);

public:

	Grid(unsigned short width, unsigned short height);
	
	void SetStartPoint(std::shared_ptr<std::vector<int>> startPoint);
	void SetEndPoint(std::shared_ptr<std::vector<int>> endPoint);
	void GenerateObstacles(unsigned short count);

	void Draw();
	void FindPath();
};

