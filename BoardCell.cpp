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

bool BoardCell::hitCell()
{
	if (hit) {
		cout << "The cell has been already hit." << endl;
		return false;
	}

	if (isOccupied()) {
		submarine->addSubHit();

		if (submarine->isSink())
			cout << submarine->getSubMarinename() << " sunk!";

		return true;
	}

	hit = true;

	return false;
}