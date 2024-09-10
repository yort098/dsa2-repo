#include "Grid.h"
#include <iostream>

/// <summary>
/// Initializes the data of the grid
/// </summary>
/// <param name="width">The width of the grid</param>
/// <param name="height">The height of the grid</param>
Grid::Grid(unsigned short width, unsigned short height)
{
	this->width = width;
	this->height = height;
	this->startPoint = startPoint;
	this->endPoint = endPoint;

	console_color = GetStdHandle(STD_OUTPUT_HANDLE);

	int cellCount = 0; // Used for each cell's id
	for (int y = 0; y < height; ++y)
	{
		grid.push_back(std::vector<Cell>()); // Creates an array for each row
		for (int x = 0; x < width; ++x)
		{
			grid[y].push_back(Cell(cellCount, x, y));
			cellCount++;
		}
	}
}

/// <summary>
/// Sets the start point of the grid
/// </summary>
/// <param name="startPoint">A pointer to a start point</param>
void Grid::SetStartPoint(std::shared_ptr<std::vector<int>> startPoint)
{
	this->startPoint = startPoint;
	grid[(*startPoint)[1]][(*startPoint)[0]].cellType = Start;
}

/// <summary>
/// Sets the end point of the grid
/// </summary>
/// <param name="endPoint">A pointer to an end point</param>
void Grid::SetEndPoint(std::shared_ptr<std::vector<int>> endPoint)
{
	this->endPoint = endPoint;
	grid[(*endPoint)[1]][(*endPoint)[1]].cellType = End;

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			// Sets the heuristic cost using the "Manhattan Distance" formula
			// (no diagonals)
			grid[y][x].SetH(std::abs(x - (*endPoint)[0]) + std::abs(y - (*endPoint)[1]));
		}

	}
}

/// <summary>
/// Randomly places walls on the grid
/// </summary>
/// <param name="count">The number of obstacles to add</param>
void Grid::GenerateObstacles(unsigned short count)
{
	Cell* randomCell;
	for (unsigned int i = 0; i < count; ++i)
	{
		// Making sure the wall goes in an available spot
		do 
		{
			randomCell = &(grid[std::rand() % height][std::rand() % width]);
		} while ((*randomCell).cellType != Empty);

		(*randomCell).cellType = Wall;
	}
}

/// <summary>
/// Draws a representation of the grid in the console
/// </summary>
void Grid::Draw()
{
	std::cout << "\nKey: 'S' = start 'E' = end 'x' = closed list 'o' = open list '.' = unchecked cell '#' = wall" << std::endl;

	for (unsigned short y = 0; y < height; ++y)
	{
		for (unsigned short x = 0; x < width; ++x)
		{
			// Adding line breaks
			if (grid[y][x].id % width == 0)
			{
				std::cout << std::endl;
			}

			if (grid[y][x].cellType == Wall)
			{
				std::cout << "#\t";
			}
			else if (grid[y][x].cellType == Start)
			{
				SetConsoleTextAttribute(console_color, 2); // green
				std::cout << "S\t";
			}
			else if (grid[y][x].cellType == End)
			{
				SetConsoleTextAttribute(console_color, 12); // red
				std::cout << "E\t";
			}
			// Finds out whether or not the element exists in the closed list
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

			SetConsoleTextAttribute(console_color, 7); // Resetting the console color
		}
	}

	std::cout << "\n\n"; // Formatting
}

/// <summary>
/// Draws the final path between the start and end points
/// </summary>
/// <param name="path">The finalized path the was found</param>
void Grid::DrawPath(std::vector<Cell> path)
{
	for (unsigned short y = 0; y < height; ++y)
	{
		for (unsigned short x = 0; x < width; ++x)
		{

			if (grid[y][x].id % width == 0)
			{
				std::cout << std::endl;
			}

			if (grid[y][x].cellType == Start)
			{
				SetConsoleTextAttribute(console_color, 2); // green
				std::cout << "S\t";
			}
			else if (grid[y][x].cellType == End)
			{
				SetConsoleTextAttribute(console_color, 12); // red
				std::cout << "E\t";
			}
			// Only drawing the path cells, and nothing else
			else if (unsigned short count = std::count(path.begin(), path.end(), grid[y][x]) > 0)
			{
				SetConsoleTextAttribute(console_color, 14);
				std::cout << "x\t";
			}
			else
			{
				std::cout << " \t";
			}

			SetConsoleTextAttribute(console_color, 7); // Resetting the console color
		}
	}

	std::cout << "\n\n"; // Formatting
}

/// <summary>
/// If possible, finds the shortest path between start and end points on the grid
/// </summary>
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
				if ((x == currentCell.x && y == currentCell.y) || grid[y][x].cellType == Wall)
				{
					continue;
				}


				// Skipping cells on the closed list already
				unsigned short count = std::count(closedList.begin(), closedList.end(), grid[y][x]);
				if (count > 0)
				{
					continue;
				}

				// Skipping the parent of this cell
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
					grid[y][x].SetParent(currentCell);
					closedList.push_back(grid[y][x]);

					std::vector<Cell> path;
					currentCell = grid[y][x];

					// Moves backwards through all the parents starting from the end
					// to create the path
					while (currentCell.cellType != Start)
					{
						path.push_back(*(currentCell.GetParent()));
						currentCell = *(currentCell.GetParent());
					}
					
					DrawPath(path);
					return;
				}

				// Add the cell to the open list, if none of the
				// other conditions are true
				grid[y][x].SetParent(currentCell);
				grid[y][x].SetG(currentCell.GetG() + grid[y][x].GetW());
				grid[y][x].SetF(grid[y][x].GetG() + grid[y][x].GetH());
				openList.push_back(grid[y][x]);
			}
		}

		if (openList.size() > 0)
		{
			Draw();
			
			// Finding the cell on the open list with the
			// lowest f-cost, to check that cell first	
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
		else // no more cells on the open list
		{
			std::cout << "Path not found!" << std::endl;
			findingPath = false;
		}

		
	}
}
