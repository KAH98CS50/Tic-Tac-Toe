#include <iostream>
using namespace std;
const int ROWS=3;
const int COLUMNS=3;
//Functions 
void runGame();
void initialGameBoard(string gameBoard[ROWS][COLUMNS] );
void printCurrentBoard(string gameBoard[ROWS][COLUMNS] );
void getUserInput(bool xTurn,string gameBoard[ROWS][COLUMNS] );
bool cellAlreadyOccupied(int rows,int cols,string gameBoard[ROWS][COLUMNS] );
string getWinner(string gameBoard[ROWS][COLUMNS] );
bool isBoardFull(string gameBoard[ROWS][COLUMNS] );
int main(){
    runGame();
    return 0;
 
}
void runGame(){
    string winner="";
    bool xTurn=true;
    int theRow=0;
    int theCol=0;
    string gameboard[ROWS][COLUMNS];
    initialGameBoard(gameboard);
    printCurrentBoard(gameboard);
    while(winner==""){
        if (xTurn){
            cout<<"It's X's turn"<<endl;
        }
        else {
            cout<<"It's O's turn"<<endl;
        }
        getUserInput(xTurn,gameboard);
        cout<<endl;
        printCurrentBoard(gameboard);
        winner=getWinner(gameboard);
        xTurn=!xTurn;
        if (winner==""&&isBoardFull(gameboard)){
            winner="C";
        }

    }
    cout<<endl;
    if(winner=="C"){
        cout<<"It was the Cat's Game ! No Winner !"<<endl;
    }
    else {
        cout<<"The winner is "<<winner<<endl;
    }
    cout<<endl;
}
void initialGameBoard(string gameBoard[ROWS][COLUMNS] ){
    for (int i=0;i<ROWS;i++){
        for (int j=0;j<COLUMNS;j++){
            gameBoard[i][j]=" ";
        }
    }
}
void printCurrentBoard(string gameBoard[ROWS][COLUMNS] ){
    for (int i=0;i<ROWS;i++){
        for (int j=0;j<COLUMNS;j++){
            cout<<gameBoard[i][j];
            if(j<2){
                cout<<" | ";
            }
        }
        cout<<endl;
        if(i<2){
            cout<<"----------"<<endl;
        }
    }
    cout<<endl;
}
void getUserInput(bool xTurn,string gameBoard[ROWS][COLUMNS] ){
    int row=-1;
    int col=-1;
    bool keepAsking=true;
    while(keepAsking){
        cout<<"Please enter the row and col from (0 to 2) Separated by a space : "<<endl;
        cin>>row;
        cin>>col;
        if (row>=0 && col>=0 && row<=2 && col<=2){
            if (!cellAlreadyOccupied(row,col,gameBoard)){
                keepAsking=false;
            }
            else {
                cout<<"That cell is already occupied!"<<endl;
            }
        }
    }
    if(xTurn){
        gameBoard[row][col]="X";
    }
    else {
        gameBoard[row][col]="O";
    }
}
bool cellAlreadyOccupied(int rows,int cols,string gameBoard[ROWS][COLUMNS] ){
    return gameBoard[rows][cols]!=" ";
}
string getWinner(string gameBoard[ROWS][COLUMNS] ){
    //Check the rows
    for (int i=0;i<ROWS;i++){
        if (gameBoard[i][0]!=" "&&gameBoard[i][0]==gameBoard[i][1]&&gameBoard[i][1]==gameBoard[i][2]){
            return gameBoard[i][0];
        }
    }
    //Check for cols
    for (int j=0;j<COLUMNS;j++){
        if(gameBoard[0][j]!=" "&&gameBoard[0][j]==gameBoard[1][j] &&gameBoard[1][j]==gameBoard[2][j]){
            return gameBoard[0][j];
        }

        
    }
    //Upper-left to bottom right digonal
    if(gameBoard[0][0]!=" " && gameBoard[0][0]==gameBoard[1][1] && gameBoard[1][1]==gameBoard[2][2]){
        return gameBoard[0][0];
    }
    //Lower-left to upper right diagonal 
    if (gameBoard[2][0]!=" "&&gameBoard[2][0]==gameBoard[1][1] && gameBoard[1][1] ==gameBoard[0][2]){
        return gameBoard[2][0];
    }
    return "";
}

bool isBoardFull(string gameBoard[ROWS][COLUMNS] ){
    int countFill=0;
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLUMNS;j++){
            if (gameBoard[i][j]!=" "){
                countFill++;

            }
        }
    }
    return countFill==9;
}


