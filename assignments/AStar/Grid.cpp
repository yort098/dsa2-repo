#include "Grid.h"
#include <iostream>
#include <windows.h>

Grid::Grid(unsigned short width, unsigned short height, std::vector<unsigned short>* startPoint, std::vector<unsigned short>* endPoint)
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
			grid[i].push_back(Cell(cellCount, j, i, (std::rand() % 10) + 1, 0, std::abs(j - (*endPoint)[0]) + std::abs(i - (*endPoint)[1])));
			cellCount++;
		}
			
	}
}

Grid::~Grid()
{

}

void Grid::Draw()
{
	//HANDLE console_color;
	//console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(console_color, 2);

	//std::cout << "A* Grid with random obstacles:" << std::endl;

	for (unsigned short i = 0; i < height; ++i)
	{
		for (unsigned short j = 0; j < width; ++j)
		{

			if (grid[j][j].GetId() % width == 0)
			{
				std::cout << std::endl;
			}

			if (grid[i][j].isObstacle())
			{
				std::cout << "x\t";
			}
			else if (grid[i][j].x == (*startPoint)[1] && grid[i][j].y == (*startPoint)[0])
			{
				std::cout << "S\t";
				//std::cout << 
				//	"(h = " << grid[i][j].GetH() <<
				//	", w = " << grid[i][j].GetW() << 
				//	", g = " << grid[i][j].GetG() <<
				//	", f = " << grid[i][j].GetF() <<
				//	")\t";
			}
			else if (grid[i][j].x == (*endPoint)[1] && grid[i][j].y == (*endPoint)[0])
			{
				std::cout << "E\t";
			}
			else if (unsigned short count = std::count(closedList.begin(), closedList.end(), grid[j][i]) > 0)
			{
				std::cout << "x\t";
			}
			else if (unsigned short count = std::count(openList.begin(), openList.end(), grid[j][i]) > 0)
			{
				std::cout << "o\t";
			}
			else
			{
				std::cout << ".\t";
			}
		}
	}

	std::cout << "\n\n";
}

void Grid::DrawPath()
{
}

void Grid::FindPath()
{
	bool findingPath = true;
	Cell currentCell = grid[(*startPoint)[0]][(*startPoint)[1]];

	closedList.push_back(currentCell);

	while (findingPath)
	{
		for (int y = currentCell.y - 1; y <= currentCell.y + 1; ++y)
		{
			for (int x = currentCell.x - 1; x <= currentCell.x + 1; ++x)
			{
				// If the cell is out of bounds, skips over it
				if (x < 0 || x > width - 1 || y < 0 || y > height - 1)
				{
					continue;
				}

				// Skipping diagonal checks
				if ((x == currentCell.x - 1 && y == currentCell.y - 1) ||
					(x == currentCell.x - 1 && y == currentCell.y + 1) ||
					(x == currentCell.x + 1 && y == currentCell.y - 1) ||
					(x == currentCell.x + 1 && y == currentCell.y + 1))
				{
					continue;
				}

				// If the cell is the current one, or an obstacle, then skips over it
				if ((x == currentCell.x && y == currentCell.y) || grid[y][x].isObstacle())
				{
					continue;
				}


				// Skipping cells on the closed list already, or a parent to the current cell
				unsigned short count = std::count(closedList.begin(), closedList.end(), grid[y][x]);
				if (count > 0)
				{
					continue;
				}

				if (currentCell.GetParent())
					if ((x == currentCell.GetParent()->x && y == currentCell.GetParent()->y))
					{
						continue;
					}

				// Found the target location!
				if (x == (*endPoint)[0] && y == (*endPoint)[1])
				{
					findingPath = false;
					std::cout << "End found!" << std::endl;

					break;
				}

				grid[y][x].SetParent(&currentCell);
				grid[y][x].SetG(currentCell.GetG() + grid[y][x].GetW());
				grid[y][x].SetF(grid[y][x].GetG() + grid[y][x].GetH());
				openList.push_back(grid[y][x]);
			}
		}

		if (openList.size() > 0)
		{
			if (findingPath)
			{
				Draw();
			}
			else
			{
				DrawPath();
			}
			

			unsigned short shortestPath = openList[0].GetF();
			unsigned short shortestPathIndex = 0;

			for (unsigned short i = 1; i < openList.size(); ++i)
			{
				if (openList[i].GetF() < shortestPath)
				{
					shortestPath = openList[i].GetF();
					shortestPathIndex = i;
				}
			} 

			currentCell = openList[shortestPathIndex];
			closedList.push_back(currentCell);
			openList.erase(openList.begin() + shortestPathIndex);
		}
		else
		{
			std::cout << "Path not found!" << std::endl;
			findingPath = false;
		}

		
	}
}
