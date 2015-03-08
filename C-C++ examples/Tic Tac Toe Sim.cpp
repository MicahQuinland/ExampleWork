//============================================================================
// Name        : Tic Tac Toe Sim.cpp
// Author      : Juan Micah Quinland
// Version     :
// Description : Computer vs Computer 3D tic-tac-toe simulation
//				 Best of 10 games, my AI player vs my partners AI			 			
//============================================================================

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class classBoard {
      
public:
  void PrintBoard();
  void ComputerMoveX();
  int ComputerMoveO();
  void UserMoveO();
  void UserMoveX();  
  char spot[10];
  
  classBoard(){
     for(int r = 0; r < 10; r++){
      spot[r] = '_'; 
}
} // Create class and constructor
  ~classBoard(){
        cout << "Destructor\n";   
} // Destructor      
};

class classBoard3D {
   public:
    void PrintBoard3D();
    
    int ComputerMoveX3D(int iRandom);
    int ComputerMoveO3D();
    int UserMoveO3D(int iRandom);
    int UserMoveX3D(int iRandom);
    int ComputerScore(int iRandom);
    int UserScore(int iRandom);
    classBoard Board3D[4];
    int class_randomx;
    int class_temp;
    void clearboard();
   private:
               
};
//Travis's classes---------------------------
class ticTacToe
{
public:
       void clearBoard();
       void printBoard();
       void AI();
       int testWinner();
       char board[3][3];

};

//creates a derived class 
class ticTacToe3D
{
public:
       void AI3D();
       void player3D();
       void clearBoard3D();
       void printBoard3D();
       int testWinner3D();
       ticTacToe board3D[3];
       void tAI();
       int class_field;
       int class_row;
       int class_column;
       
       ticTacToe3D(){
       class_field =0;
       class_row = 0;
       class_column = 0;            
       }
       
};
//Competition class
class Competition {
  public:
  classBoard3D mcomBoard3D;
  ticTacToe3D tcomBoard3D; 
  int boardConv(int field, int row, int col);
  void bchange(int randomx, int temp);
  
}; 

int main(){
srand(time(NULL));
int iRandom = 0, z = 0, f = 0, g =0;
int temp = 4,x = 0,m = 0,c = 0,b = 0;
int randomx = 0, t = 0;
int row, col, field, choice, turn = 0;
iRandom = 1;
Competition comBoard;

           comBoard.tcomBoard3D.clearBoard3D(); // Clear garbage values
           while (f != 10){
           comBoard.mcomBoard3D.clearboard(); // Clears boards after new game
           comBoard.tcomBoard3D.clearBoard3D();      
           while (g != 1) {    
             comBoard.mcomBoard3D.ComputerMoveO3D();
             randomx = comBoard.mcomBoard3D.class_randomx;
             temp = comBoard.mcomBoard3D.class_temp;
             comBoard.bchange(randomx,temp); // Transfers boards
             z++;
             if (z == 14){break;}
             comBoard.tcomBoard3D.tAI();
             field = comBoard.tcomBoard3D.class_field;
             row = comBoard.tcomBoard3D.class_row;
             col = comBoard.tcomBoard3D.class_column;
             comBoard.boardConv(field,row,col); // Transfers boards
             }
             system("pause");
             system("cls");
             cout << "Game" << (f + 1);
             comBoard.mcomBoard3D.PrintBoard3D();
             c = 0;
             b = 0;
            c = comBoard.mcomBoard3D.ComputerScore(iRandom);
            b = comBoard.mcomBoard3D.UserScore(iRandom); 
            if ( b > c)
               {cout << "Micah Wins\n";
               m++;
               }
            else if (c > b)
               {cout << "Travis Wins\n";
               t++;
               }
            else {cout << "Draw\n";}              
             z = 0;
             f++;
}
if ( m > t) {cout << "\nMicah wins " << m << " out of 10 games, " << m-t << " more games than Travis\n"; }
else if ( t > m) {cout << "\nTravis wins " << t << " out of 10 games, " << t-m << " more games than Micah\n"; }
else {cout << "\nDraw, both Micah and Travis won "<< m << " games\n" ;}            
              
system("pause"); 
return 0;
}

