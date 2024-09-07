#pragma once

enum CellType
{
	Start,
	End,
	Obstacle,
	Empty
};

class Cell
{
private:
	unsigned short weightedCost;
	unsigned short heuristicCost;
	unsigned short costFromStart;
	unsigned short weightedDistance;

	Cell* parent;
	

public:
	unsigned short id;
	unsigned short x;
	unsigned short y;
	CellType cellType;

	bool operator==(const Cell& other);

	Cell(unsigned short id, unsigned short x, unsigned short y, unsigned short w, unsigned short g);
	~Cell();

	unsigned short GetId();

	unsigned short GetH();
	void SetH(unsigned short value);

	unsigned short GetW();

	unsigned short GetG();
	void SetG(unsigned short value);

	unsigned short GetF();
	void SetF(unsigned short value);

	Cell* GetParent();
	void SetParent(Cell* other);
};

