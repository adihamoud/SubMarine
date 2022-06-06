#include"Board.h"
#include"BoardCell.h"
const string red("\033[0;31m");
const string green("\033[1;32m");
const string yellow("\033[1;33m");
const string yellow2("\033[1;34m");
const string cyan("\033[0;36m");
const string magenta("\033[0;35m");
const string reset("\033[0m");

Board::Board(string _boardname) {
	BoardName = _boardname;
	numofhits = 0;
	for (int Column = 0; Column < SIZE; Column++) {
		DisplayBoard[0][Column] = NULL;
	}
	for (int Row = 0; Row < SIZE; Row++) {
		DisplayBoard[Row][0] = NULL;
	}

	for (int Row = 1; Row < SIZE; Row++)
	{
		for (int Col = 1; Col < SIZE; Col++)
		{
			DisplayBoard[Row][Col] = new BoardCell();
		}
	}
}
void Board::printBoard()
{
	//system("Color FA");

	for (int Column = 0; Column < SIZE; Column++) {

		if (Column == 0) {
			cout << yellow2;
			cout << "\t\t\t\t\t";
			cout << Column << ")  ";
		}
		else
			cout << "(" << Column << ") ";
	}

	cout << endl;
	cout << endl;

	for (int row = 1; row < SIZE; row++)
	{
		cout << yellow2;
		cout << "\t\t\t\t\t";
		for (int col = 0; col < SIZE; col++)
		{
			if (DisplayBoard[row][col] == NULL) {
				if (row != 10)
					cout << row << ")  ";
				else
					cout << row << ") ";

			}
			else if (DisplayBoard[row][col]->isOccupied())
			{

				cout << red << "(" << DisplayBoard[row][col]->getSubMarine()->getSubMarineSize() << ") " << reset;
			}
			else {

				cout << yellow2;

				cout << "(" << 0 << ") ";
			}
		}
		cout << endl;
		cout << endl;
	}


}

int** Board::BoardStatus()
{
	int** x = new int* [SIZE - 1];
	for (int row = 1; row < SIZE; row++)
	{
		x[row - 1] = new int[SIZE - 1];

		for (int Col = 1; Col < SIZE; Col++)
		{
			if (!DisplayBoard[row][Col]->isHit())
			{
				if (DisplayBoard[row][Col]->isOccupied() && DisplayBoard[row][Col]->getSubMarine()->getSubHits() > 0)
				{
					x[row - 1][Col - 1] = DisplayBoard[row][Col]->getSubMarine()->getSubMarineSize();
				}
				else
				{
					x[row - 1][Col - 1] = 0;
				}

			}
			else if (DisplayBoard[row][Col]->isHit() && (!DisplayBoard[row][Col]->isOccupied()))
			{
				x[row - 1][Col - 1] = -1;

			}
			else if (DisplayBoard[row][Col]->isHit() && DisplayBoard[row][Col]->isOccupied())
			{
				x[row - 1][Col - 1] = (-DisplayBoard[row][Col]->getSubMarine()->getSubMarineSize());
			}

		}
	}
	return x;
}