void classBoard::PrintBoard() // print board fuction
{
cout << "\t\t\t     |     |\n"; 
cout << "\t\t\t  "<< spot[1] <<"  |  "<< spot[2] <<"  |  "<< spot[3] <<" \n"; 
cout << "\t\t\t_____|_____|_____\n";
cout << "\t\t\t     |     |\n"; 
cout << "\t\t\t  "<< spot[4] <<"  |  "<< spot[5] <<"  |  "<< spot[6] <<" \n"; 
cout << "\t\t\t_____|_____|_____\n";
cout << "\t\t\t     |     |\n"; 
cout << "\t\t\t  "<< spot[7] <<"  |  "<< spot[8] <<"  |  "<< spot[9] <<" \n"; 
cout << "\t\t\t     |     |     \n";
cout << endl << endl; 
}

void classBoard::ComputerMoveX() // Computer X move
{
   int temp = 0, x = 0;  
   for ( x=1; x<10; x++){
    if ((spot[x] != 'O') && (spot[x] != 'X') ){
      temp = x;
      spot[temp] = 'X';
      break;
} // End If
} // End For  
}

int classBoard::ComputerMoveO() // Computer O move
{
   int temp = 0, x = 0;  
   for ( x=1; x<10; x++){
    if ((spot[x] != 'O') && (spot[x] != 'X') ){
      temp = x;
      spot[temp] = 'O';
      break;
} // End If
} // End For  
}

void classBoard::UserMoveO() // User O move
{
   int f = 0,num = 0;
  cout << "Chose the location of your move\n";
        do {
              cin >> num;
              if ((spot[num] != 'O') && (spot[num] != 'X')){
              spot[num] = 'O';
              f = 1;
} // End If 
              else {
               cout << "invalid move";
} // End Else
} // End Do while
      while (f != 1);   
}

void classBoard::UserMoveX() // User X move
{
   int f = 0,num = 0;
  cout << "Chose the location of your move\n";
        do {
              cin >> num;
              if ((spot[num] != 'O') && (spot[num] != 'X')){
              spot[num] = 'X';
              f = 1;
} // End If 
              else {
               cout << "invalid move";
} // End Else
} // End Do while
      while (f != 1);   
}

void classBoard3D::PrintBoard3D() // print board fuction
{  
   Board3D[1].PrintBoard();
   cout << endl;
   Board3D[2].PrintBoard();
   cout << endl;
   Board3D[3].PrintBoard(); 
}

int classBoard3D::ComputerMoveX3D(int iRandom) // Checks valid board
{ int z = 0,randomx = 0,b = 0, c = 0;
while (z != 1){
randomx = (rand() % 3)+ 1;
if (((Board3D[randomx].spot[1] == 'X') || (Board3D[randomx].spot[1] == 'O')) &&
((Board3D[randomx].spot[2] == 'X') || (Board3D[randomx].spot[2] == 'O')) &&
((Board3D[randomx].spot[3] == 'X') || (Board3D[randomx].spot[3] == 'O')) &&
((Board3D[randomx].spot[4] == 'X') || (Board3D[randomx].spot[4] == 'O')) &&
((Board3D[randomx].spot[5] == 'X') || (Board3D[randomx].spot[5] == 'O')) &&
((Board3D[randomx].spot[6] == 'X') || (Board3D[randomx].spot[6] == 'O')) &&
((Board3D[randomx].spot[7] == 'X') || (Board3D[randomx].spot[7] == 'O')) &&
((Board3D[randomx].spot[8] == 'X') || (Board3D[randomx].spot[8] == 'O')) &&
((Board3D[randomx].spot[9] == 'X') || (Board3D[randomx].spot[9] == 'O'))
) {}
else {Board3D[randomx].ComputerMoveX(); z = 1;}
}
system("cls");       
PrintBoard3D();
cout << "\nUser score: ";
b = UserScore(iRandom);
cout << b;
cout << "\nComputer score: "; 
c = ComputerScore(iRandom);
cout << c;
cout << "\nUser's Turn  ";
system("pause");      
}

