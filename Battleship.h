#pragma once
#include "SubMarine.h"

class Battleship : public SubMarine
{
public:

	Battleship() : SubMarine("Battleship", 4) {};
	~Battleship() {};
};

