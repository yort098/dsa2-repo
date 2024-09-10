#pragma once
#include <memory>

/// <summary>
/// Represents the type of cell that is on the grid
/// </summary>
enum CellType
{
	Start,
	End,
	Wall,
	Empty
};

class Cell
{
private:
	unsigned short weightedCost;
	unsigned short heuristicCost;
	unsigned short costFromStart;
	unsigned short weightedDistance;

	std::shared_ptr<Cell> parent;
	

public:
	unsigned short id;
	unsigned short x;
	unsigned short y;
	CellType cellType;

	bool operator==(const Cell& other);

	Cell(unsigned short id, unsigned short x, unsigned short y);

	unsigned short GetH();
	void SetH(unsigned short value);

	unsigned short GetW();

	unsigned short GetG();
	void SetG(unsigned short value);

	unsigned short GetF();
	void SetF(unsigned short value);

	std::shared_ptr<Cell> GetParent();
	void SetParent(Cell other);
};

