#include"Board.h"
#include"BoardCell.h"


Board::Board(string _boardname) {
	BoardName = _boardname;

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

int  Board::setSubMarine(SubMarine* _SubmarineName, int _Row, int _Col) {
	int SubMarineSize = _SubmarineName->getSubMarineSize();
	string SubMarineName = _SubmarineName->getSubMarinename();
	int Dir;
	int freePlace = 0;
	int Col = _Col;
	int Row = _Row;

	if (10 < _Col || 1 > _Col || 10 < _Row || 1 > _Row)
	{
		cout << "Please insert a valid Point between 1<10" << endl;
		return 0;
	}
	if (DisplayBoard[_Row][_Col]->isOccupied() == false)
	{
		cout << "please choose Direction(1.up 2.down 3.right 4.left)" << endl;
		cin >> Dir;
		if (Dir <= 0 || Dir > 4)
		{
			cout << "Please insert a valid Direction 1<4" << endl;
			return 0;
		}
		switch (Dir)
		{
		case 1:
		{
			if (SubMarineSize > _Row)
			{
				cout << "There is not enough space for " << SubMarineName << endl;
				return 0;
			}
			else
			{
				if (Col == 1)
				{
					int casenum = 0;
					if (_Row == SubMarineSize)
					{
						casenum = 99;
					}
					else
					{
						casenum = _Row;
					}
					switch (casenum)
					{
					case 99:
					{
						for (int rowcheck = (_Row + 1); rowcheck > 0; rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}

						}
						break;
					}
					case 10:
					{
						for (int rowcheck = _Row; rowcheck > ((_Row - (SubMarineSize + 1))); rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}

					default:
					{
						for (int rowcheck = (_Row + 1); rowcheck > (((_Row + 1) - (SubMarineSize + 2))); rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;

					}
					break;
					}
				}
				if (Col < 10 && Col > 1)
				{
					int casenum = 0;
					if (_Row == SubMarineSize)
					{
						casenum = 99;
					}
					else
					{
						casenum = _Row;
					}
					switch (casenum)
					{
					case 1:
					{
						for (int rowcheck = _Row; rowcheck > 0; rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}
					case 99:
					{
						for (int rowcheck = (_Row + 1); rowcheck > 0; rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}
					case 10:
					{
						for (int rowcheck = _Row; rowcheck > (_Row - (SubMarineSize + 1)); rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col - 1]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}
					default:
					{
						for (int rowcheck = (_Row + 1); rowcheck > (((_Row + 1) - (SubMarineSize + 2))); rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;

					}
					}
				}
				if (Col == 10)
				{
					int casenum = 0;
					if (_Row == SubMarineSize)
					{
						casenum = 99;
					}
					else
					{
						casenum = _Row;
					}
					switch (casenum)
					{
					case 10:
					{
						for (int rowcheck = _Row; rowcheck > ((_Row - (SubMarineSize + 1))); rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}
					case 99:
					{
						for (int rowcheck = _Row; rowcheck > 0; rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}
					default:
					{
						for (int rowcheck = (_Row + 1); rowcheck > (((_Row + 1) - (SubMarineSize + 2))); rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;

					}
					break;
					}
				}
				while (Row > 0 && DisplayBoard[Row][Col]->isOccupied() == false)
				{
					Row--;
					freePlace++;
				}

				if (freePlace >= SubMarineSize) {
					freePlace = SubMarineSize;
					while (freePlace > 0 && DisplayBoard[_Row][_Col]->isOccupied() == false) {
						DisplayBoard[_Row][_Col]->setSubMarine(_SubmarineName);
						freePlace--;
						_Row--;
					}
					cout << SubMarineName << " is ready and loaded for battle!" << endl;
					printBoard();
					return 1;
				}

				else {

					cout << "There is not enough space for " << SubMarineName << endl;
					return 0;

				}
			}
		}
		case 2:
		{
			if ((SIZE - _Row) < SubMarineSize)
			{
				cout << "There is not enough space for " << SubMarineName << endl;
				return 0;
			}
			else
			{
				if (Col == 1)
				{
					int casenum = 0;
					if (_Row == SubMarineSize)
					{
						casenum = 99;
					}
					else
					{
						casenum = _Row;
					}
					switch (casenum)
					{
					case 99:
					{
						for (int rowcheck = (_Row - 1); rowcheck < SIZE; rowcheck++)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}

						}
						break;
					}
					case 1:
					{
						for (int rowcheck = _Row; rowcheck < ((_Row + (SubMarineSize + 1))); rowcheck++)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}

					default:
					{
						for (int rowcheck = (_Row - 1); rowcheck < (((_Row - 1) + (SubMarineSize + 2))); rowcheck++)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;

					}
					break;
					}
				}
				if (Col < 10 && Col > 1)
				{
					int casenum = 0;
					if (_Row == SubMarineSize)
					{
						casenum = 99;
					}
					else
					{
						casenum = _Row;
					}
					switch (casenum)
					{
					case 1:
					{
						for (int rowcheck = _Row; rowcheck < (_Row + (SubMarineSize + 1)); rowcheck++)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}
					case 99:
					{
						for (int rowcheck = (_Row - 1); rowcheck < SIZE; rowcheck++)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}

					default:
					{
						for (int rowcheck = (_Row - 1); rowcheck < (((_Row - 1) + (SubMarineSize + 2))); rowcheck++)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;

					}
					}
				}
				if (Col == 10)
				{
					int casenum = 0;
					if (_Row == SubMarineSize)
					{
						casenum = 99;
					}
					else
					{
						casenum = _Row;
					}
					switch (casenum)
					{
					case 1:
					{
						for (int rowcheck = _Row; rowcheck < ((_Row + (SubMarineSize + 1))); rowcheck++)
						{
							if (DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}
					case 99:
					{
						for (int rowcheck = (_Row - 1); rowcheck < SIZE; rowcheck++)
						{
							if (DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}
					default:
					{
						for (int rowcheck = (_Row - 1); rowcheck < (((_Row - 1) + (SubMarineSize + 2))); rowcheck++)
						{
							if (DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;

					}
					break;
					}
				}
				while (Row < SIZE && DisplayBoard[Row][Col]->isOccupied() == false)
				{
					Row++;
					freePlace++;
				}

				if (freePlace >= SubMarineSize) {
					freePlace = SubMarineSize;
					while (freePlace > 0 && DisplayBoard[_Row][_Col]->isOccupied() == false) {
						DisplayBoard[_Row][_Col]->setSubMarine(_SubmarineName);
						freePlace--;
						_Row++;
					}
					cout << SubMarineName << " is ready and loaded for battle!" << endl;
					printBoard();
					return 1;
				}

				else {

					cout << "There is not enough space for " << SubMarineName << endl;
					return 0;

				}
			}
		}
		case 3:
		{
			if ((SIZE - _Col) < SubMarineSize)
			{
				cout << "There is not enough space for " << SubMarineName << endl;
				return 0;
			}
			else
			{
				if (Row == 1)
				{
					int casenum = 0;
					if (SIZE == (_Col + SubMarineSize))
					{
						casenum = 99;
					}
					else
					{
						casenum = _Col;
					}
					switch (casenum)
					{
					case 99:
					{
						for (int Colcheck = (_Col - 1); Colcheck < SIZE; Colcheck++)
						{
							if (DisplayBoard[(Row + 1)][Colcheck]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}

						}
						break;
					}
					case 1:
					{
						for (int Colcheck = _Col; Colcheck < ((_Col + (SubMarineSize + 1))); Colcheck++)
						{
							if (DisplayBoard[Row + 1][Colcheck]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}

					default:
					{
						for (int Colcheck = (_Col - 1); Colcheck < (((_Col - 1) + (SubMarineSize + 2))); Colcheck++)
						{
							if (DisplayBoard[Row + 1][Colcheck]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;

					}
					break;
					}
				}
				if (Row < 10 && Row > 1)
				{
					int casenum = 0;
					if (SIZE == (_Col + SubMarineSize))
					{
						casenum = 99;
					}
					else
					{
						casenum = _Col;
					}
					switch (casenum)
					{
					case 1:
					{
						for (int Colcheck = _Col; Colcheck < (_Col + (SubMarineSize + 1)); Colcheck++)
						{
							if (DisplayBoard[Row + 1][Colcheck]->isOccupied() || DisplayBoard[Row - 1][Colcheck]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}
					case 99:
					{
						for (int Colcheck = (_Col - 1); Colcheck < SIZE; Colcheck++)
						{
							if (DisplayBoard[Row + 1][Colcheck]->isOccupied() || DisplayBoard[Row - 1][Colcheck]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}
					default:
					{
						for (int Colcheck = (_Col - 1); Colcheck < (((_Col - 1) + (SubMarineSize + 2))); Colcheck++)
						{
							if (DisplayBoard[Row + 1][Colcheck]->isOccupied() || DisplayBoard[Row - 1][Colcheck]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;

					}
					}
				}
				if (Row == 10)
				{
					int casenum = 0;
					if (SIZE == (_Col + SubMarineSize))
					{
						casenum = 99;
					}
					else
					{
						casenum = _Col;
					}
					switch (casenum)
					{
					case 1:
					{
						for (int Colcheck = _Col; Colcheck < ((_Col + (SubMarineSize + 1))); Colcheck++)
						{
							if (DisplayBoard[Row - 1][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}
					case 99:
					{
						for (int Colcheck = (_Col - 1); Colcheck > SIZE; Colcheck++)
						{
							if (DisplayBoard[Row - 1][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}
					default:
					{
						for (int Colcheck = (_Col - 1); Colcheck < (((_Col - 1) + (SubMarineSize + 2))); Colcheck++)
						{
							if (DisplayBoard[Row - 1][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;

					}
					break;
					}
				}
				while (Col < SIZE && DisplayBoard[Row][Col]->isOccupied() == false)
				{
					Col++;
					freePlace++;
				}

				if (freePlace >= SubMarineSize) {
					freePlace = SubMarineSize;
					while (freePlace > 0 && DisplayBoard[_Row][_Col]->isOccupied() == false) {
						DisplayBoard[_Row][_Col]->setSubMarine(_SubmarineName);
						freePlace--;
						_Col++;
					}
					cout << SubMarineName << " is ready and loaded for battle!" << endl;
					printBoard();
					return 1;
				}

				else {

					cout << "There is not enough space for " << SubMarineName << endl;
					return 0;

				}
			}
		}

		case 4:
		{
			if (Col < SubMarineSize)
			{
				cout << "There is not enough space for " << SubMarineName << endl;
				return 0;
			}
			else
			{
				if (Row == 1)
				{
					int casenum = 0;
					if (_Col == SubMarineSize)
					{
						casenum = 99;
					}
					else
					{
						casenum = _Col;
					}
					switch (casenum)
					{
					case 99:
					{
						for (int Colcheck = (_Col + 1); Colcheck > SIZE; Colcheck--)
						{
							if (DisplayBoard[(Row + 1)][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}

						}
						break;
					}
					case 10:
					{
						for (int Colcheck = _Col; Colcheck > ((_Col - (SubMarineSize + 1))); Colcheck--)
						{
							if (DisplayBoard[Row + 1][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}

					default:
					{
						for (int Colcheck = (_Col + 1); Colcheck > (((_Col + 1) - (SubMarineSize + 2))); Colcheck--)
						{
							if (DisplayBoard[Row + 1][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;

					}
					break;
					}
				}
				if (Row < 10 && Row > 1)
				{
					int casenum = 0;
					if (_Col == SubMarineSize)
					{
						casenum = 99;
					}
					else
					{
						casenum = _Col;
					}
					switch (casenum)
					{
					case 10:
					{
						for (int Colcheck = _Col; Colcheck > (_Col - (SubMarineSize + 1)); Colcheck--)
						{
							if (DisplayBoard[Row + 1][Colcheck]->isOccupied() || DisplayBoard[Row - 1][Colcheck]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}
					case 99:
					{
						for (int Colcheck = (_Col + 1); Colcheck > 0; Colcheck--)
						{
							if (DisplayBoard[Row + 1][Colcheck]->isOccupied() || DisplayBoard[Row - 1][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}
					default:
					{
						for (int Colcheck = (_Col + 1); Colcheck > (((_Col + 1) - (SubMarineSize + 2))); Colcheck--)
						{
							if (DisplayBoard[Row + 1][Colcheck]->isOccupied() || DisplayBoard[Row - 1][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;

					}
					}
				}
				if (Row == 10)
				{
					int casenum = 0;
					if (_Col == SubMarineSize)
					{
						casenum = 99;
					}
					else
					{
						casenum = _Col;
					}
					switch (casenum)
					{
					case 10:
					{
						for (int Colcheck = _Col; Colcheck > ((_Col - (SubMarineSize + 1))); Colcheck--)
						{
							if (DisplayBoard[Row - 1][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}
					case 99:
					{
						for (int Colcheck = (_Col + 1); Colcheck > 0; Colcheck--)
						{
							if (DisplayBoard[Row - 1][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;

					}
					default:
					{
						for (int Colcheck = (_Col - 1); Colcheck < (((_Col - 1) + (SubMarineSize + 2))); Colcheck++)
						{
							if (DisplayBoard[Row - 1][Colcheck]->isOccupied() || DisplayBoard[Row + 1][Colcheck]->isOccupied())
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;

					}
					break;
					}
				}
				while (Col > 0 && DisplayBoard[Row][Col]->isOccupied() == false)
				{
					Col--;
					freePlace++;
				}

				if (freePlace >= SubMarineSize) {
					freePlace = SubMarineSize;
					while (freePlace > 0 && DisplayBoard[_Row][_Col]->isOccupied() == false) {
						DisplayBoard[_Row][_Col]->setSubMarine(_SubmarineName);
						freePlace--;
						_Col--;
					}
					cout << SubMarineName << " is ready and loaded for battle!" << endl;
					printBoard();
					return 1;
				}

				else {

					cout << "There is not enough space for " << SubMarineName << endl;
					return 0;

				}
			}
		}
		}

	}
	else
	{
		cout << "submarine already there" << endl;
	}
}



int  Board::setAISubMarine(SubMarine* _SubmarineName, int _Row, int _Col, int _Dir) {
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
	if (DisplayBoard[_Row][_Col]->isOccupied() == false)
	{
		switch (Dir)
		{
		case 1:
		{
			if (SubMarineSize > _Row)
			{
				return 0;
			}
			else
			{
				if (Col == 1)
				{
					int casenum = 0;
					if (_Row == SubMarineSize)
					{
						casenum = 99;
					}
					else
					{
						casenum = _Row;
					}
					switch (casenum)
					{
					case 99:
					{
						for (int rowcheck = _Row; rowcheck > 0; rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{

								return 0;
							}

						}
						break;
					}
					case 10:
					{
						for (int rowcheck = _Row; rowcheck > ((_Row - (SubMarineSize + 1))); rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{

								return 0;
							}
						}
						break;
					}

					default:
					{
						for (int rowcheck = (_Row + 1); rowcheck > (((_Row + 1) - (SubMarineSize + 2))); rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{

								return 0;
							}
						}


					}
					break;
					}
				}
				if (Col < 10 && Col > 1)
				{
					int casenum = 0;
					if (_Row == SubMarineSize)
					{
						casenum = 99;
					}
					else
					{
						casenum = _Row;
					}
					switch (casenum)
					{
						/*case 1:
						{
							for (int rowcheck = _Row; rowcheck > 0; rowcheck--)
							{
								if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
								{

									return 0;
								}
							}
							break;
						}*/
					case 99:
					{
						for (int rowcheck = (_Row + 1); rowcheck > 0; rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{

								return 0;
							}
						}
						break;
					}
					case 10:
					{
						for (int rowcheck = _Row; rowcheck > (_Row - (SubMarineSize + 1)); rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col - 1]->isOccupied())
							{

								return 0;
							}
						}
						break;
					}
					default:
					{
						for (int rowcheck = (_Row + 1); rowcheck > (((_Row + 1) - (SubMarineSize + 2))); rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{

								return 0;
							}
						}
						break;

					}
					}
				}
				if (Col == 10)
				{
					int casenum = 0;
					if (_Row == SubMarineSize)
					{
						casenum = 99;
					}
					else
					{
						casenum = _Row;
					}
					switch (casenum)
					{
					case 10:
					{
						for (int rowcheck = _Row; rowcheck > ((_Row - (SubMarineSize + 1))); rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{

								return 0;
							}
						}
						break;
					}
					case 99:
					{
						for (int rowcheck = (_Row + 1); rowcheck > 0; rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{

								return 0;
							}
						}
						break;
					}
					default:
					{
						for (int rowcheck = (_Row + 1); rowcheck > (((_Row + 1) - (SubMarineSize + 2))); rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{

								return 0;
							}
						}
						break;

					}
					break;
					}
				}
				while (Row > 0 && DisplayBoard[Row][Col]->isOccupied() == false)
				{
					Row--;
					freePlace++;
				}

				if (freePlace == SubMarineSize) {
					freePlace = SubMarineSize;
					while (freePlace > 0 && DisplayBoard[_Row][_Col]->isOccupied() == false) {
						DisplayBoard[_Row][_Col]->setSubMarine(_SubmarineName);
						freePlace--;
						_Row--;
					}


					return 1;
				}

				else {


					return 0;

				}
			}
		}
		case 2:
		{
			if ((SIZE - _Row) < SubMarineSize)
			{

				return 0;
			}
			else
			{
				if (Col == 1)
				{
					int casenum = 0;
					if (SIZE - _Row == SubMarineSize)
					{
						casenum = 99;
					}
					else
					{
						casenum = _Row;
					}
					switch (casenum)
					{
					case 99:
					{
						for (int rowcheck = (_Row - 1); rowcheck < SIZE; rowcheck++)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{

								return 0;
							}

						}
						break;
					}
					case 1:
					{
						for (int rowcheck = _Row; rowcheck < ((_Row + (SubMarineSize + 1))); rowcheck++)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{

								return 0;
							}
						}
						break;
					}

					default:
					{
						for (int rowcheck = (_Row - 1); rowcheck < (((_Row - 1) + (SubMarineSize + 2))); rowcheck++)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{

								return 0;
							}
						}
						break;

					}
					break;
					}
				}
				if (Col < 10 && Col > 1)
				{
					int casenum = 0;
					if (_Row == SubMarineSize)
					{
						casenum = 99;
					}
					else
					{
						casenum = _Row;
					}
					switch (casenum)
					{
					case 1:
					{
						for (int rowcheck = _Row; rowcheck < (_Row + (SubMarineSize + 1)); rowcheck++)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{

								return 0;
							}
						}
						break;
					}
					case 99:
					{
						for (int rowcheck = (_Row - 1); rowcheck < SIZE; rowcheck++)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{

								return 0;
							}
						}
						break;
					}

					default:
					{
						for (int rowcheck = (_Row - 1); rowcheck < (((_Row - 1) + (SubMarineSize + 1))); rowcheck++)
						{
							if (DisplayBoard[rowcheck][Col + 1]->isOccupied() || DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{

								return 0;
							}
						}
						break;

					}
					}
				}
				if (Col == 10)
				{
					int casenum = 0;
					if (_Row == SubMarineSize)
					{
						casenum = 99;
					}
					else
					{
						casenum = _Row;
					}
					switch (casenum)
					{
					case 1:
					{
						for (int rowcheck = _Row; rowcheck < ((_Row + (SubMarineSize + 1))); rowcheck++)
						{
							if (DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{

								return 0;
							}
						}
						break;
					}
					case 99:
					{
						for (int rowcheck = (_Row - 1); rowcheck < SIZE; rowcheck++)
						{
							if (DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{

								return 0;
							}
						}
						break;
					}
					default:
					{
						for (int rowcheck = (_Row - 1); rowcheck < (((_Row - 1) + (SubMarineSize + 2))); rowcheck++)
						{
							if (DisplayBoard[rowcheck][Col - 1]->isOccupied() || DisplayBoard[rowcheck][Col]->isOccupied())
							{

								return 0;
							}
						}
						break;

					}
					break;
					}
				}
				while (Row < SIZE && DisplayBoard[Row][Col]->isOccupied() == false)
				{
					Row++;
					freePlace++;
				}

				if (freePlace >= SubMarineSize) {
					freePlace = SubMarineSize;
					while (freePlace > 0 && DisplayBoard[_Row][_Col]->isOccupied() == false) {
						DisplayBoard[_Row][_Col]->setSubMarine(_SubmarineName);
						freePlace--;
						_Row++;
					}


					return 1;
				}

				else {


					return 0;

				}
			}
		}
		case 3:
		{
			if ((SIZE - _Col) < SubMarineSize)
			{

				return 0;
			}
			else
			{
				if (Row == 1)
				{
					int casenum = 0;
					if (SIZE == (_Col + SubMarineSize))
					{
						casenum = 99;
					}
					else
					{
						casenum = _Col;
					}
					switch (casenum)
					{
					case 99:
					{
						for (int Colcheck = (_Col - 1); Colcheck < SIZE; Colcheck++)
						{
							if (DisplayBoard[(Row + 1)][Colcheck]->isOccupied() || DisplayBoard[(Row)][Colcheck]->isOccupied())
							{

								return 0;
							}

						}
						break;
					}
					case 1:
					{
						for (int Colcheck = _Col; Colcheck < ((_Col + (SubMarineSize + 1))); Colcheck++)
						{
							if (DisplayBoard[Row + 1][Colcheck]->isOccupied() || DisplayBoard[(Row)][Colcheck]->isOccupied())
							{

								return 0;
							}
						}
						break;
					}

					default:
					{
						for (int Colcheck = (_Col - 1); Colcheck < (((_Col - 1) + (SubMarineSize + 2))); Colcheck++)
						{
							if (DisplayBoard[Row + 1][Colcheck]->isOccupied() || DisplayBoard[(Row)][Colcheck]->isOccupied())
							{

								return 0;
							}
						}
						break;

					}
					break;
					}
				}
				if (Row < 10 && Row > 1)
				{
					int casenum = 0;
					if (SIZE == (_Col + SubMarineSize))
					{
						casenum = 99;
					}
					else
					{
						casenum = _Col;
					}
					switch (casenum)
					{
					case 1:
					{
						for (int Colcheck = _Col; Colcheck < (_Col + (SubMarineSize + 1)); Colcheck++)
						{
							if (DisplayBoard[Row + 1][Colcheck]->isOccupied() || DisplayBoard[Row - 1][Colcheck]->isOccupied() || DisplayBoard[(Row)][Colcheck]->isOccupied())
							{

								return 0;
							}
						}
						break;
					}
					case 99:
					{
						for (int Colcheck = (_Col - 1); Colcheck < SIZE; Colcheck++)
						{
							if (DisplayBoard[Row + 1][Colcheck]->isOccupied() || DisplayBoard[Row - 1][Colcheck]->isOccupied() || DisplayBoard[(Row)][Colcheck]->isOccupied())
							{

								return 0;
							}
						}
						break;
					}
					default:
					{
						for (int Colcheck = (_Col - 1); Colcheck < (((_Col - 1) + (SubMarineSize + 2))); Colcheck++)
						{
							if (DisplayBoard[Row + 1][Colcheck]->isOccupied() || DisplayBoard[Row - 1][Colcheck]->isOccupied() || DisplayBoard[(Row)][Colcheck]->isOccupied())
							{

								return 0;
							}
						}
						break;

					}
					}
				}
				if (Row == 10)
				{
					int casenum = 0;
					if (SIZE == (_Col + SubMarineSize))
					{
						casenum = 99;
					}
					else
					{
						casenum = _Col;
					}
					switch (casenum)
					{
					case 1:
					{
						for (int Colcheck = _Col; Colcheck < ((_Col + (SubMarineSize + 1))); Colcheck++)
						{
							if (DisplayBoard[Row - 1][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{

								return 0;
							}
						}
						break;
					}
					case 99:
					{
						for (int Colcheck = (_Col - 1); Colcheck > SIZE; Colcheck++)
						{
							if (DisplayBoard[Row - 1][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{

								return 0;
							}
						}
						break;
					}
					default:
					{
						for (int Colcheck = (_Col - 1); Colcheck < (((_Col - 1) + (SubMarineSize + 2))); Colcheck++)
						{
							if (DisplayBoard[Row - 1][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{

								return 0;
							}
						}
						break;

					}
					break;
					}
				}
				while (Col < SIZE && DisplayBoard[Row][Col]->isOccupied() == false)
				{
					Col++;
					freePlace++;
				}

				if (freePlace >= SubMarineSize) {
					freePlace = SubMarineSize;
					while (freePlace > 0 && DisplayBoard[_Row][_Col]->isOccupied() == false) {
						DisplayBoard[_Row][_Col]->setSubMarine(_SubmarineName);
						freePlace--;
						_Col++;
					}


					return 1;
				}

				else {


					return 0;

				}
			}
		}

		case 4:
		{
			if (Col < SubMarineSize)
			{

				return 0;
			}
			else
			{
				if (Row == 1)
				{
					int casenum = 0;
					if (_Col == SubMarineSize)
					{
						casenum = 99;
					}
					else
					{
						casenum = _Col;
					}
					switch (casenum)
					{
					case 99:
					{
						for (int Colcheck = (_Col + 1); Colcheck > 0; Colcheck--)
						{
							if (DisplayBoard[(Row + 1)][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{

								return 0;
							}

						}
						break;
					}
					case 10:
					{
						for (int Colcheck = _Col; Colcheck > ((_Col - (SubMarineSize + 1))); Colcheck--)
						{
							if (DisplayBoard[Row + 1][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{

								return 0;
							}
						}
						break;
					}

					default:
					{
						for (int Colcheck = (_Col + 1); Colcheck > (((_Col + 1) - (SubMarineSize + 2))); Colcheck--)
						{
							if (DisplayBoard[Row + 1][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{

								return 0;
							}
						}
						break;

					}
					break;
					}
				}
				if (Row < 10 && Row > 1)
				{
					int casenum = 0;
					if (_Col == SubMarineSize)
					{
						casenum = 99;
					}
					else
					{
						casenum = _Col;
					}
					switch (casenum)
					{
					case 10:
					{
						for (int Colcheck = _Col; Colcheck > (_Col - (SubMarineSize + 1)); Colcheck--)
						{
							if (DisplayBoard[Row + 1][Colcheck]->isOccupied() || DisplayBoard[Row - 1][Colcheck]->isOccupied())
							{

								return 0;
							}
						}
						break;
					}
					case 99:
					{
						for (int Colcheck = (_Col + 1); Colcheck > 0; Colcheck--)
						{
							if (DisplayBoard[Row + 1][Colcheck]->isOccupied() || DisplayBoard[Row - 1][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{

								return 0;
							}
						}
						break;
					}
					default:
					{
						for (int Colcheck = (_Col + 1); Colcheck > (((_Col + 1) - (SubMarineSize + 2))); Colcheck--)
						{
							if (DisplayBoard[Row + 1][Colcheck]->isOccupied() || DisplayBoard[Row - 1][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{

								return 0;
							}
						}
						break;

					}
					}
				}
				if (Row == 10)
				{
					int casenum = 0;
					if (_Col == SubMarineSize)
					{
						casenum = 99;
					}
					else
					{
						casenum = _Col;
					}
					switch (casenum)
					{
					case 10:
					{
						for (int Colcheck = _Col; Colcheck > ((_Col - (SubMarineSize + 1))); Colcheck--)
						{
							if (DisplayBoard[Row - 1][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{

								return 0;
							}
						}
						break;
					}
					case 99:
					{
						for (int Colcheck = (_Col + 1); Colcheck > 0; Colcheck--)
						{
							if (DisplayBoard[Row - 1][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{

								return 0;
							}
						}
						break;

					}
					default:
					{
						for (int Colcheck = (_Col + 1); Colcheck < (((_Col)-(SubMarineSize + 1))); Colcheck--)
						{
							if (DisplayBoard[Row - 1][Colcheck]->isOccupied() || DisplayBoard[Row][Colcheck]->isOccupied())
							{

								return 0;
							}
						}
						break;

					}
					break;
					}
				}
				while (Col > 0 && DisplayBoard[Row][Col]->isOccupied() == false)
				{
					Col--;
					freePlace++;
				}

				if (freePlace >= SubMarineSize) {
					freePlace = SubMarineSize;
					while (freePlace > 0 && DisplayBoard[_Row][_Col]->isOccupied() == false) {
						DisplayBoard[_Row][_Col]->setSubMarine(_SubmarineName);
						freePlace--;
						_Col--;
					}


					return 1;
				}

				else {


					return 0;

				}
			}
		}
		}

	}
	else
	{
		return 0;

	}

}

bool Board::hit(int _Row, int _Col)
{
	if (_Row <= 0 || _Col <= 0 || _Row >= SIZE || _Col >= SIZE)
		cout << "Please insert a valid Point between 1<10" << endl;
	return DisplayBoard[_Row][_Col]->hitCell();
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

