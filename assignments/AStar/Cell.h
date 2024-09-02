#pragma once

class Cell
{
private:
	unsigned short id;
	unsigned short weightedCost;
	unsigned short costFromStart;
	float heuristicCost;

	bool obstacle;

	//Cell parent;

public:

	Cell(unsigned short id, int w, int g, int h);
	~Cell();

	bool isObstacle();
	unsigned short GetId();
	void SetHeuristicCost(unsigned short cost);
	float GetHeuristicCost();
};

