#pragma once
#include "Board.h"
//#include <Windows.h>
const string red("\033[0;31m");
const string green("\033[1;32m");
const string yellow("\033[1;33m");
const string cyan("\033[0;36m");
const string magenta("\033[0;35m");
const string reset("\033[0m");
Player User;
Player AI;
class MainClass
{
public:
	MainClass(){};
	~MainClass(){};
	void welcome()
	{
		for (int i = 0; i < 10; i++)
		{
			cout << red << "\t\t\t\t\tWelcome To Adi's SubMarine game" << reset;
			system("cls"); 
			cout << green << "\t\t\t\t\tWelcome To Adi's SubMarine game" << reset;
			system("cls"); 
			cout << yellow << "\t\t\t\t\tWelcome To Adi's SubMarine game" << reset;
			system("cls"); 
			cout << cyan << "\t\t\t\t\tWelcome To Adi's SubMarine game" << reset;
			system("cls"); 
			cout << red << "\t\t\t\t\tWelcome To Adi's SubMarine game" << reset;
			system("cls"); 
			cout << green << "\t\t\t\t\tWelcome To Adi's SubMarine game" << reset;
			system("cls"); 
			cout << yellow << "\t\t\t\t\tWelcome To Adi's SubMarine game" << reset;
			system("cls"); 
			cout << cyan << "\t\t\t\t\tWelcome To Adi's SubMarine game" << reset;
			system("cls"); 
			cout << red << "\t\t\t\t\tWelcome To Adi's SubMarine game" << reset;
			system("cls"); 
			cout << green << "\t\t\t\t\tWelcome To Adi's SubMarine game" << reset;
			system("cls"); 
			cout << yellow << "\t\t\t\t\tWelcome To Adi's SubMarine game" << reset;
			system("cls"); 
			cout << cyan << "\t\t\t\t\tWelcome To Adi's SubMarine game" << reset;
			system("cls"); 
			cout << red << "\t\t\t\t\tWelcome To Adi's SubMarine game" << reset;
			system("cls"); 
			cout << green << "\t\t\t\t\tWelcome To Adi's SubMarine game" << reset;
			system("cls"); 
			cout << yellow << "\t\t\t\t\tWelcome To Adi's SubMarine game" << reset;
			system("cls"); 
			cout << cyan << "\t\t\t\t\tWelcome To Adi's SubMarine game" << reset;
		}
		


	}
	int tryAttackPotentialTarget(int** _BoardStaus)
	{
		for (int Row = 0; Row < SIZE - 1; Row++)
		{
			for (int Col = 0; Col < SIZE - 1; Col++)
			{
				if (_BoardStaus[Row][Col] > 1)
				{
					playerBoardData.hit(Row + 1, Col + 1);
					return true;

				}

			}
		}
		return false;

	}
	void addSubMrinesToPlayer() {
		User.ClearVictor();
		for (int i = 0; i <= 4; i++) {
			User.addSubMarinetoplayer(new Destroyer());
			
		}
		for (int i = 0; i <= 2; i++) {
			User.addSubMarinetoplayer(new Cruiser());
			
		}

		User.addSubMarinetoplayer(new Battleship());
		User.addSubMarinetoplayer(new Battleship());
		User.addSubMarinetoplayer(new Carrier());

		

	}
	void addSubMrinesToAI() {
		AI.ClearVictor();
		for (int i = 0; i <= 4; i++) {
			AI.addSubMarinetoplayer(new Destroyer());

		}
		for (int i = 0; i <= 2; i++) {
			AI.addSubMarinetoplayer(new Cruiser());

		}

		AI.addSubMarinetoplayer(new Battleship());
		AI.addSubMarinetoplayer(new Battleship());
		AI.addSubMarinetoplayer(new Carrier());
		


	}
	void SetBoatsOnPlayerBoard()
	{
		addSubMrinesToPlayer();
		int opt;
		cout <<yellow<< "1.Place SubMarine Manually" << " 2.Let The PC Set";
		cin >> opt;
		switch (opt)
		{
		case 1:
		{
			int _Row = 0, _Col = 0, _Dir = 0;

			while (!User.getPlayerSubMarine().empty())
			{

				CurrentSub = User.getPlayerSubMarine().back();
				cout << "Please insert a Point (row,col) to place" << " " << CurrentSub->getSubMarinename() << " " << "size:" << CurrentSub->getSubMarineSize() << endl;
				cin >> _Row;
				cin >> _Col;
				cout << "please choose Direction(1.up 2.down 3.right 4.left)" << endl;
				cin >> _Dir;

				if (_Dir <= 0 || _Dir > 4)
				{
					cout << "Please insert a valid Direction 1<4" << endl;
					return;
				}


				if (playerBoardData.setSubMarine(CurrentSub, _Row, _Col, _Dir)) {
					User.removeSubMarinefromplayer();
				}
			}
			break;
		}
		case 2:
		{
			SetBoatsOnPlayerAuto();
			break;
		}

			break;
		}
		

	}

