#include "Grid.h"
#include <iostream>

Grid::Grid(unsigned short width, unsigned short height, std::vector<int>* startPoint, std::vector<int>* endPoint)
{
	this->width = width;
	this->height = height;
	this->startPoint = startPoint;
	this->endPoint = endPoint;

	int cellCount = 0;
	for (int i = 0; i < height; ++i)
	{
		grid.push_back(std::vector<Cell>());
		for (int j = 0; j < width; ++j)
		{
			grid[i].push_back(Cell(cellCount, 1, 0, std::abs(j - (*endPoint)[0]) + std::abs(i - (*endPoint)[1])));
			cellCount++;
		}
			
	}
}

Grid::~Grid()
{
}

void Grid::Draw()
{
	std::cout << "A* Grid with random obstacles:" << std::endl;

	for (unsigned short i = 0; i < height; ++i)
	{
		for (unsigned short j = 0; j < width; ++j)
		{
			if (grid[i][j].GetId() % width == 0)
			{
				std::cout << "\n";
			}

			if (grid[i][j].isObstacle())
			{
				std::cout << "x\t";
			}
			else
			{
				std::cout << grid[i][j].GetId() << " (h = " << grid[i][j].GetHeuristicCost() << ")\t";
			}
		}
	}

	std::cout << "\n\n";
}

void Grid::FindPath(std::vector<unsigned short> start, std::vector<unsigned short> end)
{
	bool findingPath = true;
	Cell currentCell = grid[(*startPoint)[0]][(*startPoint)[1]];

	std::vector<Cell> openList;
	std::vector<Cell> closedList;

	while (findingPath)
	{

	}
}
