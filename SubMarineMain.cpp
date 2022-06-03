#include "Board.h"

Player User;
Player AI;
Board playerBoardData;
Board AIBoardData;
SubMarine CurrentSub;
SubMarine Carrier; 
SubMarine Battleship;
SubMarine Destroyer;
SubMarine Submarine;
SubMarine Cruiser;
void setupSubMarines() {
    Carrier.setSubMarinename("Carrier");
    Carrier.setSubMarineSize(5);
    Battleship.setSubMarinename("Battleship");
    Battleship.setSubMarineSize(4);
    Cruiser.setSubMarinename("Cruiser");
    Cruiser.setSubMarineSize(3);
    Destroyer.setSubMarinename("Destroyer");
    Destroyer.setSubMarineSize(2);

}
void addSubMrinesToPlayers() {
    
    for (int i = 0; i <= 4; i++) {
        User.addSubMarinetoplayer(Destroyer);
        AI.addSubMarinetoplayer(Destroyer);
    }
        User.addSubMarinetoplayer(Battleship);
        User.addSubMarinetoplayer(Battleship);
        User.addSubMarinetoplayer(Carrier);

       AI.addSubMarinetoplayer(Battleship);
        AI.addSubMarinetoplayer(Battleship);
        AI.addSubMarinetoplayer(Carrier);
        for (int i = 0; i <= 2; i++) {
            User.addSubMarinetoplayer(Cruiser);
            AI.addSubMarinetoplayer(Cruiser);
        }
    

}
void SetBoatsOnPlayerBoard() {
    int _Row=0, _Col=0;
    
    while (!User.getPlayerSubMarine().empty())
    {

        CurrentSub = User.getPlayerSubMarine().back();
        cout << "Please insert a Point (row,col) to place" << " " << CurrentSub.getSubMarinename() << " " << "size:" << CurrentSub.getSubMarineSize() << endl;
        cin >> _Row;
        cin >> _Col;
       

        if (playerBoardData.setSubMarine(CurrentSub, _Row, _Col)) {
            User.removeSubMarinefromplayer();
        }

        
    }
}
void SetBoatsOnAIBoard() {
    int _Row=0, _Col=0;
    int _Dir=0;
    srand(time(NULL));

    while (!AI.getPlayerSubMarine().empty())
    {
        CurrentSub = AI.getPlayerSubMarine().back();
        _Row = rand() % 11 - 1 + 1;
        _Col = rand() % 11 - 1 + 1;
        _Dir = rand() % 4 - 1 + 1;


        if (AIBoardData.setAISubMarine(CurrentSub, _Row, _Col,_Dir)!=1) {

           continue ;
            
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
    playerBoardData = *new Board("Adi is gay");
    AIBoardData = *new Board("Adi is gay");
    setupSubMarines();
    addSubMrinesToPlayers();
    playerBoardData.printBoard();
    SetBoatsOnPlayerBoard();
    SetBoatsOnAIBoard();
    //SetBoatsOnPlayerBoard();
    //playerBoardData.printBoard();

    
}
