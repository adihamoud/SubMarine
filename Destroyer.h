#pragma once
#include "SubMarine.h"

class Destroyer : public SubMarine
{
public:

	Destroyer() : SubMarine("Destroyer", 2) {};
	~Destroyer() {};
};

