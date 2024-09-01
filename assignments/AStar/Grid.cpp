#include "Grid.h"
#include <iostream>

Grid::Grid(unsigned short width, unsigned short height)
{
	this->width = width;
	this->height = height;

	//grid.resize(height, std::vector<Cell>(width));

	int cellCount = 0;
	for (int i = 0; i < height; ++i)
	{
		grid.push_back(std::vector<Cell>());
		for (int j = 0; j < width; ++j)
		{
			grid[i].push_back(Cell(cellCount));
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
				std::cout << grid[i][j].GetId() << "\t";
			}
		}
	}

	std::cout << "\n\n";
}