int classBoard3D::ComputerMoveO3D() // Checks valid board
{ int z = 0,randomx = 0,b = 0, c = 0;
while (z != 1){
randomx = (rand() % 3)+ 1;
if (((Board3D[randomx].spot[1] == 'X') || (Board3D[randomx].spot[1] == 'O')) &&
((Board3D[randomx].spot[2] == 'X') || (Board3D[randomx].spot[2] == 'O')) &&
((Board3D[randomx].spot[3] == 'X') || (Board3D[randomx].spot[3] == 'O')) &&
((Board3D[randomx].spot[4] == 'X') || (Board3D[randomx].spot[4] == 'O')) &&
((Board3D[randomx].spot[5] == 'X') || (Board3D[randomx].spot[5] == 'O')) &&
((Board3D[randomx].spot[6] == 'X') || (Board3D[randomx].spot[6] == 'O')) &&
((Board3D[randomx].spot[7] == 'X') || (Board3D[randomx].spot[7] == 'O')) &&
((Board3D[randomx].spot[8] == 'X') || (Board3D[randomx].spot[8] == 'O')) &&
((Board3D[randomx].spot[9] == 'X') || (Board3D[randomx].spot[9] == 'O'))
) {}
else {class_temp = Board3D[randomx].ComputerMoveO(); z = 1;}
}
class_randomx = randomx;
}

int classBoard3D::UserMoveO3D(int iRandom) // Checks valid board
{
int z = 0,bnum = 0,b = 0, c = 0;
cout << "Chose which board you would like to use.\n";
while (z != 1){
cin >> bnum;
if (((Board3D[bnum].spot[1] == 'X') || (Board3D[bnum].spot[1] == 'O')) &&
((Board3D[bnum].spot[2] == 'X') || (Board3D[bnum].spot[2] == 'O')) &&
((Board3D[bnum].spot[3] == 'X') || (Board3D[bnum].spot[3] == 'O')) &&
((Board3D[bnum].spot[4] == 'X') || (Board3D[bnum].spot[4] == 'O')) &&
((Board3D[bnum].spot[5] == 'X') || (Board3D[bnum].spot[5] == 'O')) &&
((Board3D[bnum].spot[6] == 'X') || (Board3D[bnum].spot[6] == 'O')) &&
((Board3D[bnum].spot[7] == 'X') || (Board3D[bnum].spot[7] == 'O')) &&
((Board3D[bnum].spot[8] == 'X') || (Board3D[bnum].spot[8] == 'O')) &&
((Board3D[bnum].spot[9] == 'X') || (Board3D[bnum].spot[9] == 'O'))
) {cout << "Board is Full";}
else if ((bnum == 1)||(bnum == 2)||(bnum == 3)) {z = 1;}
else {cout << "Invalid Board";}
}
Board3D[bnum].UserMoveO(); 
system("cls");       
PrintBoard3D();
cout << "\nUser score: ";
b = UserScore(iRandom);
cout << b;
cout << "\nComputer score: "; 
c = ComputerScore(iRandom);
cout << c;     
cout << "\nComputer's Turn  ";
system("pause");   
}

