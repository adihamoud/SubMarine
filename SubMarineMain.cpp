#include "Board.h"


Player User;
Player AI;
SubMarine* CurrentSub;

Board AIBoardData = *new Board("AI Board");
Board playerBoardData = *new Board("Player Board");
void addSubMrinesToPlayers() {
	
	for (int i = 0; i <= 4; i++) {
		User.addSubMarinetoplayer(new Destroyer());
		AI.addSubMarinetoplayer(new Destroyer());
	}
	for (int i = 0; i <= 2; i++) {
		User.addSubMarinetoplayer(new Cruiser());
		AI.addSubMarinetoplayer(new Cruiser());
	}

	User.addSubMarinetoplayer(new Battleship());
	User.addSubMarinetoplayer(new Battleship());
	User.addSubMarinetoplayer(new Carrier());

	AI.addSubMarinetoplayer(new Battleship());
	AI.addSubMarinetoplayer(new Battleship());
	AI.addSubMarinetoplayer(new Carrier());
	

}
void SetBoatsOnPlayerBoard() {
	
	int _Row = 0, _Col = 0, _Dir=0;

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
			return ;
		}


		if (playerBoardData.setSubMarine(CurrentSub, _Row, _Col,_Dir)) {
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
		_Row = rand() % 10 + 1 ;
		_Col = rand() % 10 + 1 ;
		_Dir = rand() % 4 + 1;



		if (AIBoardData.setSubMarine(CurrentSub, _Row, _Col, _Dir) != 1) {

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
void playerattack() {
	int Row = 0;
	int Col = 0;
	cout << "Try to hit The Enemey!" << endl;
	cin >> Row;
	cin >> Col;

	AIBoardData.hit(Row, Col);
	AIBoardData.printBoardForPlayers();
}
void AIattack()
{

	int Row = 0;
	int Col = 0;
	cout << "Try to hit The Enemey!" << endl;
	cin >> Row;
	cin >> Col;

	playerBoardData.hit(Row, Col);
	playerBoardData.printBoardForPlayers();


}
int main()
{
	addSubMrinesToPlayers();
	SetBoatsOnAIBoard();
	while (!(playerBoardData.gameEnded() || AIBoardData.gameEnded()))
	{
		playerattack();
		

	}
	


}
