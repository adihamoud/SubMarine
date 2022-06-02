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

