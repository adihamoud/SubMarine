#include"Board.h"
#include"BoardCell.h"


Board::Board(string _boardname) {
	BoardName = _boardname;
	numofhits= 0;
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
	for (int Column = 0; Column < SIZE; Column++) {
		if (Column == 0)
			cout << Column << ")  ";
		else
			cout << "(" << Column << ") ";
	}

	cout << endl;
	cout << endl;

	for (int row = 1; row < SIZE; row++)
	{
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
				cout << "(" << DisplayBoard[row][col]->getSubMarine()->getSubMarineSize() << ") ";
			}
			else {
				cout << "(" << 0 << ") ";
			}
		}
		cout << endl;
		cout << endl;
	}
	/*for (int Column = 0; Column < SIZE; Column++) {
		DisplayBoard[0][Column] = Column;
	}
	for (int Row = 0; Row < SIZE; Row++) {
		DisplayBoard[Row][0] = Row;
	}

	for (int Row = 0; Row < SIZE; Row++)
	{

		cout << "\n";
		cout << "\t\t\t\t\t";



		if (Row != 10) {
			cout << " ";
		}


		for (int Col = 0; Col < SIZE; Col++)
		{
			if (Col == 0 && Row == 0) {
				cout << "";
			}
			if (Col == 1 && Row >= 0) {
				cout << "-";
			}
			if (Col >= 1)
			{


			}
			cout << " ";
			cout << "(" << DisplayBoard[Row][Col] << ")";


		}
		cout << endl;
	}*/

}

void Board::printBoardForPlayers()
{
	for (int Column = 0; Column < SIZE; Column++) {
		if (Column == 0)
			cout << Column << ")  ";
		else
			cout << "(" << Column << ") ";
	}

	cout << endl;
	cout << endl;

	for (int row = 1; row < SIZE; row++)
	{
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
					cout << "(" << 'X' << ") ";
				}
				else
				{
					cout << "(" << '*' << ") ";
				}
			}

			else {
				if (checkSunkBoundaries(row, col)) {
					cout << "(" << 'V' << ") ";
				}
				else if (DisplayBoard[row][col]->isHit())
				{
					cout << "(" << '0' << ") ";
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
	/*for (int Column = 0; Column < SIZE; Column++) {
		DisplayBoard[0][Column] = Column;
	}
	for (int Row = 0; Row < SIZE; Row++) {
		DisplayBoard[Row][0] = Row;
	}

	for (int Row = 0; Row < SIZE; Row++)
	{

		cout << "\n";
		cout << "\t\t\t\t\t";



		if (Row != 10) {
			cout << " ";
		}


		for (int Col = 0; Col < SIZE; Col++)
		{
			if (Col == 0 && Row == 0) {
				cout << "";
			}
			if (Col == 1 && Row >= 0) {
				cout << "-";
			}
			if (Col >= 1)
			{


			}
			cout << " ";
			cout << "(" << DisplayBoard[Row][Col] << ")";


		}
		cout << endl;
	}*/

}

bool Board::hit(int _Row, int _Col)
{
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
	 return 0;
	
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




