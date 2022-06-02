#include"Board.h"
Board::Board(string _boardname) {
	BoardName = _boardname;

}
void Board::printBoard()
{
	
	for (int Column = 0; Column < SIZE; Column++) {
		DisplayBoard[0][Column] = Column;
	}
	for (int Row = 0; Row < SIZE; Row++) {
		DisplayBoard[Row][0] = Row;
	}
	
	for (int Row = 0; Row < SIZE; Row++)
	{
		
		cout<< "\n";
		cout << "\t\t\t\t\t";

		

		if (Row != 10) {
			cout << " ";
		}
		

		for (int Col = 0; Col < SIZE; Col++)
		{
			if (Col == 0 && Row == 0 ) {
				cout << "";
			}
			if (Col == 1 && Row >= 0) {
				cout << "-";
			}
			if (Col>=1)
			{
				
				
			}
			cout << " ";
			cout << "(" << DisplayBoard[Row][Col] << ")";
			

		}
		cout << endl;
	}
	
}
int  Board::setSubMarine(SubMarine _SubmarineName, int _Row, int _Col) {
	int SubMarineSize = _SubmarineName.getSubMarineSize();
	string SubMarineName = _SubmarineName.getSubMarinename();
	int Dir;
	int freePlace = 0;
	int Col = _Col;
	int Row = _Row;

	if (10 < _Col || 1 > _Col || 10 < _Row || 1 > _Row)
	{
		cout << "Please insert a valid Point between 1<10" << endl;
		return 0;
	}
	if (DisplayBoard[_Row][_Col] == 0)
	{
		cout << "please choose Direction(1.up 2.down 3.right 4.left)" << endl;
		cin >> Dir;
		if (Dir <=0 ||Dir > 4)
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
						for (int rowcheck = _Row; rowcheck > 0; rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col + 1] != 0 || DisplayBoard[rowcheck][Col] != 0)
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
							if (DisplayBoard[rowcheck][Col + 1] != 0 || DisplayBoard[rowcheck][Col] != 0)
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
							if (DisplayBoard[rowcheck][Col + 1] != 0 || DisplayBoard[rowcheck][Col] != 0)
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
							if (DisplayBoard[rowcheck][Col + 1] != 0 || DisplayBoard[rowcheck][Col - 1] != 0 || DisplayBoard[rowcheck][Col] != 0)
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
							if (DisplayBoard[rowcheck][Col + 1] != 0 || DisplayBoard[rowcheck][Col - 1] != 0 || DisplayBoard[rowcheck][Col] != 0)
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
							if (DisplayBoard[rowcheck][Col + 1] != 0 || DisplayBoard[rowcheck][Col - 1] != 0)
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
							if (DisplayBoard[rowcheck][Col + 1] != 0 || DisplayBoard[rowcheck][Col - 1] != 0 || DisplayBoard[rowcheck][Col ] != 0)
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
						casenum = 3;
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
							if (DisplayBoard[rowcheck][Col - 1] != 0 || DisplayBoard[rowcheck][Col] != 0)
							{
								cout << "Cant set Submrines close to each other" << endl;
								return 0;
							}
						}
						break;
					}
					case 1:
					{
						for (int rowcheck = _Row; rowcheck > 0; rowcheck--)
						{
							if (DisplayBoard[rowcheck][Col - 1] != 0 || DisplayBoard[rowcheck][Col] != 0)
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
							if (DisplayBoard[rowcheck][Col - 1] != 0 || DisplayBoard[rowcheck][Col] != 0)
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
				while (DisplayBoard[Row][Col] == 0)
				{
					Row--;
					freePlace++;
				}

				if (freePlace >= SubMarineSize) {
					freePlace = SubMarineSize;
					while (DisplayBoard[_Row][_Col] == 0 && freePlace > 0) {
						DisplayBoard[_Row][_Col] = SubMarineSize;
						freePlace--;
						_Row--;
					}
					cout << " " + SubMarineName << "is ready and loaded for battle!" << endl;
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
							if (DisplayBoard[rowcheck][Col + 1] != 0 || DisplayBoard[rowcheck][Col] != 0)
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
							if (DisplayBoard[rowcheck][Col + 1] != 0 || DisplayBoard[rowcheck][Col] != 0)
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
							if (DisplayBoard[rowcheck][Col + 1] != 0 || DisplayBoard[rowcheck][Col] != 0)
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
							if (DisplayBoard[rowcheck][Col + 1] != 0 || DisplayBoard[rowcheck][Col - 1] != 0 || DisplayBoard[rowcheck][Col] != 0)
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
							if (DisplayBoard[rowcheck][Col + 1] != 0 || DisplayBoard[rowcheck][Col - 1] != 0 || DisplayBoard[rowcheck][Col] != 0)
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
							if (DisplayBoard[rowcheck][Col + 1] != 0 || DisplayBoard[rowcheck][Col - 1] != 0 || DisplayBoard[rowcheck][Col] != 0)
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
							if (DisplayBoard[rowcheck][Col - 1] != 0 || DisplayBoard[rowcheck][Col] != 0)
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
							if (DisplayBoard[rowcheck][Col - 1] != 0 || DisplayBoard[rowcheck][Col] != 0)
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
							if (DisplayBoard[rowcheck][Col - 1] != 0 || DisplayBoard[rowcheck][Col] != 0)
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
				while (DisplayBoard[Row][Col] == 0)
				{
					Row++;
					freePlace++;
				}

				if (freePlace >= SubMarineSize) {
					freePlace = SubMarineSize;
					while (DisplayBoard[_Row][_Col] == 0 && freePlace > 0) {
						DisplayBoard[_Row][_Col] = SubMarineSize;
						freePlace--;
						_Row++;
					}
					cout << " " + SubMarineName << "is ready and loaded for battle!" << endl;
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
							if (DisplayBoard[(Row + 1)][Colcheck] != 0)
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
							if (DisplayBoard[Row + 1][Colcheck] != 0)
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
							if (DisplayBoard[Row + 1][Colcheck] != 0)
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
							if (DisplayBoard[Row + 1][Colcheck] != 0 || DisplayBoard[Row - 1][Colcheck] != 0)
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
							if (DisplayBoard[Row + 1][Colcheck] != 0 || DisplayBoard[Row - 1][Colcheck] != 0)
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
							if (DisplayBoard[Row + 1][Colcheck] != 0 || DisplayBoard[Row - 1][Colcheck] != 0)
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
							if (DisplayBoard[Row - 1][Colcheck] != 0 || DisplayBoard[Row][Colcheck] != 0)
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
							if (DisplayBoard[Row - 1][Colcheck] != 0 || DisplayBoard[Row][Colcheck] != 0)
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
							if (DisplayBoard[Row - 1][Colcheck] != 0 || DisplayBoard[Row][Colcheck] != 0)
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
				while (DisplayBoard[Row][Col] == 0)
				{
					Col++;
					freePlace++;
				}

				if (freePlace >= SubMarineSize) {
					freePlace = SubMarineSize;
					while (DisplayBoard[_Row][_Col] == 0 && freePlace > 0) {
						DisplayBoard[_Row][_Col] = SubMarineSize;
						freePlace--;
						_Col++;
					}
					cout << " " + SubMarineName << "is ready and loaded for battle!" << endl;
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
							if (DisplayBoard[(Row + 1)][Colcheck] != 0 || DisplayBoard[Row][Colcheck] != 0)
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
							if (DisplayBoard[Row + 1][Colcheck] != 0 || DisplayBoard[Row][Colcheck] != 0)
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
							if (DisplayBoard[Row + 1][Colcheck] != 0 || DisplayBoard[Row][Colcheck] != 0)
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
							if (DisplayBoard[Row + 1][Colcheck] != 0 || DisplayBoard[Row - 1][Colcheck] != 0)
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
							if (DisplayBoard[Row + 1][Colcheck] != 0 || DisplayBoard[Row - 1][Colcheck] != 0 || DisplayBoard[Row][Colcheck] != 0)
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
							if (DisplayBoard[Row + 1][Colcheck] != 0 || DisplayBoard[Row - 1][Colcheck] != 0 || DisplayBoard[Row][Colcheck] != 0)
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
					if (_Row == SubMarineSize)
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
						for (int Colcheck = _Col; Colcheck < ((_Col - (SubMarineSize + 1))); Colcheck--)
						{
							if (DisplayBoard[Row - 1][Colcheck] != 0 || DisplayBoard[Row][Colcheck] != 0)
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
							if (DisplayBoard[Row - 1][Colcheck] != 0 || DisplayBoard[Row][Colcheck] != 0)
							{
								cout <<"Cant set Submrines close to each other"<< endl;
									return 0;
							}
						}
						break;

					}
					default:
					{
						for (int Colcheck = (_Col - 1); Colcheck < (((_Col - 1) + (SubMarineSize + 2))); Colcheck++)
						{
							if (DisplayBoard[Row - 1][Colcheck] != 0 || DisplayBoard[Row + 1][Colcheck] != 0)
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
				while (DisplayBoard[Row][Col] == 0)
				{
					Col--;
					freePlace++;
				}

				if (freePlace >= SubMarineSize) {
					freePlace = SubMarineSize;
					while (DisplayBoard[_Row][_Col] == 0 && freePlace > 0) {
						DisplayBoard[_Row][_Col] = SubMarineSize;
						freePlace--;
						_Col--;
					}
					cout << " " + SubMarineName << "is ready and loaded for battle!" << endl;
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

		
	
