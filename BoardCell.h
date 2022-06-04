#pragma once
#include "SubMarine.h"

class BoardCell
{
public:
	BoardCell();
	~BoardCell();
	SubMarine* getSubMarine();
	void setSubMarine(SubMarine* _submarine);
	bool isHit();
	bool isOccupied();
	bool hitCell();
	



private:
	SubMarine* submarine;
	bool hit;


};