	void SetBoatsOnAIBoard() 
	{
		addSubMrinesToAI();
		int TryCount = 0;
		int _Row = 0, _Col = 0;
		int _Dir = 0;
		srand(time(NULL));

		while (!AI.getPlayerSubMarine().empty())
		{
			CurrentSub = AI.getPlayerSubMarine().back();
			_Row = rand() % 10 + 1;
			_Col = rand() % 10 + 1;
			_Dir = rand() % 4 + 1;



			if (AIBoardData.setAISubMarine(CurrentSub, _Row, _Col, _Dir) != 1) {
				TryCount++;
				continue;

			}
			else
			{
				AI.removeSubMarinefromplayer();
				system("cls");
				/*AIBoardData.printBoard();
				cout << "----**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-**-*" << endl;*/
			}
			if (TryCount > 100)
			{
			
				SetBoatsOnAIBoard();
			}
			else
			{
				continue;
			}



		}
		//AIBoardData.printBoard();
	}
	void SetBoatsOnPlayerAuto() {
		
		int TryCount = 0;
		int _Row = 0, _Col = 0;
		int _Dir = 0;
		srand(time(NULL));

		while (!User.getPlayerSubMarine().empty())
		{
			CurrentSub = User.getPlayerSubMarine().back();
			_Row = rand() % 10 + 1;
			_Col = rand() % 10 + 1;
			_Dir = rand() % 4 + 1;
			if (playerBoardData.setAISubMarine(CurrentSub, _Row, _Col, _Dir) != 1) {
				TryCount++;
				continue;

			}
			else
			{
				User.removeSubMarinefromplayer();
				system("cls");
			}
			if (TryCount > 100)
			{
				
				SetBoatsOnPlayerAuto();
			}
			else
			{
				continue;
			}



		}
		playerBoardData.printBoard();
		system("pause");
	}
	void playerattack() {
		AIBoardData.printBoardForPlayer();
		int Row = 0;
		int Col = 0;
		cout << "Try to hit The Enemey!" << endl;
		cin >> Row;
		cin >> Col;

		AIBoardData.hit(Row, Col);
		system("cls");
		AIBoardData.printBoardForPlayer();
		system("pause");
		system("cls");
	}
	void AIattack()
	{

		if (tryAttackPotentialTarget(playerBoardData.BoardStatus()))
		{
			playerBoardData.printBoardForAI();

		}
		else
		{

			int Row = 0;
			int Col = 0;
			Row = rand() % 10 + 1;
			Col = rand() % 10 + 1;
			playerBoardData.hit(Row, Col);
			system("cls");
			playerBoardData.printBoardForAI();
		}

		system("pause");
		//Sleep(5000);
		system("cls");
	}
	void startGame()
	{
		SetBoatsOnAIBoard();
		SetBoatsOnPlayerBoard();
		while (!(playerBoardData.gameEnded() || AIBoardData.gameEnded()))
		{
			playerattack();
			AIattack();

		}
		if (playerBoardData.gameEnded())
		{
			cout << "AI has won!!!";
		}
		else
		{
			cout << "Player has won!!!";
		}
		
	}

private:
	SubMarine* CurrentSub;
	Board AIBoardData = *new Board("AI Board");
	Board playerBoardData = *new Board("Player Board");
};

