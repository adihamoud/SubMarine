#pragma once
#define	SIZE 11
#include "Player.h"
#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BoardCell.h"


class Board
{
public:
	Board(){};
	Board(string _boardname);
	void printBoard();
	void NewBoard();
	int setSubMarine(SubMarine _SubmarineName, int _Row, int _Col);
	int setAISubMarine(SubMarine _SubmarineName, int _Row, int _Col, int _Dir);

private:
	string BoardName;
	BoardCell* DisplayBoard[SIZE][SIZE];
	//int Hit;
	////int Miss;

};