int classBoard3D::UserMoveX3D(int iRandom) // Checks valid board
{
int z = 0,bnum = 0,b = 0, c = 0;
cout << "Chose which board you would like to use.\n";
while (z != 1){
cin >> bnum;
if (((Board3D[bnum].spot[1] == 'X') || (Board3D[bnum].spot[1] == 'O')) &&
((Board3D[bnum].spot[2] == 'X') || (Board3D[bnum].spot[2] == 'O')) &&
((Board3D[bnum].spot[3] == 'X') || (Board3D[bnum].spot[3] == 'O')) &&
((Board3D[bnum].spot[4] == 'X') || (Board3D[bnum].spot[4] == 'O')) &&
((Board3D[bnum].spot[5] == 'X') || (Board3D[bnum].spot[5] == 'O')) &&
((Board3D[bnum].spot[6] == 'X') || (Board3D[bnum].spot[6] == 'O')) &&
((Board3D[bnum].spot[7] == 'X') || (Board3D[bnum].spot[7] == 'O')) &&
((Board3D[bnum].spot[8] == 'X') || (Board3D[bnum].spot[8] == 'O')) &&
((Board3D[bnum].spot[9] == 'X') || (Board3D[bnum].spot[9] == 'O'))
) {cout << "Board is Full";}
else if ((bnum == 1)||(bnum == 2)||(bnum == 3)) {z = 1;}
else {cout << "Invalid Board";}
}
Board3D[bnum].UserMoveX(); 
system("cls");       
PrintBoard3D();
cout << "\nUser score: ";
b = UserScore(iRandom);
cout << b;
cout << "\nComputer score: "; 
c = ComputerScore(iRandom);
cout << c;     
cout << "\nComputer's Turn  ";
system("pause");       
}

