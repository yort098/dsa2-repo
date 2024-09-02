#include "Cell.h"

Cell::Cell(unsigned short id, int w, int g, int h)
{
	this->id = id;
	this->weightedCost = w;
	this->costFromStart = g;
	this->heuristicCost = h;

	obstacle = false;
}

Cell::~Cell()
{
}

bool Cell::isObstacle()
{
	return obstacle;
}

unsigned short Cell::GetId()
{
	return id;
}

float Cell::GetHeuristicCost()
{
	return heuristicCost;
}
