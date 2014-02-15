#include<windows.h>
#include<iostream>
#include<time.h>

//MAIN LINE 35
//TICTACTOE LINE 155
//PLUSMINUS LINE 1048
using namespace std;
//changing colors
void yellow();
void white();
void blue();
void green();
void red();
void cyan();

void tictactoe();
//tictactoe functions
bool filled(char a);
bool allfilled(bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h, bool i);

void plusminus();
//plusminus functions
void face(int d);
void facecom(int d);
void printcolored(int x);
void printboard();

void help();

//for plusminus functions
char J[501];
char dash[75], dash2[75], dashleft[75];

int main()
{
    int xm;
    double number;
    double exit;
    
    for(xm = 1; xm <= 8; xm++)
    {
           yellow();
           if(xm == 1)
           cout << "\n\n\t\tLoading.";
           else if(xm == 2)
           cout << "\n\n\t\tLoading..";
           else if(xm == 3)
           cout << "\n\n\t\tLoading...";
           else if(xm == 4)
           cout << "\n\n\t\tLoading....";
           else if(xm == 5)
           cout << "\n\n\t\tLoading.";
           else if(xm == 6)
           cout << "\n\n\t\tLoading..";
           else if(xm == 7)
           cout << "\n\n\t\tLoading...";
           else if(xm == 8)
           cout << "\n\n\t\tLoading Done!\n\n\t"; 
           else
           {
           }
           Sleep(500);//500
           if(xm == 8)
           {}
           else
           system("CLS");
    }
    system("PAUSE");
    do
    {
    Sleep(1000);
    system("CLS");
    do
    {
                  yellow();
                  cout << "\n\n\t[1]Play Tic-Tac-Toe\n";
                  blue();
                  cout << "\t[2]Play Plus or Minus <Snakes and Ladders>\n";
                  green();
                  cout << "\t[3]Help\n";
                  red();
                  cout << "\t[4]Exit\n";
                  cyan();
                  cout << "\tEnter No. : ";
                  cin >> number;
                  (int)number;
                  system("CLS");
    }while((number != 1) && (number != 2) && (number != 3) && (number != 4));
    
    if(number == 4)
    {
              system("CLS");
              do
              {
                            cout << "\n\nAre you sure you want to quit?<1 for YES, 0 for NO>: ";
                            cin >> exit;
                            (int)exit;
              }while((exit != 1) && (exit != 0));
              
              if(exit == 0)
              number = 0;
              else
              {
              }
    }
    else if(number == 3)
    {
         help();
    }
    //PLUSMINUS GAME
    else if(number == 2)
    {
         plusminus();
    }
    //TICTACTOE GAME
    else
    {
        tictactoe();
    }
    }while(number != 4);
    
    return 0;
}

//DEFINED FUNCTIONS
void yellow()
{
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); 
}

void white()
{
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); 
}

void green()
{
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); 
}

void red()
{
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); 
}

void blue()
{
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); 
}