int classBoard3D::ComputerScore(int iRandom) // Computer ways to score
{ int c = 0,d = 0;
for (int d = 1; d <= 3; d++){
if ( iRandom == 2 && (Board3D[d].spot[1] == 'O' && Board3D[d].spot[2] == 'O' && Board3D[d].spot[3] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[d].spot[4] == 'O' && Board3D[d].spot[5] == 'O' && Board3D[d].spot[6] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[d].spot[7] == 'O' && Board3D[d].spot[8] == 'O' && Board3D[d].spot[9] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[d].spot[1] == 'O' && Board3D[d].spot[5] == 'O' && Board3D[d].spot[9] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[d].spot[3] == 'O' && Board3D[d].spot[5] == 'O' && Board3D[d].spot[7] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[d].spot[1] == 'O' && Board3D[d].spot[4] == 'O' && Board3D[d].spot[7] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[d].spot[2] == 'O' && Board3D[d].spot[5] == 'O' && Board3D[d].spot[8] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[d].spot[3] == 'O' && Board3D[d].spot[6] == 'O' && Board3D[d].spot[9] == 'O')) {c++;}
}

for (int d = 1; d <= 3; d++){
if ( iRandom == 1 && (Board3D[d].spot[1] == 'X' && Board3D[d].spot[2] == 'X' && Board3D[d].spot[3] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[d].spot[4] == 'X' && Board3D[d].spot[5] == 'X' && Board3D[d].spot[6] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[d].spot[7] == 'X' && Board3D[d].spot[8] == 'X' && Board3D[d].spot[9] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[d].spot[1] == 'X' && Board3D[d].spot[5] == 'X' && Board3D[d].spot[9] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[d].spot[3] == 'X' && Board3D[d].spot[5] == 'X' && Board3D[d].spot[7] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[d].spot[1] == 'X' && Board3D[d].spot[4] == 'X' && Board3D[d].spot[7] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[d].spot[2] == 'X' && Board3D[d].spot[5] == 'X' && Board3D[d].spot[8] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[d].spot[3] == 'X' && Board3D[d].spot[6] == 'X' && Board3D[d].spot[9] == 'X')) {c++;}
}

    for (int d = 1; d <= 9; d++){
if ( iRandom == 2 && (Board3D[1].spot[d] == 'O' && Board3D[2].spot[d] == 'O' && Board3D[3].spot[d] == 'O')) {c++;}
}

for (int d = 1; d <= 9; d++){
if ( iRandom == 1 && (Board3D[1].spot[d] == 'X' && Board3D[2].spot[d] == 'X' && Board3D[3].spot[d] == 'X')) {c++;}
}

if ( iRandom == 2 && (Board3D[1].spot[9] == 'O' && Board3D[2].spot[6] == 'O' && Board3D[3].spot[3] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[1].spot[8] == 'O' && Board3D[2].spot[5] == 'O' && Board3D[3].spot[2] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[1].spot[7] == 'O' && Board3D[2].spot[4] == 'O' && Board3D[3].spot[1] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[1].spot[3] == 'O' && Board3D[2].spot[6] == 'O' && Board3D[3].spot[9] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[1].spot[2] == 'O' && Board3D[2].spot[5] == 'O' && Board3D[3].spot[8] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[1].spot[1] == 'O' && Board3D[2].spot[4] == 'O' && Board3D[3].spot[7] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[1].spot[1] == 'O' && Board3D[2].spot[5] == 'O' && Board3D[3].spot[9] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[1].spot[7] == 'O' && Board3D[2].spot[5] == 'O' && Board3D[3].spot[3] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[1].spot[3] == 'O' && Board3D[2].spot[5] == 'O' && Board3D[3].spot[7] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[1].spot[9] == 'O' && Board3D[2].spot[5] == 'O' && Board3D[3].spot[1] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[1].spot[1] == 'O' && Board3D[2].spot[2] == 'O' && Board3D[3].spot[3] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[1].spot[2] == 'O' && Board3D[2].spot[5] == 'O' && Board3D[3].spot[6] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[1].spot[7] == 'O' && Board3D[2].spot[8] == 'O' && Board3D[3].spot[9] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[1].spot[3] == 'O' && Board3D[2].spot[2] == 'O' && Board3D[3].spot[1] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[1].spot[6] == 'O' && Board3D[2].spot[5] == 'O' && Board3D[3].spot[4] == 'O')) {c++;}
if ( iRandom == 2 && (Board3D[1].spot[9] == 'O' && Board3D[2].spot[8] == 'O' && Board3D[3].spot[7] == 'O')) {c++;}

if ( iRandom == 1 && (Board3D[1].spot[9] == 'X' && Board3D[2].spot[6] == 'X' && Board3D[3].spot[3] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[1].spot[8] == 'X' && Board3D[2].spot[5] == 'X' && Board3D[3].spot[2] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[1].spot[7] == 'X' && Board3D[2].spot[4] == 'X' && Board3D[3].spot[1] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[1].spot[3] == 'X' && Board3D[2].spot[6] == 'X' && Board3D[3].spot[9] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[1].spot[2] == 'X' && Board3D[2].spot[5] == 'X' && Board3D[3].spot[8] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[1].spot[1] == 'X' && Board3D[2].spot[4] == 'X' && Board3D[3].spot[7] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[1].spot[1] == 'X' && Board3D[2].spot[5] == 'X' && Board3D[3].spot[9] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[1].spot[7] == 'X' && Board3D[2].spot[5] == 'X' && Board3D[3].spot[3] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[1].spot[3] == 'X' && Board3D[2].spot[5] == 'X' && Board3D[3].spot[7] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[1].spot[9] == 'X' && Board3D[2].spot[5] == 'X' && Board3D[3].spot[1] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[1].spot[1] == 'X' && Board3D[2].spot[2] == 'X' && Board3D[3].spot[3] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[1].spot[2] == 'X' && Board3D[2].spot[5] == 'X' && Board3D[3].spot[6] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[1].spot[7] == 'X' && Board3D[2].spot[8] == 'X' && Board3D[3].spot[9] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[1].spot[3] == 'X' && Board3D[2].spot[2] == 'X' && Board3D[3].spot[1] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[1].spot[6] == 'X' && Board3D[2].spot[5] == 'X' && Board3D[3].spot[4] == 'X')) {c++;}
if ( iRandom == 1 && (Board3D[1].spot[9] == 'X' && Board3D[2].spot[8] == 'X' && Board3D[3].spot[7] == 'X')) {c++;}

return c;
}
int classBoard3D::UserScore(int iRandom) // User ways to score
{  int b = 0,d = 0;

for (int d = 1; d <= 3; d++){
if ( iRandom == 1 && (Board3D[d].spot[1] == 'O' && Board3D[d].spot[2] == 'O' && Board3D[d].spot[3] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[d].spot[4] == 'O' && Board3D[d].spot[5] == 'O' && Board3D[d].spot[6] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[d].spot[7] == 'O' && Board3D[d].spot[8] == 'O' && Board3D[d].spot[9] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[d].spot[1] == 'O' && Board3D[d].spot[5] == 'O' && Board3D[d].spot[9] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[d].spot[3] == 'O' && Board3D[d].spot[5] == 'O' && Board3D[d].spot[7] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[d].spot[1] == 'O' && Board3D[d].spot[4] == 'O' && Board3D[d].spot[7] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[d].spot[2] == 'O' && Board3D[d].spot[5] == 'O' && Board3D[d].spot[8] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[d].spot[3] == 'O' && Board3D[d].spot[6] == 'O' && Board3D[d].spot[9] == 'O')) {b++;}
}

for (int d = 1; d <= 3; d++){
if ( iRandom == 2 && (Board3D[d].spot[1] == 'X' && Board3D[d].spot[2] == 'X' && Board3D[d].spot[3] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[d].spot[4] == 'X' && Board3D[d].spot[5] == 'X' && Board3D[d].spot[6] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[d].spot[7] == 'X' && Board3D[d].spot[8] == 'X' && Board3D[d].spot[9] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[d].spot[1] == 'X' && Board3D[d].spot[5] == 'X' && Board3D[d].spot[9] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[d].spot[3] == 'X' && Board3D[d].spot[5] == 'X' && Board3D[d].spot[7] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[d].spot[1] == 'X' && Board3D[d].spot[4] == 'X' && Board3D[d].spot[7] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[d].spot[2] == 'X' && Board3D[d].spot[5] == 'X' && Board3D[d].spot[8] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[d].spot[3] == 'X' && Board3D[d].spot[6] == 'X' && Board3D[d].spot[9] == 'X')) {b++;}
}

for (int d = 1; d <= 9; d++){
if ( iRandom == 1 && (Board3D[1].spot[d] == 'O' && Board3D[2].spot[d] == 'O' && Board3D[3].spot[d] == 'O')) {b++;}
}

for (int d = 1; d <= 9; d++){
if ( iRandom == 2 && (Board3D[1].spot[d] == 'X' && Board3D[2].spot[d] == 'X' && Board3D[3].spot[d] == 'X')) {b++;}
}

if ( iRandom == 2 && (Board3D[1].spot[9] == 'X' && Board3D[2].spot[6] == 'X' && Board3D[3].spot[3] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[1].spot[8] == 'X' && Board3D[2].spot[5] == 'X' && Board3D[3].spot[2] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[1].spot[7] == 'X' && Board3D[2].spot[4] == 'X' && Board3D[3].spot[1] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[1].spot[3] == 'X' && Board3D[2].spot[6] == 'X' && Board3D[3].spot[9] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[1].spot[2] == 'X' && Board3D[2].spot[5] == 'X' && Board3D[3].spot[8] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[1].spot[1] == 'X' && Board3D[2].spot[4] == 'X' && Board3D[3].spot[7] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[1].spot[1] == 'X' && Board3D[2].spot[5] == 'X' && Board3D[3].spot[9] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[1].spot[7] == 'X' && Board3D[2].spot[5] == 'X' && Board3D[3].spot[3] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[1].spot[3] == 'X' && Board3D[2].spot[5] == 'X' && Board3D[3].spot[7] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[1].spot[9] == 'X' && Board3D[2].spot[5] == 'X' && Board3D[3].spot[1] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[1].spot[1] == 'X' && Board3D[2].spot[2] == 'X' && Board3D[3].spot[3] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[1].spot[2] == 'X' && Board3D[2].spot[5] == 'X' && Board3D[3].spot[6] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[1].spot[7] == 'X' && Board3D[2].spot[8] == 'X' && Board3D[3].spot[9] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[1].spot[3] == 'X' && Board3D[2].spot[2] == 'X' && Board3D[3].spot[1] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[1].spot[6] == 'X' && Board3D[2].spot[5] == 'X' && Board3D[3].spot[4] == 'X')) {b++;}
if ( iRandom == 2 && (Board3D[1].spot[9] == 'X' && Board3D[2].spot[8] == 'X' && Board3D[3].spot[7] == 'X')) {b++;}

if ( iRandom == 1 && (Board3D[1].spot[9] == 'O' && Board3D[2].spot[6] == 'O' && Board3D[3].spot[3] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[1].spot[8] == 'O' && Board3D[2].spot[5] == 'O' && Board3D[3].spot[2] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[1].spot[7] == 'O' && Board3D[2].spot[4] == 'O' && Board3D[3].spot[1] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[1].spot[3] == 'O' && Board3D[2].spot[6] == 'O' && Board3D[3].spot[9] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[1].spot[2] == 'O' && Board3D[2].spot[5] == 'O' && Board3D[3].spot[8] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[1].spot[1] == 'O' && Board3D[2].spot[4] == 'O' && Board3D[3].spot[7] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[1].spot[1] == 'O' && Board3D[2].spot[5] == 'O' && Board3D[3].spot[9] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[1].spot[7] == 'O' && Board3D[2].spot[5] == 'O' && Board3D[3].spot[3] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[1].spot[3] == 'O' && Board3D[2].spot[5] == 'O' && Board3D[3].spot[7] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[1].spot[9] == 'O' && Board3D[2].spot[5] == 'O' && Board3D[3].spot[1] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[1].spot[1] == 'O' && Board3D[2].spot[2] == 'O' && Board3D[3].spot[3] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[1].spot[2] == 'O' && Board3D[2].spot[5] == 'O' && Board3D[3].spot[6] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[1].spot[7] == 'O' && Board3D[2].spot[8] == 'O' && Board3D[3].spot[9] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[1].spot[3] == 'O' && Board3D[2].spot[2] == 'O' && Board3D[3].spot[1] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[1].spot[6] == 'O' && Board3D[2].spot[5] == 'O' && Board3D[3].spot[4] == 'O')) {b++;}
if ( iRandom == 1 && (Board3D[1].spot[9] == 'O' && Board3D[2].spot[8] == 'O' && Board3D[3].spot[7] == 'O')) {b++;}

return b;    
}

