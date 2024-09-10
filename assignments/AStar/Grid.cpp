#include "Grid.h"
#include <iostream>
#include <windows.h>

Grid::Grid(unsigned short width, unsigned short height)
{
	this->width = width;
	this->height = height;
	this->startPoint = startPoint;
	this->endPoint = endPoint;

	int cellCount = 0;
	for (int y = 0; y < height; ++y)
	{
		grid.push_back(std::vector<Cell>());
		for (int x = 0; x < width; ++x)
		{
			grid[y].push_back(Cell(cellCount, x, y, (std::rand() % 10) + 1, 0));
			cellCount++;
		}
			
	}

}

Grid::~Grid()
{
}

void Grid::SetStartPoint(std::shared_ptr<std::vector<int>> startPoint)
{
	this->startPoint = startPoint;
	grid[(*startPoint)[1]][(*startPoint)[0]].cellType = Start;
}

void Grid::SetEndPoint(std::shared_ptr<std::vector<int>> endPoint)
{
	this->endPoint = endPoint;
	grid[(*endPoint)[1]][(*endPoint)[1]].cellType = End;

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			grid[y][x].SetH(std::abs(x - (*endPoint)[0]) + std::abs(y - (*endPoint)[1]));
		}

	}
}

void Grid::GenerateObstacles(unsigned short count)
{
	//srand(NULL);
	for (unsigned int i = 0; i < count; ++i)
	{
		Cell* randomCell = &(grid[std::rand() % height][std::rand() % width]);

		// Making sure the wall goes in an available spot
		while ((*randomCell).cellType != Empty)
		{
			randomCell = &(grid[std::rand() % height][std::rand() % width]);
		}

		(*randomCell).cellType = Obstacle;
	}
}

void Grid::Draw()
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	
	std::cout << "\nKey: 'S' = start 'E' = end 'x' = closed list 'o' = open list '.' = unchecked cell '#' = wall" << std::endl;

	for (unsigned short y = 0; y < height; ++y)
	{
		for (unsigned short x = 0; x < width; ++x)
		{

			if (grid[y][x].GetId() % width == 0)
			{
				std::cout << std::endl;
			}

			if (grid[y][x].cellType == Obstacle)
			{
				std::cout << "#\t";
			}
			else if (grid[y][x].cellType == Start)
			{
				SetConsoleTextAttribute(console_color, 2);
				std::cout << "S\t";
			}
			else if (grid[y][x].cellType == End)
			{
				SetConsoleTextAttribute(console_color, 12);
				std::cout << "E\t";
			}
			else if (unsigned short count = std::count(closedList.begin(), closedList.end(), grid[y][x]) > 0)
			{
				std::cout << "x\t";
			}
			else if (unsigned short count = std::count(openList.begin(), openList.end(), grid[y][x]) > 0)
			{
				std::cout << "o\t";
			}
			else
			{
				std::cout << ".\t";
			}

			SetConsoleTextAttribute(console_color, 7);
		}
	}

	std::cout << "\n\n";
}

void Grid::DrawPath(std::vector<Cell> path)
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);

	for (unsigned short y = 0; y < height; ++y)
	{
		for (unsigned short x = 0; x < width; ++x)
		{

			if (grid[y][x].GetId() % width == 0)
			{
				std::cout << std::endl;
			}


			if (grid[y][x].cellType == Start)
			{
				SetConsoleTextAttribute(console_color, 2);
				std::cout << "S\t";
			}
			else if (grid[y][x].cellType == End)
			{
				SetConsoleTextAttribute(console_color, 12);
				std::cout << "E\t";
			}
			else if (unsigned short count = std::count(path.begin(), path.end(), grid[y][x]) > 0)
			{
				SetConsoleTextAttribute(console_color, 14);
				std::cout << "x\t";
			}
			else
			{
				std::cout << " \t";
			}

			SetConsoleTextAttribute(console_color, 7);
		}
	}

	std::cout << "\n\n";
}

void Grid::FindPath()
{
	bool findingPath = true;
	Cell currentCell = grid[(*startPoint)[1]][(*startPoint)[0]];

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
				if ((x == currentCell.x && y == currentCell.y) || grid[y][x].cellType == Obstacle)
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
				if (grid[y][x].cellType == End)
				{
					findingPath = false;
					std::cout << "End found!" << std::endl;
					grid[y][x].SetParent(new Cell(currentCell));
					closedList.push_back(grid[y][x]);

					std::vector<Cell> path;
					currentCell = grid[y][x];

					while (currentCell.cellType != Start)
					{
						path.push_back(*(currentCell.GetParent()));
						currentCell = *(currentCell.GetParent());
					}
					
					DrawPath(path);
					return;
				}

				grid[y][x].SetParent(new Cell(currentCell));
				grid[y][x].SetG(currentCell.GetG() + grid[y][x].GetW());
				grid[y][x].SetF(grid[y][x].GetG() + grid[y][x].GetH());
				openList.push_back(grid[y][x]);
			}
		}

		if (openList.size() > 0)
		{
			Draw();
			
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