void cyan()
{
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); 
}
//TICTACTOE and its functions
//tictactoe code
void tictactoe()
{
     cyan();
    bool A1, A2, A3, B1, B2, B3, C1, C2, C3;
    bool win, lose, draw, invalid;
    bool all, none;
    char A[11], B[20], C[20];
    int row, col, x;
    A1 = false;
    A2 = false;
    A3 = false;
    B1 = false;
    B2 = false;
    B3 = false;
    C1 = false;
    C2 = false;
    C3 = false;

    A[0] = ' ';
    A[1] = ' ';
    A[2] = ' ';
    A[3] = '|';
    A[4] = ' ';
    A[5] = ' ';
    A[6] = ' ';
    A[7] = '|';
    A[8] = ' ';
    A[9] = ' ';
    A[10] = ' ';
    B[0] = ' ';
    B[1] = ' ';
    B[2] = ' ';
    B[3] = '|';
    B[4] = ' ';
    B[5] = ' ';
    B[6] = ' ';
    B[7] = '|';
    B[8] = ' ';
    B[9] = ' ';
    B[10] = ' ';
    C[0] = ' ';
    C[1] = ' ';
    C[2] = ' ';
    C[3] = '|';
    C[4] = ' ';
    C[5] = ' ';
    C[6] = ' ';
    C[7] = '|';
    C[8] = ' ';
    C[9] = ' ';
    C[10] = ' ';
    
    win = false;
    lose = false;
    draw = false;
    
    //[1][5][9] - COLUMNS
    x = 1;
    do
    {
                do
                {
                //PRINT BOARD (tictactoe)
                cout << "   1   2   3 \n";
                cout << "1 " << A << endl;
                cout << "  ---+---+---" << endl;
                cout << "2 " << B << endl;
                cout << "  ---+---+---" << endl;
                cout << "3 " << C << endl;
                //INPUT POSITION
                
                invalid = false;        
                        
                do
                {
                        cout << "\nX is 1st, 2nd or 3rd row (1, 2 or 3)? "; 
                        cin >> row;
                
                        cout << "\nX is 1st, 2nd or 3rd column (1, 2 or 3)? "; 
                        cin >> col;
                        if(((row < 1) || (row > 3)) || ((col < 1) || (col > 3)))
                        {
                                 system("CLS");
                                 cout << "INVALID move!\n";
                                 cout << "Row = " << row << endl;
                                 cout << "Column = " << col << endl;
                                 cout << "Both should be integers between 1 and 3\n";
                                 //PRINT BOARD (tictactoe)
                                 cout << "   1   2   3 \n";
                                 cout << "1 " << A << endl;
                                 cout << "  ---+---+---" << endl;
                                 cout << "2 " << B << endl;
                                 cout << "  ---+---+---" << endl;
                                 cout << "3 " << C << endl;
                                 system("PAUSE");
                                 system("CLS");
                                 cout << "   1   2   3 \n";
                                 cout << "1 " << A << endl;
                                 cout << "  ---+---+---" << endl;
                                 cout << "2 " << B << endl;
                                 cout << "  ---+---+---" << endl;
                                 cout << "3 " << C << endl;
                        }
                        else
                        {
                        }
                }while(((row < 1) || (row > 3)) || ((col < 1) || (col > 3)));
                
                //CHECKS IF FILLED ALREADY
                A1 = filled(A[1]);
                A2 = filled(A[5]);
                A3 = filled(A[9]);
                B1 = filled(B[1]);
                B2 = filled(B[5]);
                B3 = filled(B[9]);
                C1 = filled(C[1]);
                C2 = filled(C[5]);
                C3 = filled(C[9]);
                //MOVES
                //1ST ROW
                if((row == 1) && (col == 1) && (A1 == false))
                {
                        A[1] = 'X';
                }
                else if((row == 1) && (col == 2) && (A2 == false))
                {
                     A[5] = 'X';
                }
                else if((row == 1) && (col == 3) && (A3 == false))
                {
                     A[9] = 'X';
                }
                //2ND ROW
                else if((row == 2) && (col == 1) && (B1 == false))
                {
                     B[1] = 'X';
                }
                else if((row == 2) && (col == 2) && (B2 == false))
                {
                     B[5] = 'X';
                }
                else if((row == 2) && (col == 3) && (B3 == false))
                {
                     B[9] = 'X';
                }
                //3RD ROW
                else if((row == 3) && (col == 1) && (C1 == false))
                {
                     C[1] = 'X';
                }
                else if((row == 3) && (col == 2) && (C2 == false))
                {
                     C[5] = 'X';
                }
                else if((row == 3) && (col == 3) && (C3 == false))
                {
                     C[9] = 'X';
                }
                else
                {
                    invalid = true;
                    system("CLS");
                    yellow();
                    cout << "\nBox already FILLED!\n" << endl;
                    cyan();
                    cout << "   1   2   3 \n";
                    cout << "1 " << A << endl;
                    cout << "  ---+---+---" << endl;
                    cout << "2 " << B << endl;
                    cout << "  ---+---+---" << endl;
                    cout << "3 " << C << endl;
                    system("PAUSE");
                    
                }
                
                //TIME DELAY(1 SECOND)
                if(invalid == false)
                {
                              yellow();
                              cout << "COMPUTER's turn...";
                              cyan();
                              Sleep(1000);
                }
                else
                {
                }
                system("CLS");
                }while(invalid == true);
                
                
                //COMPUTER'S MOVES
                /* if first move is in the corner and edges
                 X | X | X 
                ---+---+---
                 X |   | X 
                ---+---+---
                 X | X | X 
                 computer will always attack middle
                 */
                if((A[1] == 'X') && (A[5] == ' ') && (A[9] == ' ') && (B[1] == ' ') && (B[5] == ' ') && (B[9] == ' ') && (C[1] == ' ') && (C[5] == ' ') && (C[9] == ' ')) 
                {
                         B[5] = 'O';
                         
                }
                else if((A[1] == ' ') && (A[5] == 'X') && (A[9] == ' ') && (B[1] == ' ') && (B[5] == ' ') && (B[9] == ' ') && (C[1] == ' ') && (C[5] == ' ') && (C[9] == ' '))
                {
                     B[5] = 'O';
                }
                else if((A[1] == ' ') && (A[5] == ' ') && (A[9] == 'X') && (B[1] == ' ') && (B[5] == ' ') && (B[9] == ' ') && (C[1] == ' ') && (C[5] == ' ') && (C[9] == ' '))
                {
                     B[5] = 'O';
                }
                else if((A[1] == ' ') && (A[5] == ' ') && (A[9] == ' ') && (B[1] == 'X') && (B[5] == ' ') && (B[9] == ' ') && (C[1] == ' ') && (C[5] == ' ') && (C[9] == ' '))
                {
                     B[5] = 'O';
                }
                else if((A[1] == ' ') && (A[5] == ' ') && (A[9] == ' ') && (B[1] == ' ') && (B[5] == ' ') && (B[9] == 'X') && (C[1] == ' ') && (C[5] == ' ') && (C[9] == ' '))
                {
                     B[5] = 'O';
                }
                else if((A[1] == ' ') && (A[5] == ' ') && (A[9] == ' ') && (B[1] == ' ') && (B[5] == ' ') && (B[9] == ' ') && (C[1] == ' ') && (C[5] == ' ') && (C[9] == 'X'))
                {
                     B[5] = 'O';
                }
                else if((A[1] == ' ') && (A[5] == ' ') && (A[9] == ' ') && (B[1] == ' ') && (B[5] == ' ') && (B[9] == ' ') && (C[1] == ' ') && (C[5] == 'X') && (C[9] == ' '))
                {
                     B[5] = 'O';
                }
                else if((A[1] == ' ') && (A[5] == ' ') && (A[9] == ' ') && (B[1] == ' ') && (B[5] == ' ') && (B[9] == ' ') && (C[1] == 'X') && (C[5] == ' ') && (C[9] == ' '))
                {
                     B[5] = 'O';
                }
                /*first move middle
                   |   |   
                ---+---+---
                   | X |   
                ---+---+---
                   |   |   
                 computer will always attack bottom left
                 */
                else if((A[1] == ' ') && (A[5] == ' ') && (A[9] == ' ') && (B[1] == ' ') && (B[5] == 'X') && (B[9] == ' ') && (C[1] == ' ') && (C[5] == ' ') && (C[9] == ' '))
                {
                     C[1] = 'O';
                }
                else
                {
                }
                
                //COMPUTER'S MOVE WHICH COMPLETES THREE(if any) FIRST BEFORE BLOCKING
                //COMPLETES THREE
                //HORIZONTAL
                if((A[1] == 'O') && (A[5] == 'O') && (A[9] == ' '))
                {
                         A[9] = 'O';
                }
                else if((B[1] == 'O') && (B[5] == 'O') && (B[9] == ' '))
                {
                     B[9] = 'O';
                }
                else if((C[1] == 'O') && (C[5] == 'O') && (C[9] == ' '))
                {
                     C[9] = 'O';
                }
                else if((A[5] == 'O') && (A[9] == 'O') && (A[1] == ' '))
                {
                     A[1] = 'O';
                }
                else if((B[5] == 'O') && (B[9] == 'O') && (B[1] == ' '))
                {
                     B[1] = 'O';
                }
                else if((C[5] == 'O') && (C[9] == 'O') && (C[1] == ' '))
                {
                     C[1] = 'O';
                }
                else if((A[1] == 'O') && (A[9] == 'O') && (A[5] == ' '))
                {
                     A[5] = 'O';
                }
                else if((B[1] == 'O') && (B[9] == 'O') && (B[5] == ' '))
                {
                     B[5] = 'O';
                }
                else if((C[1] == 'O') && (C[9] == 'O') && (C[5] == ' '))
                {
                     C[5] = 'O';
                }
                //VERTICAL
                else if((A[1] == 'O') && (B[1] == 'O') && (C[1] == ' '))
                {
                     C[1] = 'O';
                }
                else if((A[5] == 'O') && (B[5] == 'O') && (C[5] == ' '))
                {
                     C[5] = 'O';
                }
                else if((A[9] == 'O') && (B[9] == 'O') && (C[9] == ' '))
                {
                     C[9] = 'O';
                }
                else if((A[1] == ' ') && (B[1] == 'O') && (C[1] == 'O'))
                {
                     A[1] = 'O';
                }
                else if((A[5] == ' ') && (B[5] == 'O') && (C[5] == 'O'))
                {
                     A[5] = 'O';
                }
                else if((A[9] == ' ') && (B[9] == 'O') && (C[9] == 'O'))
                {
                     A[9] = 'O';
                }
                else if((A[1] == 'O') && (B[1] == ' ') && (C[1] == 'O'))
                {
                     B[1] = 'O';
                }
                else if((A[5] == 'O') && (B[5] == ' ') && (C[5] == 'O'))
                {
                     B[5] = 'O';
                }
                else if((A[9] == 'O') && (B[9] == ' ') && (C[9] == 'O'))
                {
                     B[9] = 'O';
                }
                //DIAGONAL
                else if((A[1] == 'O') && (B[5] == 'O') && (C[9] == ' '))
                {
                     C[9] = 'O';
                }
                else if((A[1] == 'O') && (B[5] == ' ') && (C[9] == 'O'))
                {
                     B[5] = 'O';
                }
                else if((A[1] == ' ') && (B[5] == 'O') && (C[9] == 'O'))
                {
                     A[1] = 'O';
                }
                else if((C[1] == 'O') && (B[5] == 'O') && (A[9] == ' '))
                {
                     A[9] = 'O';
                }
                else if((C[1] == 'O') && (B[5] == ' ') && (A[9] == 'O'))
                {
                     B[5] = 'O';
                }
                else if((C[1] == ' ') && (B[5] == 'O') && (A[9] == 'O'))
                {
                     C[1] = 'O';
                }
                //BLOCKS
                //HORIZONTAL
                else if((A[1] == 'X') && (A[5] == 'X') && (A[9] == ' '))
                {
                         A[9] = 'O';
                }
                else if((B[1] == 'X') && (B[5] == 'X') && (B[9] == ' '))
                {
                     B[9] = 'O';
                }
                else if((C[1] == 'X') && (C[5] == 'X') && (C[9] == ' '))
                {
                     C[9] = 'O';
                }
                else if((A[5] == 'X') && (A[9] == 'X') && (A[1] == ' '))
                {
                     A[1] = 'O';
                }
                else if((B[5] == 'X') && (B[9] == 'X') && (B[1] == ' '))
                {
                     B[1] = 'O';
                }
                else if((C[5] == 'X') && (C[9] == 'X') && (C[1] == ' '))
                {
                     C[1] = 'O';
                }
                else if((A[1] == 'X') && (A[9] == 'X') && (A[5] == ' '))
                {
                     A[5] = 'O';
                }
                else if((B[1] == 'X') && (B[9] == 'X') && (B[5] == ' '))
                {
                     B[5] = 'O';
                }
                else if((C[1] == 'X') && (C[9] == 'X') && (C[5] == ' '))
                {
                     C[5] = 'O';
                }
                //VERTICAL
                else if((A[1] == 'X') && (B[1] == 'X') && (C[1] == ' '))
                {
                     C[1] = 'O';
                }
                else if((A[5] == 'X') && (B[5] == 'X') && (C[5] == ' '))
                {
                     C[5] = 'O';
                }
                else if((A[9] == 'X') && (B[9] == 'X') && (C[9] == ' '))
                {
                     C[9] = 'O';
                }
                else if((A[1] == ' ') && (B[1] == 'X') && (C[1] == 'X'))
                {
                     A[1] = 'O';
                }
                else if((A[5] == ' ') && (B[5] == 'X') && (C[5] == 'X'))
                {
                     A[5] = 'O';
                }
                else if((A[9] == ' ') && (B[9] == 'X') && (C[9] == 'X'))
                {
                     A[9] = 'O';
                }
                else if((A[1] == 'X') && (B[1] == ' ') && (C[1] == 'X'))
                {
                     B[1] = 'O';
                }
                else if((A[5] == 'X') && (B[5] == ' ') && (C[5] == 'X'))
                {
                     B[5] = 'O';
                }
                else if((A[9] == 'X') && (B[9] == ' ') && (C[9] == 'X'))
                {
                     B[9] = 'O';
                }
                //DIAGONAL
                else if((A[1] == 'X') && (B[5] == 'X') && (C[9] == ' '))
                {
                     C[9] = 'O';
                }
                else if((A[1] == 'X') && (B[5] == ' ') && (C[9] == 'X'))
                {
                     B[5] = 'O';
                }
                else if((A[1] == ' ') && (B[5] == 'X') && (C[9] == 'X'))
                {
                     A[1] = 'O';
                }
                else if((C[1] == 'X') && (B[5] == 'X') && (A[9] == ' '))
                {
                     A[9] = 'O';
                }
                else if((C[1] == 'X') && (B[5] == ' ') && (A[9] == 'X'))
                {
                     B[5] = 'O';
                }
                else if((C[1] == ' ') && (B[5] == 'X') && (A[9] == 'X'))
                {
                     C[1] = 'O';
                }
                /*STRATEGIES
                   | X |          | X |     
                ---+---+---    ---+---+---  
                 O | O | X      X | O | X   
                ---+---+---    ---+---+---  
                   | X |          | O |    
                */
                else if((A[5] == 'X') && (B[5] == 'O') && (C[5] == 'X') && (B[1] == 'O') && (B[9] == 'X') && (C[1] == ' '))
                {
                     C[1] = 'O';
                }
                else if((B[1] == 'X') && (B[5] == 'O') && (B[9] == 'X') && (C[5] == 'O') && (A[5] == 'X') && (C[9] == ' '))
                {
                     C[9] = 'O';
                }
                
                //OTHER POSSIBLE MOVES AND STRATEGIES(WITHOUT SUDDEN OFFENSE AND HIDDEN X's and O's)
                /*
                 X |   |          |   | X    X |   |          |   | X      |   |          |   |   
                ---+---+---    ---+---+---  ---+---+---    ---+---+---  ---+---+---    ---+---+---
                   | O |          | O |        | O | X      X | O |        | O | X      X | O |   
                ---+---+---    ---+---+---  ---+---+---    ---+---+---  ---+---+---    ---+---+---
                   |   | X      X |   |        |   |          |   |      X |   |          |   | X 
                 */
                else if((A[1] == 'X') && (B[5] == 'O') && (C[9] == 'X') && (B[1] == ' '))
                {
                     B[1] = 'O';
                }
                else if((A[9] == 'X') && (B[5] == 'O') && (C[1] == 'X') && (B[1] == ' '))
                {
                     B[1] = 'O';
                }
                else if((A[1] == 'X') && (B[5] == 'O') && (B[9] == 'X') && (C[5] == ' '))
                {
                     C[5] = 'O';
                }
                else if((A[9] == 'X') && (B[5] == 'O') && (B[1] == 'X') && (C[5] == ' '))
                {
                     C[5] = 'O';
                }
                else if((C[1] == 'X') && (B[5] == 'O') && (B[9] == 'X') && (C[5] == ' '))
                {
                     C[5] = 'O';
                }
                else if((C[9] == 'X') && (B[5] == 'O') && (B[1] == 'X') && (C[5] == ' '))
                {
                     C[5] = 'O';
                }
                /*
                   | X |          | X |        |   | X      X |   |   
                ---+---+---    ---+---+---  ---+---+---    ---+---+---
                   | O |          | O |        | O |          | O |   
                ---+---+---    ---+---+---  ---+---+---    ---+---+---
                   |   | X      X |   |        | X |          | X |    
                */
                else if((A[5] == 'X') && (B[5] == 'O') && (C[9] == 'X') && (A[9] == ' '))
                {
                     A[9] = 'O';
                }
                else if((A[5] == 'X') && (B[5] == 'O') && (C[1] == 'X') && (A[1] == ' '))
                {
                     A[1] = 'O';
                }
                else if((C[5] == 'X') && (B[5] == 'O') && (A[9] == 'X') && (C[9] == ' '))
                {
                     C[9] = 'O';
                }
                else if((C[5] == 'X') && (B[5] == 'O') && (A[1] == 'X') && (C[1] == ' '))
                {
                     C[1] = 'O';
                }
                /*
                   | X |          | X |        |   |          |   |   
                ---+---+---    ---+---+---  ---+---+---    ---+---+---
                   | O | X      X | O |        | O | X      X | O |   
                ---+---+---    ---+---+---  ---+---+---    ---+---+---
                   |   |          |   |        | X |          | X |    
                */
                else if((A[5] == 'X') && (B[5] == 'O') && (B[9] == 'X') && (C[9] == ' '))
                {
                     C[9] = 'O';
                }
                else if((A[5] == 'X') && (B[5] == 'O') && (B[1] == 'X') && (C[1] == ' '))
                {
                     C[1] = 'O';
                }
                else if((C[5] == 'X') && (B[5] == 'O') && (B[9] == 'X') && (C[1] == ' '))
                {
                     C[1] = 'O';
                }
                else if((C[5] == 'X') && (B[5] == 'O') && (B[1] == 'X') && (C[9] == ' '))
                {
                     C[9] = 'O';
                }
                /* if position
                   | X |          |   |     
                ---+---+---    ---+---+---  
                   | O |        X | O | X   
                ---+---+---    ---+---+---  
                   | X |          |   |     
                */
                else if((A[5] == 'X') && (B[5] == 'O') && (C[5] == 'X') && (B[1] == ' '))
                {
                     B[1] = 'O';
                }
                else if((B[1] == 'X') && (B[5] == 'O') && (B[9] == 'X') && (C[5] == ' '))
                {
                     C[5] = 'O';
                }
                /* if position
                     |   | X   
                  ---+---+---  
                     | X |     
                  ---+---+---  
                   O |   |     
                
                */
                else if((A[9] == 'X') && (B[5] == 'X') && (C[1] == 'O') && (C[9] == ' '))
                {
                     C[9] = 'O';
                }
                //CHECKS IF ALL FILLED ALREADY(FOR 2 BOXES LEFT FOR DRAW)
                A1 = filled(A[1]);
                A2 = filled(A[5]);
                A3 = filled(A[9]);
                B1 = filled(B[1]);
                B2 = filled(B[5]);
                B3 = filled(B[9]);
                C1 = filled(C[1]);
                C2 = filled(C[5]);
                C3 = filled(C[9]);
                //NO CHOICE(2 BOXES LEFT FOR DRAW)
                /* if position
                   ? | ? | ?     ? |   | ?         |   | ?     ? |   |    
                  ---+---+---   ---+---+---     ---+---+---   ---+---+--- 
                     | ? |       ? | ? | ?       ? | ? | ?     ? | ? | ?  
                  ---+---+---   ---+---+---     ---+---+---   ---+---+--- 
                   ? | ? | ?     ? |   | ?       ? | ? | ?     ? | ? | ?  
                
                */
                if((B[1] == ' ') && (B[9] == ' ') && (A1 == true) && (A2 == true) && (A3 == true) && (B2 == true) && (C1 == true) && (C2 == true) && (C3 == true))
                {
                     B[1] = 'O';
                }
                else if((A[5] == ' ') && (C[5] == ' ') && (A1 == true) && (B1 == true) && (A3 == true) && (B2 == true) && (C1 == true) && (B3 == true) && (C3 == true))
                {
                     A[5] = 'O';
                }
                else if((A[1] == ' ') && (A[5] == ' ') && (C2 == true) && (B1 == true) && (A3 == true) && (B2 == true) && (C1 == true) && (B3 == true) && (C3 == true))
                {
                     A[1] = 'O';
                }
                else if((A[5] == ' ') && (A[9] == ' ') && (C2 == true) && (B1 == true) && (A1 == true) && (B2 == true) && (C1 == true) && (B3 == true) && (C3 == true))
                {
                     A[9] = 'O';
                }
                
                
                //HORIZONTAL WIN
                if(((A[1] == 'X') && (A[5] == 'X') && (A[9] == 'X')) || ((B[1] == 'X') && (B[5] == 'X') && (B[9] == 'X')) || ((C[1] == 'X') && (C[5] == 'X') && (C[9] == 'X')))
                {
                     win = true;
                }
                //VERTICAL WIN
                else if(((A[1] == 'X') && (B[1] == 'X') && (C[1] == 'X')) || ((A[5] == 'X') && (B[5] == 'X') && (C[5] == 'X')) || ((A[9] == 'X') && (B[9] == 'X') && (C[9] == 'X')))
                {
                     win = true;
                }
                //DIAGONAL WIN
                else if(((A[1] == 'X') && (B[5] == 'X') && (C[9] == 'X')) || ((A[9] == 'X') && (B[5] == 'X') && (C[1] == 'X')))
                {
                     win = true;
                }
                //HORIZONTAL LOSE
                else if(((A[1] == 'O') && (A[5] == 'O') && (A[9] == 'O')) || ((B[1] == 'O') && (B[5] == 'O') && (B[9] == 'O')) || ((C[1] == 'O') && (C[5] == 'O') && (C[9] == 'O')))
                {
                     lose = true;
                }
                //VERTICAL LOSE
                else if(((A[1] == 'O') && (B[1] == 'O') && (C[1] == 'O')) || ((A[5] == 'O') && (B[5] == 'O') && (C[5] == 'O')) || ((A[9] == 'O') && (B[9] == 'O') && (C[9] == 'O')))
                {
                     lose = true;
                }
                //DIAGONAL LOSE
                else if(((A[1] == 'O') && (B[5] == 'O') && (C[9] == 'O')) || ((A[9] == 'O') && (B[5] == 'O') && (C[1] == 'O')))
                {
                     lose = true;
                }
                else
                {
                }
                //CHECKS IF ALL FILLED ALREADY(FOR DRAW)
                A1 = filled(A[1]);
                A2 = filled(A[5]);
                A3 = filled(A[9]);
                B1 = filled(B[1]);
                B2 = filled(B[5]);
                B3 = filled(B[9]);
                C1 = filled(C[1]);
                C2 = filled(C[5]);
                C3 = filled(C[9]);
                all = allfilled(A1, A2, A3, B1, B2, B3, C1, C2, C3);
                //CHECKS IF DRAW
                if((all == true) && (lose == false) && (win == false))
                {
                        draw = true;
                }
                else
                {
                }
                //CLEARS THE SCREEN EVERYTIME IT LOOPS
                system("CLS");
    }while((win == false) && (lose == false) && (draw == false));
    
    
    //OUTPUT FOR WIN LOSE DRAW
    
    if(win)
    {
           yellow();
           system("msg * You WON!");
           cout << "\nYou WON!\n\n";
           cyan();
    }
    else if(lose)
    {
         yellow();
         system("msg * You LOST!");
         cout << "\nYou LOST!\n\n";
         cyan();
    }
    else
    {
        yellow();
        system("msg * DRAW!");
        cout << "\nDRAW!\n\n";
        cyan();
    }
    
    //LOSE, CHANGE COLOR OF CONSECUTIVE THREE
    //HORIZONTAL
    if((A[1] == 'O') && (A[5] == 'O') && (A[9] == 'O'))
    {         
             cout << "   1   2   3 \n";
             cout << "1 ";
             yellow();
             cout << " O ";
             cyan();
             cout << "| ";
             yellow();
             cout << "O ";
             cyan();
             cout << "| ";
             yellow();
             cout << "O \n";
             cyan();
             cout << "  ---+---+---" << endl;
             cout << "2 " << B << endl;
             
             cout << "  ---+---+---" << endl;
             cout << "3 " << C << endl << endl;
    }
    else if((B[1] == 'O') && (B[5] == 'O') && (B[9] == 'O'))
    {         
             cout << "   1   2   3 \n";
             cout << "1 " << A << endl;
             cout << "  ---+---+---" << endl;
             cout << "2 ";
             yellow();
             cout << " O ";
             cyan();
             cout << "| ";
             yellow();
             cout << "O ";
             cyan();
             cout << "| ";
             yellow();
             cout << "O \n";
             cyan();
             cout << "  ---+---+---" << endl;
             cout << "3 " << C << endl << endl;
    }
    else if((C[1] == 'O') && (C[5] == 'O') && (C[9] == 'O'))
    {
             cout << "   1   2   3 \n";
             cout << "1 " << A << endl;
             cout << "  ---+---+---" << endl;
             cout << "2 " << B << endl;
             cout << "  ---+---+---" << endl;
             cout << "3 ";
             yellow();
             cout << " O ";
             cyan();
             cout << "| ";
             yellow();
             cout << "O ";
             cyan();
             cout << "| ";
             yellow();
             cout << "O \n\n";
             cyan();
    }
    else if((A[5] == 'O') && (B[5] == 'O') && (C[5] == 'O'))
    {
         cout << "   1   2   3 \n";
         cout << "1 ";
         cout << A[0] << A[1] << A[2] << A[3] << A[4];
         yellow();
         cout << "O ";
         cyan();
         cout << "| ";
         cout << A[9] << A[10] << A[11] << endl;
         cout << "  ---+---+---" << endl;
         cout << "2 ";
         cout << B[0] << B[1] << B[2] << B[3] << B[4];
         yellow();
         cout << "O ";
         cyan();
         cout << "| ";
         cout << B[9] << B[10] << B[11] << endl;
         cout << "  ---+---+---" << endl;
         cout << "3 ";
         cout << C[0] << C[1] << C[2] << C[3] << C[4];
         yellow();
         cout << "O ";
         cyan();
         cout << "| ";
         cout << C[9] << C[10] << endl << endl;
    }
    else if((A[1] == 'O') && (B[1] == 'O') && (C[1] == 'O'))
    {
         cout << "   1   2   3 \n";
         cout << "1  ";
         yellow();
         cout << "O ";
         cyan();
         cout << A[3] << A[4] << A[5] << A[6] << A[7] << A[8] << A[9] << A[10] << endl;
         cout << "  ---+---+---" << endl;
         cout << "2  ";
         yellow();
         cout << "O ";
         cyan();
         cout << B[3] << B[4] << B[5] << B[6] << B[7] << B[8] << B[9] << B[10] << endl;
         cout << "  ---+---+---" << endl;
         cout << "3  ";
         yellow();
         cout << "O ";
         cyan();
         cout << C[3] << C[4] << C[5] << C[6] << C[7] << C[8] << C[9] << C[10] << endl << endl;
    }
    else if((A[9] == 'O') && (B[9] == 'O') && (C[9] == 'O'))
    {
         cout << "   1   2   3 \n";
         cout << "1 " << A[0] << A[1] << A[2] << A[3] << A[4] << A[5] << A[6] << A[7] << A[8];
         yellow();
         cout << A[9];
         cyan();
         cout << A[10] << endl;
         cout << "  ---+---+---" << endl;
         cout << "2 " << B[0] << B[1] << B[2] << B[3] << B[4] << B[5] << B[6] << B[7] << B[8];
         yellow();
         cout << B[9];
         cyan();
         cout << B[10] << endl;
         cout << "  ---+---+---" << endl;
         cout << "3 " << C[0] << C[1] << C[2] << C[3] << C[4] << C[5] << C[6] << C[7] << C[8];
         yellow();
         cout << C[9];
         cyan();
         cout << C[10] << endl << endl;
    }
    else if((A[1] == 'O') && (B[5] == 'O') && (C[9] == 'O'))
    {
         cout << "   1   2   3 \n";
         cout << "1  ";
         yellow();
         cout << A[1];
         cyan();
         cout << A[2] << A[3] << A[4] << A[5] << A[6] << A[7] << A[8] << A[9] << A[10] << endl;
         cout << "  ---+---+---" << endl;
         cout << "2 ";
         cout << B[0] << B[1] << B[2] << B[3] << B[4];
         yellow();
         cout << "O ";
         cyan();
         cout << "| ";
         cout << B[9] << B[10] << B[11] << endl;
         cout << "  ---+---+---" << endl;
         cout << "3 " << C[0] << C[1] << C[2] << C[3] << C[4] << C[5] << C[6] << C[7] << C[8];
         yellow();
         cout << C[9];
         cyan();
         cout << C[10] << endl << endl;
    }
    else if((A[9] == 'O') && (B[5] == 'O') && (C[1] == 'O'))
    {
         cout << "   1   2   3 \n";
         cout << "1 " << A[0] << A[1] << A[2] << A[3] << A[4] << A[5] << A[6] << A[7] << A[8];
         yellow();
         cout << A[9];
         cyan();
         cout << A[10] << endl;
         cout << "  ---+---+---" << endl;
         cout << "2 ";
         cout << B[0] << B[1] << B[2] << B[3] << B[4];
         yellow();
         cout << "O ";
         cyan();
         cout << "| ";
         cout << B[9] << B[10] << B[11] << endl;
         cout << "  ---+---+---" << endl;
         cout << "3  ";
         yellow();
         cout << "O ";
         cyan();
         cout << C[3] << C[4] << C[5] << C[6] << C[7] << C[8] << C[9] << C[10] << endl << endl;
    }     
    else
    {    
        cout << "   1   2   3 \n";
        cout << "1 " << A << endl;
        cout << "  ---+---+---" << endl;
        cout << "2 " << B << endl;
        cout << "  ---+---+---" << endl;
        cout << "3 " << C << endl << endl;
    }
    
    system("PAUSE");
}//end of tictactoe code
//CHECKS IF FILLED
bool filled(char a)
{
     if((a == 'X') || (a == 'O'))
           return true;
     else if(a == ' ')
         return false;
}
//CHECKS IF ALL FILLED
bool allfilled(bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h, bool i)
{
     if((a == true) && (b == true) && (c == true) && (d == true) && (e == true) && (f == true) && (g == true) && (h == true) && (i == true))
           return true;
     else
           return false;
}

