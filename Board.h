#pragma once
#define	SIZE 11
#include "Player.h"
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BoardCell.h"
#include "SubMarine.h"


class Board
{
public:
	Board(){};
	Board(string _boardname);
	void printBoard();
	void NewBoard();
	int setSubMarine(SubMarine *_SubmarineName, int _Row, int _Col);
	int setAISubMarine(SubMarine *_SubmarineName, int _Row, int _Col, int _Dir);
	bool hit(int _Row, int _Col);

private:
	string BoardName;
	BoardCell* DisplayBoard[SIZE][SIZE];
	//int Hit;
	////int Miss;

};

