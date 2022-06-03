#pragma once
#define	SIZE 11
#include "Player.h"
#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


class Board
{
public:
	Board(){};
	Board(string _boardname);
	void printBoard();
	void NewBoard();
	int setSubMarine(SubMarine _SubmarineName, int _Row, int _Col);
	int setAISubMarine(SubMarine _SubmarineName, int _Row, int _Col, int _Dir);
	bool checkIfAdjacent(int _row, int _col);

	/*void addHit();
	int gethit();*/

private:
	string BoardName;
	int DisplayBoard[SIZE][SIZE];
	//int Hit;
	////int Miss;

};