//Plus or Minus and its functions
void plusminus()
{
     int dcom, dfcom;
    int x, d, df;
    char a;
    bool win, lose;
    win = false;
    lose = false;
    
    d = 0;
    df = 1;
    dcom = 0;
    dfcom = 2;
    
    //VALUE ASSIGNMENTS FOR BOARD
    for(x = 0; x <= 500; x++)
    {
          if(x == 499)
          {
               J[x] = 1;
          }
          else if((x%5) == 0)
          J[x] = '|';
          else if(((x+1)%5) == 0)
          {
               if((x+1)%50 == 0)
               J[x] = '^';
               else if((x+6)%50 == 0)
               J[x] = '9';
               else if((x+11)%50 == 0)
               J[x] = '8';
               else if((x+16)%50 == 0)
               J[x] = '7';
               else if((x+21)%50 == 0)
               J[x] = '6';
               else if((x+26)%50 == 0)
               J[x] = '5';
               else if((x+31)%50 == 0)
               J[x] = '4';
               else if((x+36)%50 == 0)
               J[x] = '3';
               else if((x+41)%50 == 0)
               J[x] = '2';
               else if((x+46)%50 == 0)
               J[x] = '1';
               else
               {}
          }
          else
          J[x] = ' ';
    }
    for(x= 0; x <= 50; x++)
    {
           if((x >= 46) && (x <= 49))
           dash[x] = ' ';
           else if((x == 0) || (x == 50))
           dash[x] = '|';
           else if((x%5) == 0)
           dash[x] = '+';
           else
           dash[x] = '=';
    }
    for(x= 0; x <= 50; x++)
    {
           if((x >= 1) && (x <= 4))
           dashleft[x] = ' ';
           else if((x == 0) || (x == 50))
           dashleft[x] = '|';
           else if((x%5) == 0)
           dashleft[x] = '+';
           else
           dashleft[x] = '=';
    }
    
    for(x= 0; x <= 50; x++)
    {
           if((x%5) == 0)
           dash2[x] = '+';
           else
           dash2[x] = '-';
    }
    

    
    while((win == false) && (lose == false))
    {  
       //ROLLS AND POSITION OF PLAYER
       d = d*5;
       J[df] = ' ';
       df = df + d;
       J[df] = 'X';
       //ROLLS AND POSITION OF PLAYER2
       dcom = dcom*5;
       J[dfcom] = ' ';
       dfcom = dfcom + dcom;
       J[dfcom] = 'O';
       
       //CONDITIONS FOR BOARD
       if((df >= 496) && (dfcom >= 497))
       {
              win = true;
              lose = true;
              
              break;
       }
       else if(df >= 496)
       {
              win = true;
              
              break;
       }
       else if(dfcom >= 497)
       {
            lose = true;
            
            break;
       }
       //PLAYER'S!!
       //MINUS 5 STEPS
       else if(df == 251)
       {
            df = 226;
            printboard();
            system("msg * You landed on something! You fell 5 steps lower!");
            cout << "\nYou landed on something! You fell 5 steps lower!\n";
            system("PAUSE");
            J[251] = ' ';
            system("CLS");
            J[226] = 'X';
       }
       //MINUS 2 STEPS
       else if(df == 11)
       {
            df = 1;
            printboard();
            system("msg * You landed on something! You fell 2 steps lower!");
            cout << "\nYou landed on something! You fell 2 steps lower!\n";
            system("PAUSE");
            J[11] = ' ';
            system("CLS");
            J[1] = 'X';
       }
       //PLUS 8 STEPS
       else if(df == 36)
       {
            df = 76;
            printboard();
            system("msg * You landed on something! You advanced 8 steps higher!");
            cout << "\nYou landed on something! You advanced 8 steps higher!\n";
            system("PAUSE");
            J[36] = ' ';
            system("CLS");
            J[76] = 'X';
       }
       //MINUS 4 STEPS
       else if(df == 71)
       {
            df = 51;
            printboard();
            system("msg * You landed on something! You fell 4 steps lower!");
            cout << "\nYou landed on something! You fell 4 steps lower!\n";
            system("PAUSE");
            J[71] = ' ';
            system("CLS");
            J[51] = 'X';
       }
       //MINUS 3 STEPS
       else if(df == 91)
       {
            df = 76;
            printboard();
            system("msg * You landed on something! You fell 3 steps lower!");
            cout << "\nYou landed on something! You fell 3 steps lower!\n";
            system("PAUSE");
            J[91] = ' ';
            system("CLS");
            J[76] = 'X';
       }
       //PLUS 9 STEPS
       else if(df == 171)
       {
            df = 216;
            printboard();
            system("msg * You landed on something! You advanced 9 steps higher!");
            cout << "\nYou landed on something! You advanced 9 steps higher!\n";
            system("PAUSE");
            J[171] = ' ';
            system("CLS");
            J[216] = 'X';
       }
       //MINUS 6 STEPS
       else if(df == 176)
       {
            df = 146;
            printboard();
            system("msg * You landed on something! You fell 6 steps lower!");
            cout << "\nYou landed on something! You fell 6 steps lower!\n";
            system("PAUSE");
            J[176] = ' ';
            system("CLS");
            J[146] = 'X';
       }
       //PLUS 4 STEPS
       else if(df == 421)
       {
            df = 441;
            printboard();
            system("msg * You landed on something! You advanced 4 steps higher!");
            cout << "\nYou landed on something! You advanced 4 steps higher!\n";
            system("PAUSE");
            J[421] = ' ';
            system("CLS");
            J[441] = 'X';
       }
       //MINUS 9 STEPS
       else if(df == 371)
       {
            df = 326;
            printboard();
            system("msg * You landed on something! You fell 9 steps lower!");
            cout << "\nYou landed on something! You fell 9 steps lower!\n";
            system("PAUSE");
            J[371] = ' ';
            system("CLS");
            J[326] = 'X';
       }
       //PLUS 2 STEPS
       else if(df == 481)
       {
            df = 491;
            printboard();
            system("msg * You landed on something! You advanced 2 steps higher!");
            cout << "\nYou landed on something! You advanced 2 steps higher!\n";
            system("PAUSE");
            J[481] = ' ';
            system("CLS");
            J[491] = 'X';
            df = 466;
            printboard();
            system("msg * You landed on something! You fell 5 steps lower!");
            cout << "\nYou landed on something! You fell 5 steps lower!\n";
            system("PAUSE");
            J[491] = ' ';
            system("CLS");
            J[466] = 'X';
       }
       //MINUS 5 STEPS
       else if(df == 491)
       {
            df = 466;
            printboard();
            system("msg * You landed on something! You fell 5 steps lower!");
            cout << "\nYou landed on something! You fell 5 steps lower!\n";
            system("PAUSE");
            J[491] = ' ';
            system("CLS");
            J[466] = 'X';
       }
       else
       {
       }
       //COMPUTER'S!!
       //MINUS 5 STEPS
       if(dfcom == 252)
       {
            dfcom = 227;
            printboard();
            system("msg * Computer landed on something! Computer fell 5 steps lower!");
            cout << "\nComputer landed on something! Computer fell 5 steps lower!\n";
            system("PAUSE");
            J[252] = ' ';
            system("CLS");
            J[227] = 'O';
       }
       //MINUS 2 STEPS
       else if(dfcom == 12)
       {
            dfcom = 2;
            printboard();
            system("msg * Computer landed on something! Computer fell 2 steps lower!");
            cout << "\nComputer landed on something! Computer fell 2 steps lower!\n";
            system("PAUSE");
            J[12] = ' ';
            system("CLS");
            J[2] = 'O';
       }
       //PLUS 8 STEPS
       else if(dfcom == 37)
       {
            dfcom = 77;
            printboard();
            system("msg * Computer landed on something! Computer advanced 8 steps higher!");
            cout << "\nComputer landed on something! Computer advanced 8 steps higher!\n";
            system("PAUSE");
            J[37] = ' ';
            system("CLS");
            J[77] = 'O';
       }
       //MINUS 4 STEPS
       else if(dfcom == 72)
       {
            dfcom = 52;
            printboard();
            system("msg * Computer landed on something! Computer fell 4 steps lower!");
            cout << "\nComputer landed on something! Computer fell 4 steps lower!\n";
            system("PAUSE");
            J[72] = ' ';
            system("CLS");
            J[52] = 'O';
       }
       //MINUS 3 STEPS
       else if(dfcom == 92)
       {
            dfcom = 77;
            printboard();
            system("msg * Computer landed on something! Computer fell 3 steps lower!");
            cout << "\nComputer landed on something! Computer fell 3 steps lower!\n";
            system("PAUSE");
            J[92] = ' ';
            system("CLS");
            J[77] = 'O';
       }
       //PLUS 9 STEPS
       else if(dfcom == 172)
       {
            dfcom = 217;
            printboard();
            system("msg * Computer landed on something! Computer advanced 9 steps higher!");
            cout << "\nComputer landed on something! Computer advanced 9 steps higher!\n";
            system("PAUSE");
            J[172] = ' ';
            system("CLS");
            J[217] = 'O';
       }
       //MINUS 6 STEPS
       else if(dfcom == 177)
       {
            dfcom = 147;
            printboard();
            system("msg * Computer landed on something! Computer fell 6 steps lower!");
            cout << "\nComputer landed on something! Computer fell 6 steps lower!\n";
            system("PAUSE");
            J[177] = ' ';
            system("CLS");
            J[147] = 'O';
       }
       //PLUS 4 STEPS
       else if(dfcom == 422)
       {
            dfcom = 442;
            printboard();
            system("msg * Computer landed on something! Computer advanced 4 steps higher!");
            cout << "\nComputer landed on something! Computer advanced 4 steps higher!\n";
            system("PAUSE");
            J[422] = ' ';
            system("CLS");
            J[442] = 'O';
       }
       //MINUS 9 STEPS
       else if(dfcom == 372)
       {
            dfcom = 327;
            printboard();
            system("msg * Computer landed on something! Computer fell 9 steps lower!");
            cout << "\nComputer landed on something! Computer fell 9 steps lower!\n";
            system("PAUSE");
            J[372] = ' ';
            system("CLS");
            J[327] = 'O';
       }
       //PLUS 2 STEPS
       else if(dfcom == 482)
       {
            dfcom = 492;
            printboard();
            system("msg * Computer landed on something! Computer advanced 2 steps higher!");
            cout << "\nComputer landed on something! Computer advanced 2 steps higher!\n";
            system("PAUSE");
            J[482] = ' ';
            system("CLS");
            J[492] = 'O';
            dfcom = 467;
            printboard();
            system("msg * Computer landed on something! Computer fell 5 steps lower!");
            cout << "\nComputer landed on something! Computer fell 5 steps lower!\n";
            system("PAUSE");
            J[492] = ' ';
            system("CLS");
            J[467] = 'O';
       }
       //MINUS 5 STEPS
       else if(dfcom == 492)
       {
            dfcom = 467;
            printboard();
            system("msg * Computer landed on something! Computer fell 5 steps lower!");
            cout << "\nComputer landed on something! Computer fell 5 steps lower!\n";
            system("PAUSE");
            J[492] = ' ';
            system("CLS");
            J[467] = 'O';
       }
       
       
       //roll dice >> random!
       printboard();
       cout << df << " " << dfcom << endl;
       cout << "Press enter to roll dice!\n";
       system("PAUSE");
       //random 1 - 6
       srand(time(NULL)); 
       d = rand() % 6 + 1;
       system("CLS");
       for(x = 1; x <= 2; x++)
       {
             cout << "Rolling dice.. " << x;
             Sleep(500);
             system("CLS");
       }
       face(d);
       system("PAUSE");
       system("CLS");
       //NEXT PLAYER!
       cout << "Computer's turn...";
       //random 1 - 6
       srand(time(NULL)); 
       dcom = rand() % 6 + 1;
       Sleep(750);
       system("CLS");
       for(x = 1; x <= 2; x++)
       {
             cout << "Rolling dice<computer>.. " << x;
             Sleep(500);
             system("CLS");
       }
       facecom(dcom);
       system("PAUSE");
       system("CLS");
    }
    
    if((win == true) && (lose == true))
    {
           system("msg * DRAW! :/");
           cout << "\nDRAW! :|\n" << endl;
           J[496] = 'X';
           J[497] = 'O';
           printboard();
    }
    else if(win)
    {
           system("msg * YOU WON! :)");
           cout << "\nYou WON! :)\n" << endl;
           J[496] = 'X';
           printboard();
    }
    else if(lose)
    {
           system("msg * YOU LOST! :(");
           cout << "\nYou LOST! :(\n" << endl;
           J[497] = 'O';
           printboard();
    }       
    else
    {}
    system("PAUSE");
}//end of plusminus code

