#include "Board.h"
Player User;
Player AI;
Board playerBoard;
Board playerBoardData;
Board AIBoard;
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
    Submarine.setSubMarinename("Submarine");
    Submarine.setSubMarineSize(3);
    Destroyer.setSubMarinename("Destroyer");
    Destroyer.setSubMarineSize(2);

}
void addSubMrinesToUser() {
    for (int i = 0; i <= 3; i++) {
        User.addSubMarinetoplayer(Submarine);
    }
    for (int i = 0; i <= 2; i++) {
        User.addSubMarinetoplayer(Cruiser);
    }
    for (int i = 0; i <= 4; i++) {
        User.addSubMarinetoplayer(Destroyer);
    }
        User.addSubMarinetoplayer(Battleship);
        User.addSubMarinetoplayer(Battleship);
        User.addSubMarinetoplayer(Carrier);
    

}
void SetBoatsOnPlayerBoard() {
    int _Row, _Col;
    
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
    int _Row, _Col;

    while (!AI.getPlayerSubMarine().empty())
    {

        CurrentSub = AI.getPlayerSubMarine().back();
        cout << "Please insert a Point (row,col) to place" << " " << CurrentSub.getSubMarinename() << " " << "size:" << CurrentSub.getSubMarineSize() << endl;
        cin >> _Row;
        cin >> _Col;


        if (AIBoardData.setSubMarine(CurrentSub, _Row, _Col)) {
            AI.removeSubMarinefromplayer();
        }


    }
}




int main()
{
    setupSubMarines();
    addSubMrinesToUser();
    playerBoardData.printBoard();
    SetBoatsOnPlayerBoard();
    playerBoardData.printBoard();

    
}