void Board::printBoardForPlayer()
{
	//system("cls");
	cout << red;
	cout << "\t\t\t\t\t\t\t" << "AI Board!!" << endl;
	for (int Column = 0; Column < SIZE; Column++) {

		if (Column == 0)
		{
			cout << "\t\t\t\t\t";
			cout << yellow2;
			cout << Column << ")  ";


		}
		else
			cout << "(" << Column << ") ";
	}

	cout << endl;
	cout << endl;

	for (int row = 1; row < SIZE; row++)
	{
		cout << "\t\t\t\t\t";
		for (int col = 0; col < SIZE; col++)
		{
			if (DisplayBoard[row][col] == NULL) {
				if (row != 10)
					cout << row << ")  ";
				else
					cout << row << ") ";

			}
			else if (DisplayBoard[row][col]->isOccupied())
			{
				if (DisplayBoard[row][col]->isHit())
				{
					
					cout << "(" << red << 'X' << yellow2 << ") ";
				}
				else
				{
					cout << "(" << '*' << ") ";
				}
			}

			else {
				if (checkSunkBoundaries(row, col)) {
					cout << "(" << yellow << 'V' << yellow2 << ") ";
				}
				else if (DisplayBoard[row][col]->isHit())
				{
					cout << "(" << reset << '0' << yellow2 << ") ";
				}
				else
				{
					cout << "(" << '*' << ") ";
				}
			}
		}
		cout << endl;
		cout << endl;
	}


}
void Board::printBoardForAI()
{
	//system("cls");
	cout << "\t\t\t\t\t\t\t" <<reset<< "Player Board!!"<<yellow2 << endl;
	for (int Column = 0; Column < SIZE; Column++) {

		if (Column == 0)
		{
			cout << "\t\t\t\t\t";
			cout << yellow2;
			cout << Column << ")  ";


		}
		else
			cout << "(" << Column << ") ";
	}

	cout << endl;
	cout << endl;

	for (int row = 1; row < SIZE; row++)
	{
		cout << "\t\t\t\t\t";
		for (int col = 0; col < SIZE; col++)
		{
			if (DisplayBoard[row][col] == NULL) {
				if (row != 10)
					cout << row << ")  ";
				else
					cout << row << ") ";

			}
			else if (DisplayBoard[row][col]->isOccupied())
			{
				if (DisplayBoard[row][col]->isHit())
				{
					cout << "(" << red << 'X' << yellow2 << ") ";
				}
				else
				{
					cout << "(" << '*' << ") ";
				}
			}

			else {
				if (checkSunkBoundaries(row, col)) {
					cout << "(" << yellow << 'V' << yellow2 << ") ";
					
				}
				else if (DisplayBoard[row][col]->isHit())
				{
					cout << "(" << reset << '0' << yellow2 << ") ";
				}
				else
				{
					cout << "(" << '*' << ") ";
				}
			}
		}
		cout << endl;
		cout << endl;
	}


}


bool Board::hit(int _Row, int _Col)
{
	//system("cls");
	if (_Row <= 0 || _Col <= 0 || _Row >= SIZE || _Col >= SIZE)
	{
		cout << "Please insert a valid Point between 1<10" << endl;
		return 0;
	}
	if (DisplayBoard[_Row][_Col]->hitCell())
	{
		numofhits++;
		return true;
	}
	else
	{
		return 0;
	}
	system("cls");


}

bool Board::checkSunkBoundaries(int Row, int Col)
{

	return isthiscellSink(Row + 1, Col - 1) || isthiscellSink(Row + 1, Col)
		|| isthiscellSink(Row + 1, Col + 1) || isthiscellSink(Row, Col - 1)
		|| isthiscellSink(Row, Col + 1) || isthiscellSink(Row - 1, Col - 1)
		|| isthiscellSink(Row - 1, Col) || isthiscellSink(Row - 1, Col + 1);
}