//COLOR BOARD
void printcolored(int x)
{
               if(x == 499)
               {
                    white();
                    cout << J[x];
                    blue();
               }
               //X is always yellow
               else if(J[x] == 'X')
               {
                       yellow();
                       cout << J[x];
                       blue();
               }
               //O is always cyan
               else if(J[x] == 'O')
               {
                       cyan();
                       cout << J[x];
                       blue();
               }
               else if((x+1)%50 == 0)
               {
                           green();
                           cout << J[x];
                           blue();
               }
               else if((x+6)%50 == 0)
               {
                           green();
                           cout << J[x];
                           blue();
               }
               else if((x+11)%50 == 0)
               {
                           green();
                           cout << J[x];
                           blue();
               }
               else if((x+16)%50 == 0)
               {
                           green();
                           cout << J[x];
                           blue();
               }
               else if((x+21)%50 == 0)
               {
                           green();
                           cout << J[x];
                           blue();
               }
               else if((x+26)%50 == 0)
               {
                           green();
                           cout << J[x];
                           blue();
               }
               else if((x+31)%50 == 0)
               {
                           green();
                           cout << J[x];
                           blue();
               }
               else if((x+36)%50 == 0)
               {
                           green();
                           cout << J[x];
                           blue();
               }
               else if((x+41)%50 == 0)
               {
                           green();
                           cout << J[x];
                           blue();
               }
               else if((x+46)%50 == 0)
               {
                           green();
                           cout << J[x];
                           blue();
               }
               else
               {
                   cout << J[x];
               }
}
//PRINT BOARD (PLUSMINUS)
void printboard()
{
     int x;
     //PRINT BOARD plus minus
    blue();
    cout << dash2 << endl;
    J[494] = '-';
    J[493] = '5';
    J[484] = '+';
    J[483] = '2';
    for(x = 500; x >= 450; x--)
    {
          if((x == 483) || (x == 484))
          {
                white();
                cout << J[x];
                blue();
          }
          else if((x == 493) || (x == 494))
          {
               red();
               cout << J[x];
               blue();
          }
          else
          printcolored(x);
    }
    cout << endl;
    cout << dash << endl;
    J[423] = '+';
    J[424] = '4';
    for(x = 400; x <= 450; x++)
    {
          if((x == 423) || (x == 424))
          {
                white();
                cout << J[x];
                blue();
          }
          else
          printcolored(x);
    }
    cout << endl;
    cout << dashleft << endl;
    J[374] = '-';
    J[373] = '9';
    for(x = 400; x >= 350; x--)
    {
          if((x == 374) || (x == 373))
          {
                red();
                cout << J[x];
                blue();
          }
          else
          printcolored(x);
    }
    cout << endl;
    cout << dash << endl;
    for(x = 300; x <= 350; x++)
    {
          printcolored(x);
    }
    cout << endl;
    cout << dashleft << endl;
    J[254] = '-';
    J[253] = '5';
    for(x = 300; x >= 250; x--)
    {
          if((x == 254) || (x == 253))
          {
                red();
                cout << J[x];
                blue();
          }
          else
          printcolored(x);
    }
    cout << endl;
    cout << dash << endl;
    for(x = 200; x <= 250; x++)
    {
          printcolored(x);
    }
    cout << endl;
    cout << dashleft << endl;
    J[174] = '+';
    J[173] = '9';
    J[179] = '-';
    J[178] = '6';
    for(x = 200; x >= 150; x--)
    {
          if((x == 179) || (x == 178))
          {
                red();
                cout << J[x];
                blue();
          }
          else if((x == 174) || (x == 173))
          {
               white();
               cout << J[x];
               blue();
          }
          else
          printcolored(x);
    }
    cout << endl;
    cout << dash << endl;
    for(x = 100; x <= 150; x++)
    {
          printcolored(x);
    }
    cout << endl;
    cout << dashleft << endl;
    J[74] = '-';
    J[73] = '4';
    J[94] = '-';
    J[93] = '3';
    for(x = 100; x >= 50; x--)
    {
          if((x == 74) || (x == 73) || (x == 94) || (x == 93))
          {
                red();
                cout << J[x];
                blue();
          }
          else
          printcolored(x);
    }
    cout << endl;
    cout << dash << endl;
    J[38] = '+';
    J[39] = '8';
    J[13] = '-';
    J[14] = '2';
    for(x = 0; x <= 50; x++)
    {
          if((x == 38) || (x == 39))
          {
                white();
                cout << J[x];
                blue();
          }
          else if((x == 13) || (x == 14))
          {
               red();
               cout << J[x];
               blue();    
          }
          else
          printcolored(x);
    }
    cout << endl;
    cout << dash2 << endl;
    //END PRINT
}
   
