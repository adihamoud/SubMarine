#pragma once
#include "SubMarine.h"

class Carrier : public SubMarine
{
public:

	Carrier() : SubMarine("Carrier", 5) {};
	~Carrier() {};
};