void classBoard3D::clearboard(){
    for (int d = 1; d <= 3; d++){
    for (int c = 1; c <= 9; c++){ 
        Board3D[d].spot[c] = '_';
    }   
        } 
}

void ticTacToe3D::clearBoard3D()
{
     board3D[0].clearBoard();
     board3D[1].clearBoard();
     board3D[2].clearBoard();
}

void ticTacToe::clearBoard()
{
     for(int r = 0; r < 3; r++)
     {
          for(int c = 0; c < 3; c++)
          {
               board[r][c] = ' ';
          }        
     }
}

//prints the 3D board to the player
void ticTacToe3D::printBoard3D()
{
     cout <<"Board 0";
     board3D[0].printBoard();
     cout <<"Board 1";
     board3D[1].printBoard();
     cout <<"Board 2";
     board3D[2].printBoard();    
}

void ticTacToe::printBoard()
{
     cout<<"\n";
     for(int r = 0; r < 3; r++)
     {
         for(int c = 0; c < 3; c++)
         {
                 cout<<"|"<<board[r][c]<<"|  ";
         }  
         cout<<"\n-------------\n";      
     }
             
} 

//function to control the players move
void ticTacToe3D::player3D()
{
    int field, row, column;     
    cout <<"\nWhich board do you want to make you move on (0,1,2)\n";
    cin>>field;
    cout<<"\nWhich row do you want to make your move in (0,1,2)\n";
    cin>>row;
    cout<<"\nWhich column do you want to make your move in (0,1,2)\n";
    cin>>column; 
    
    //checks for valid input
    if(field >= 0 && field <=3 && row >= 0 && row <=3 && column >= 0 && column <=3)
    {
        //checks if space is empty, if so, places a X
        if(board3D[field].board[row][column] == ' ')
        {
            board3D[field].board[row][column] = 'X';
        }
        else
        {
            cout << "Wrong Move!";
        }                         
    }
    else
    {
        cout << "Invalid Move!";
    }
            
}

