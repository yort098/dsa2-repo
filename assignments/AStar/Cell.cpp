#include "Cell.h"

/// <summary>
/// Checks if two Cells are equal to each other
/// </summary>
/// <param name="other">The cell to compare against</param>
/// <returns>Whether or not the 2 cells are equal</returns>
bool Cell::operator==(const Cell& other)
{
	return (id == other.id);
}

/// <summary>
/// Initializes the data of the cell
/// </summary>
/// <param name="id">The id assigned to this cell</param>
/// <param name="x">The x position of this cell in the grid</param>
/// <param name="y">The y position of this cell in the grid</param>
Cell::Cell(unsigned short id, unsigned short x, unsigned short y)
{
	this->x = x;
	this->y = y;
	this->id = id;
	
	weightedCost = (std::rand() % 10) + 1; // Generates a random number between 1-10
	costFromStart = 0;
	heuristicCost = 0;
	weightedDistance = 0;
	cellType = Empty;
	parent = nullptr;
}

/// <returns>The heuristic cost of this cell</returns>
unsigned short Cell::GetH()
{
	return heuristicCost;
}

/// <summary>
/// Sets the heuristic cost of this cell
/// </summary>
/// <param name="value">The value to assign h to</param>
void Cell::SetH(unsigned short value)
{
	heuristicCost = value;
}

/// <returns>The weighted cost of this cell</returns>
unsigned short Cell::GetW()
{
	return weightedCost;
}

/// <returns>The cost from the starting point of this cell</returns>
unsigned short Cell::GetG()
{
	return costFromStart;
}

/// <summary>
/// Sets the cost from start of this cell
/// </summary>
/// <param name="value">The value to set</param>
void Cell::SetG(unsigned short value)
{
	costFromStart = value;
}

/// <returns>The weighted distance of this cell</returns>
unsigned short Cell::GetF()
{
	return weightedDistance;
}

/// <summary>
/// Sets the weighted distance of this cell
/// </summary>
/// <param name="value">The value to set</param>
void Cell::SetF(unsigned short value)
{
	weightedDistance = value;
}

/// <returns>A pointer to this cell's parent</returns>
std::shared_ptr<Cell> Cell::GetParent()
{
	return parent;
}

/// <summary>
/// Sets this cell's parent to another cell
/// </summary>
/// <param name="other">The parent of this cell</param>
void Cell::SetParent(Cell other)
{
	parent = std::make_shared<Cell>(other);
}
