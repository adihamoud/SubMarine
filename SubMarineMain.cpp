#include "Board.h"


Player User;
Player AI;
Board playerBoardData;
Board AIBoardData;
SubMarine* CurrentSub;
//SubMarine Carrier;
//SubMarine Battleship;
//SubMarine Destroyer;
//SubMarine Submarine;
//SubMarine Cruiser;
//void setupSubMarines() {
//	Carrier Player1 = *new Carrier();
//	for (int i = 0; i <= 4; i++) {
//		User.addSubMarinetoplayer(new Destroyer());
//		AI.addSubMarinetoplayer(new Destroyer());
//	}
//	
//
//}
void addSubMrinesToPlayers() {

	for (int i = 0; i <= 4; i++) {
		User.addSubMarinetoplayer(new Destroyer());
		AI.addSubMarinetoplayer(new Destroyer());
	}
	User.addSubMarinetoplayer(new Battleship());
	User.addSubMarinetoplayer(new Battleship());
	User.addSubMarinetoplayer(new Carrier());

	AI.addSubMarinetoplayer(new Battleship());
	AI.addSubMarinetoplayer(new Battleship());
	AI.addSubMarinetoplayer(new Carrier());
	for (int i = 0; i <= 2; i++) {
		User.addSubMarinetoplayer(new Cruiser());
		AI.addSubMarinetoplayer(new Cruiser());
	}


}
void SetBoatsOnPlayerBoard() {
	int _Row = 0, _Col = 0;

	while (!User.getPlayerSubMarine().empty())
	{

		CurrentSub = User.getPlayerSubMarine().back();
		cout << "Please insert a Point (row,col) to place" << " " << CurrentSub->getSubMarinename() << " " << "size:" << CurrentSub->getSubMarineSize() << endl;
		cin >> _Row;
		cin >> _Col;


		if (playerBoardData.setSubMarine(CurrentSub, _Row, _Col)) {
			User.removeSubMarinefromplayer();
		}


	}
}
void SetBoatsOnAIBoard() {
	int _Row = 0, _Col = 0;
	int _Dir = 0;
	srand(time(NULL));

	while (!AI.getPlayerSubMarine().empty())
	{
		CurrentSub = AI.getPlayerSubMarine().back();
		_Row = rand() % 11 - 1 + 1;
		_Col = rand() % 11 - 1 + 1;
		_Dir = rand() % 4 - 1 + 1;


		if (AIBoardData.setAISubMarine(CurrentSub, _Row, _Col, _Dir) != 1) {

			continue;

		}
		else
		{
			AI.removeSubMarinefromplayer();
			AIBoardData.printBoard();
			cout << "----**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-**-*" << endl;
		}



	}
	AIBoardData.printBoard();
}




int main()
{
	playerBoardData = *new Board("Player Board");
	AIBoardData = *new Board("AI Board");
	//setupSubMarines();
	addSubMrinesToPlayers();
	playerBoardData.printBoard();
	SetBoatsOnPlayerBoard();
	SetBoatsOnAIBoard();
	//SetBoatsOnPlayerBoard();
	//playerBoardData.printBoard();


}
