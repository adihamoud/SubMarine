#include "BoardCell.h"


BoardCell::BoardCell()
{
	hit = false;
	submarine = NULL;
}

BoardCell::~BoardCell()
{
}

SubMarine* BoardCell::getSubMarine()
{
	return submarine;
}

void BoardCell::setSubMarine(SubMarine* _submarine)
{
	submarine = _submarine;
}

bool BoardCell::isHit()
{
	return hit;
}

bool BoardCell::isOccupied()
{
	return (submarine != NULL);
}

void BoardCell::hitCell()
{
	hit = true;
}