//DICE PLAYER
void face(int d)
{
     white();
     if(d == 6)
    {
         cout << "\n+-----+\n";
         cout << "| * * |\n";
         cout << "| * * |\n";
         cout << "| * * |\n";
         cout << "+-----+\n";
    }
    else if(d == 5)
    {
         cout << "\n+-----+\n";    
         cout << "| * * |\n";
         cout << "|  *  |\n";
         cout << "| * * |\n";
         cout << "+-----+\n";
    }
    else if(d == 4)
    {
         cout << "\n+-----+\n";    
         cout << "| * * |\n";
         cout << "|     |\n";
         cout << "| * * |\n";
         cout << "+-----+\n";
    }
    else if(d == 3)
    {
         cout << "\n+-----+\n";    
         cout << "|   * |\n";
         cout << "|  *  |\n";
         cout << "| *   |\n";
         cout << "+-----+\n";
    }
    else if(d == 2)
    {
         cout << "\n+-----+\n";    
         cout << "|   * |\n";
         cout << "|     |\n";
         cout << "| *   |\n";
         cout << "+-----+\n";
    }
    else if(d == 1)
    {
         cout << "\n+-----+\n";    
         cout << "|     |\n";
         cout << "|  *  |\n";
         cout << "|     |\n";
         cout << "+-----+\n";
    }
    else
    {
    }
    red();
}
//DICE COMPUTER
void facecom(int d)
{
     red();
     if(d == 6)
    {
         cout << "\n+-----+\n";
         cout << "| * * |\n";
         cout << "| * * |\n";
         cout << "| * * |\n";
         cout << "+-----+\n";
    }
    else if(d == 5)
    {
         cout << "\n+-----+\n";    
         cout << "| * * |\n";
         cout << "|  *  |\n";
         cout << "| * * |\n";
         cout << "+-----+\n";
    }
    else if(d == 4)
    {
         cout << "\n+-----+\n";    
         cout << "| * * |\n";
         cout << "|     |\n";
         cout << "| * * |\n";
         cout << "+-----+\n";
    }
    else if(d == 3)
    {
         cout << "\n+-----+\n";    
         cout << "|   * |\n";
         cout << "|  *  |\n";
         cout << "| *   |\n";
         cout << "+-----+\n";
    }
    else if(d == 2)
    {
         cout << "\n+-----+\n";    
         cout << "|   * |\n";
         cout << "|     |\n";
         cout << "| *   |\n";
         cout << "+-----+\n";
    }
    else if(d == 1)
    {
         cout << "\n+-----+\n";    
         cout << "|     |\n";
         cout << "|  *  |\n";
         cout << "|     |\n";
         cout << "+-----+\n";
    }
    else
    {
    }
    red();
}
//HELP
void help()
{
     white();
     cout << "In both games, you'll always be 'X'.";
     yellow();
     cout << "\n\n\nTic-Tac-Toe!\nTo play, enter a position of the row(1-3) and column(1-3).\n";
     blue();
     cout << "Plus or Minus!\nTo play, press any key to roll dice.\n\n\n";
     green();
     system("msg * Tic-Tac-Toe!  To play, enter a position of a row(1-3) and column(1-3).");
     system("msg * Plus or Minus! To play, press any key to roll dice.");
     system("PAUSE");
}
