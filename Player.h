#pragma once
#include <vector>
#include "SubMarine.h"

class Player
{
public:
	Player(string _PlayerName);
	void addSubMarinetoplayer(SubMarine* _SubMarineName);
	vector <SubMarine*> getPlayerSubMarine();
	void removeSubMarinefromplayer();
	Player();
	~Player();

private:
	string PlayerName;
	vector <SubMarine*> PlayerSubMarines;
};


