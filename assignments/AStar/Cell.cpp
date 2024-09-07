#include "Cell.h"

bool Cell::operator==(const Cell& other)
{
	return (x == other.x && y == other.y);
}

Cell::Cell(unsigned short id, unsigned short x, unsigned short y, unsigned short w, unsigned short g)
{
	this->x = x;
	this->y = y;
	this->id = id;
	this->weightedCost = w;
	this->costFromStart = g;
	
	heuristicCost = 0;
	weightedDistance = 0;
	cellType = Empty;
	parent = nullptr;
}

Cell::~Cell()
{
	if (parent)
	{
		delete parent;
	}
	
	parent = nullptr;
}

unsigned short Cell::GetId()
{
	return id;
}

unsigned short Cell::GetH()
{
	return heuristicCost;
}

void Cell::SetH(unsigned short value)
{
	heuristicCost = value;
}

unsigned short Cell::GetW()
{
	return weightedCost;
}

unsigned short Cell::GetG()
{
	return costFromStart;
}

void Cell::SetG(unsigned short value)
{
	costFromStart = value;
}

unsigned short Cell::GetF()
{
	return weightedDistance;
}

void Cell::SetF(unsigned short value)
{
	weightedDistance = value;
}

Cell* Cell::GetParent()
{
	return parent;
}

void Cell::SetParent(Cell* other)
{
	parent = other;
}
