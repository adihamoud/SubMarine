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
	int** BoardStatus();
	void printBoardForPlayers();
	void NewBoard();
	bool hit(int _Row, int _Col);
	bool checkSunkBoundaries(int Row, int Col);
	bool isthiscellSink(int Row,int Col);
	int setSubMarine(SubMarine* _SubmarineName, int _Row, int _Col, int Dir);
	bool isthiscellOccupied(int Row, int Col);
	bool checkOccupiedBoundaries(int Row, int Col);
	bool gameEnded();
private:
	int numofhits;
	string BoardName;
	BoardCell* DisplayBoard[SIZE][SIZE];
};