bool Board::isthiscellSink(int Row, int Col)
{
	if ((Row >= 1 && Row <= 10 && Col >= 1 && Col <= 10) && DisplayBoard[Row][Col] && DisplayBoard[Row][Col]->isOccupied() && DisplayBoard[Row][Col]->getSubMarine()->isSink())
	{
		return true;
	}
	return false;
}
bool Board::isthiscellOccupied(int Row, int Col)
{
	if (!(Row >= 1 && Row <= 10 && Col >= 1 && Col <= 10) || (!DisplayBoard[Row][Col]) || (!DisplayBoard[Row][Col]->isOccupied()))
	{
		return true;
	}
	return false;
}
bool Board::checkOccupiedBoundaries(int Row, int Col)
{

	return ((Row >= 1 && Row <= 10 && Col >= 1 && Col <= 10) && (DisplayBoard[Row][Col]) && (!DisplayBoard[Row][Col]->isOccupied())) && isthiscellOccupied(Row + 1, Col - 1) && isthiscellOccupied(Row + 1, Col)
		&& isthiscellOccupied(Row + 1, Col + 1) && isthiscellOccupied(Row, Col - 1)
		&& isthiscellOccupied(Row, Col + 1) && isthiscellOccupied(Row - 1, Col - 1)
		&& isthiscellOccupied(Row - 1, Col) && isthiscellOccupied(Row - 1, Col + 1);
}
bool Board::gameEnded()
{
	return(numofhits == 32);

}
int Board::setSubMarine(SubMarine* _SubmarineName, int _Row, int _Col, int _Dir)
{
	printBoard();
	int SubMarineSize = _SubmarineName->getSubMarineSize();
	string SubMarineName = _SubmarineName->getSubMarinename();
	int Dir = _Dir;
	int freePlace = 0;
	int Col = _Col;
	int Row = _Row;

	if (10 < _Col || 1 > _Col || 10 < _Row || 1 > _Row)
	{
		cout << "Please insert a valid Point between 1<10" << endl;
		return 0;
	}
	switch (Dir)
	{
	case 1:
	{
		for (int i = 0; i < SubMarineSize; i++)
		{
			if (!checkOccupiedBoundaries(Row - i, Col))
			{

				cout << "cant set submarine here" << endl;
				return 0;
			}
		}
		for (int i = 0; i < SubMarineSize; i++)
		{
			DisplayBoard[_Row - i][_Col]->setSubMarine(_SubmarineName);
		}

		cout << SubMarineName << " is ready and loaded for battle!" << endl;
		printBoard();
		return 1;
	}
	case 2:
	{
		for (int i = 0; i < SubMarineSize; i++)
		{
			if (!checkOccupiedBoundaries(Row + i, Col))
			{
				cout << "cant set submarine here" << endl;
				return 0;
			}
		}
		for (int i = 0; i < SubMarineSize; i++)
		{
			DisplayBoard[_Row + i][_Col]->setSubMarine(_SubmarineName);
		}

		cout << SubMarineName << " is ready and loaded for battle!" << endl;
		printBoard();
		return 1;
	}
	case 3:
	{
		for (int i = 0; i < SubMarineSize; i++)
		{
			if (!checkOccupiedBoundaries(Row, Col + i))
			{
				cout << "cant set submarine here" << endl;
				return 0;
			}
		}
		for (int i = 0; i < SubMarineSize; i++)
		{
			DisplayBoard[_Row][_Col + i]->setSubMarine(_SubmarineName);
		}

		cout << SubMarineName << " is ready and loaded for battle!" << endl;
		printBoard();
		return 1;
	}
	case 4:
	{
		for (int i = 0; i < SubMarineSize; i++)
		{
			if (!checkOccupiedBoundaries(Row, Col - i))
			{
				cout << "cant set submarine here" << endl;
				return 0;
			}
		}
		for (int i = 0; i < SubMarineSize; i++)
		{
			DisplayBoard[_Row][_Col - i]->setSubMarine(_SubmarineName);
		}

		cout << SubMarineName << " is ready and loaded for battle!" << endl;
		printBoard();
		return 1;
	}
	break;


	}


}

int Board::setAISubMarine(SubMarine* _SubmarineName, int _Row, int _Col, int _Dir)
{
	int SubMarineSize = _SubmarineName->getSubMarineSize();
	string SubMarineName = _SubmarineName->getSubMarinename();
	int Dir = _Dir;
	int freePlace = 0;
	int Col = _Col;
	int Row = _Row;

	if (10 < _Col || 1 > _Col || 10 < _Row || 1 > _Row)
	{

		return 0;
	}
	switch (Dir)
	{
	case 1:
	{
		for (int i = 0; i < SubMarineSize; i++)
		{
			if (!checkOccupiedBoundaries(Row - i, Col))
			{


				return 0;
			}
		}
		for (int i = 0; i < SubMarineSize; i++)
		{
			DisplayBoard[_Row - i][_Col]->setSubMarine(_SubmarineName);
		}


		return 1;
	}
	case 2:
	{
		for (int i = 0; i < SubMarineSize; i++)
		{
			if (!checkOccupiedBoundaries(Row + i, Col))
			{

				return 0;
			}
		}
		for (int i = 0; i < SubMarineSize; i++)
		{
			DisplayBoard[_Row + i][_Col]->setSubMarine(_SubmarineName);
		}


		return 1;
	}
	case 3:
	{
		for (int i = 0; i < SubMarineSize; i++)
		{
			if (!checkOccupiedBoundaries(Row, Col + i))
			{

				return 0;
			}
		}
		for (int i = 0; i < SubMarineSize; i++)
		{
			DisplayBoard[_Row][_Col + i]->setSubMarine(_SubmarineName);
		}


		return 1;
	}
	case 4:
	{
		for (int i = 0; i < SubMarineSize; i++)
		{
			if (!checkOccupiedBoundaries(Row, Col - i))
			{

				return 0;
			}
		}
		for (int i = 0; i < SubMarineSize; i++)
		{
			DisplayBoard[_Row][_Col - i]->setSubMarine(_SubmarineName);
		}


		return 1;
	}
	break;


	}


}



