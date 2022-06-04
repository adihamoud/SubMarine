#pragma once
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class SubMarine
{
public:
	
	SubMarine(string _SubMarineName, int _SubMarineSize);
	SubMarine();
	~SubMarine(){};
	string getSubMarinename();
	void setSubMarinename(string _SubMarineName);
	int getSubMarineSize();
	void setSubMarineSize(int _SubMarineSize);
	void addSubHit();
	int getSubHits();
	bool isSink();
private:
	string SubMarinename;
	int SubMarineSize;
	bool Sink;
	int SubHits=0;

};

class Carrier : public SubMarine
{
public:

	Carrier() : SubMarine("Carrier", 5) {};
	~Carrier() {};
};

class Cruiser : public SubMarine
{
public:

	Cruiser() : SubMarine("Cruiser", 3) {};
	~Cruiser() {};
};


class Destroyer : public SubMarine
{
public:

	Destroyer() : SubMarine("Destroyer", 2) {};
	~Destroyer() {};
};

class Battleship : public SubMarine
{
public:

	Battleship() : SubMarine("Battleship", 4) {};
	~Battleship() {};
};




