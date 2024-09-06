#pragma once

class Cell
{
private:
	unsigned short id;

	unsigned short weightedCost;
	unsigned short heuristicCost;
	unsigned short costFromStart;
	unsigned short weightedDistance;

	bool obstacle;

	Cell* parent;

public:
	unsigned short x;
	unsigned short y;

	bool operator==(const Cell& other);

	Cell(unsigned short id, unsigned short x, unsigned short y, unsigned short w, unsigned short g, unsigned short h);
	~Cell();

	bool isObstacle();
	unsigned short GetId();

	unsigned short GetH();

	unsigned short GetW();

	unsigned short GetG();
	void SetG(unsigned short value);

	unsigned short GetF();
	void SetF(unsigned short value);

	Cell* GetParent();
	void SetParent(Cell* other);
};

