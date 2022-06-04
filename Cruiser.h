#pragma once
#include "SubMarine.h"

class Cruiser : public SubMarine
{
public:

	Cruiser() : SubMarine("Cruiser", 3) {};
	~Cruiser() {};
};

