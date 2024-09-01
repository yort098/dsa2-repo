#include "Cell.h"

Cell::Cell(unsigned short id)
{
	this->id = id;

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