//function to control the computer player
void ticTacToe3D::AI3D()
{
     bool condition = true;
     int row = 0;
     int column = 0;
     int field = 0;
     while(condition == true)
     {
          //Places an "O" in slot (0,0,0)
          //Choses a random slot to place an "O' if (0,0,0) is occupied
          if(board3D[field].board[row][column] != ' ')
          {
               time_t seconds;
               time(&seconds);
               srand((unsigned int) seconds);  
               column = rand()%3;
               row = rand()%3;
               field = rand()%3;     
          }
          else
          {
               board3D[field].board[row][column] = 'O';
               condition = false;   
          }//end if                                     
     }
}

void Competition::bchange(int randomx, int temp){
     int field = 0;
     field = (randomx - 1); 
    if (temp == 1) 
    {tcomBoard3D.board3D[field].board[0][0] = 'O';}
    else if (temp == 2)
    {tcomBoard3D.board3D[field].board[0][1] = 'O';}
    else if (temp == 3)
    {tcomBoard3D.board3D[field].board[0][2] = 'O';}
    else if (temp == 4)
    {tcomBoard3D.board3D[field].board[1][0] = 'O';}
    else if (temp == 5)
    {tcomBoard3D.board3D[field].board[1][1] = 'O';}
    else if (temp == 6)
    {tcomBoard3D.board3D[field].board[1][2] = 'O';}
    else if (temp == 7)
    {tcomBoard3D.board3D[field].board[2][0] = 'O';}
    else if (temp == 8)
    {tcomBoard3D.board3D[field].board[2][1] = 'O';}
    else
    {tcomBoard3D.board3D[field].board[2][2] = 'O';}
}
int Competition::boardConv(int field, int row, int col)
{
    int bnum, num;
    bnum = field + 1;
    if(row == 0 && col == 0)
       {num = 1;} 
    else if(row == 0 && col == 0)
       {num = 1;}
    else if(row == 0 && col == 1)
       {num = 2;}
    else if(row == 0 && col == 2)
       {num = 3;}
    else if(row == 1 && col == 0)
       {num = 4;}
    else if(row == 1 && col == 1)
       {num = 5;}
    else if(row == 1 && col == 2)
       {num = 6;}
    else if(row == 2 && col == 0)
       {num = 7;}
    else if(row == 2 && col == 1)
       {num = 8;}
    else if (row == 2 && col == 2)
       {num = 9;} 
    mcomBoard3D.Board3D[bnum].spot[num] = 'X';
}

//function to control travis' computer
void ticTacToe3D::tAI()
{
     bool condition = true;
     int row = 0;
     int column = 0;
     int field = 0;
     
     while(condition == true)
     {
          //Places an "O" in slot (0,0,0)
          //Choses a random slot to place an "O' if (0,0,0) is occupied
          if(board3D[field].board[row][column] != ' ')
          {   
              while (board3D[field].board[row][column] != ' '){
               field = rand()%3; 
               column = rand()%3;
               row = rand()%3;
               }                  
               class_field = field;
               class_row = row;
               class_column = column;
               board3D[field].board[row][column] = 'X';
          }
          else
          {
               board3D[field].board[row][column] = 'X';
               class_field = 0;
               class_row = 0;
               class_column = 0;
                  
          }
          
            
          condition = false;                                            
     }
}

