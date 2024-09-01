#pragma once

class Cell
{
private:
	unsigned short id;
	unsigned short weightedCost;
	unsigned short costFromStart;
	unsigned short hueristicCost;

	bool obstacle;

	//Cell parent;

public:

	Cell(unsigned short id);
	~Cell();

	bool isObstacle();
	unsigned short GetId();
};

