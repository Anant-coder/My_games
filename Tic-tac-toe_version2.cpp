#include <iostream>
#include <windows.h>

// Author : Anant Mishra
/* 
*** TIC-TAC-TOE *** game in which two players can play one after another by entering the X/Y postions of the matrix 
*/
// Any correction is welcome :)

using namespace std;

void displaymatrix(char matrix[3][3]);
int placechar(char matrix[3][3], int chance);
int checkwin(char matrix[3][3], int chance);

void changecolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main()
{
    int x, y;
    int win = 0;
    int chance = 1;
    cout << endl;
    changecolor(15);
    cout << "Hello! Welcome to my Tic-Tac-Toe :)" << endl;
    cout << "Made by Anant Mishra" << endl;
    cout << endl;
    cout << "Let's play :)" << endl;
    cout << endl;
    changecolor(4);
    cout << "Player 1 : X" << endl;
    changecolor(2);
    cout << "Player 2 : O" << endl;
    char matrix[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    while (win == 0)
    {
        displaymatrix(matrix);
        chance = placechar(matrix, chance);
        win = checkwin(matrix, chance);
    }
    return 0;
}

void displaymatrix(char matrix[3][3])
{
    changecolor(11);
    printf("\n");
    printf("  %c  |  %c  |  %c \n", matrix[0][0], matrix[0][1], matrix[0][2]);
    printf("-----|-----|-----\n");
    printf("  %c  |  %c  |  %c \n", matrix[1][0], matrix[1][1], matrix[1][2]);
    printf("-----|-----|-----\n");
    printf("  %c  |  %c  |  %c \n", matrix[2][0], matrix[2][1], matrix[2][2]);
    printf("\n");
    changecolor(7);
}

int placechar(char matrix[3][3], int chance)
{
    int x, y;
    bool error = 0;
    cout << endl;

    cout << "Player " << (chance == 1 ? "X" : "O") << " turn :-" << endl;

    cout << "Enter the X and Y coordinates : " << endl;
    cin >> x >> y;

    if ((x < 3 && x >= 0) && (y < 3 && y >= 0))
    {
        if (matrix[x][y] != 'O' && matrix[x][y] != 'X')
        {
            if (chance == 1)
            {
                matrix[x][y] = 'X';
                chance = 2;
                return chance;
            }
            else
            {
                matrix[x][y] = 'O';
                chance = 1;
                return chance;
            }
        }
        else
        {
            cout << "Invalid !! choice  :( " << endl;
            placechar(matrix, chance);
        }
    }
    else
    {
        cout << "Invalid !! choice  :( " << endl;
        placechar(matrix, chance);
    }
}

int checkwin(char matrix[3][3], int chance)
{
    int matrixcount = 0, condition = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrixcount += (matrix[i][j] != ' ');
        }
    }

    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if ((matrix[i][0] == 'X' || matrix[i][0] == 'O') && matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
            condition = 1;
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if ((matrix[0][i] == 'X' || matrix[0][i] == 'O') && matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
            condition = 1;
    }

    // Check diagonals
    if ((matrix[0][0] == 'X' || matrix[0][0] == 'O') && matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2])
        condition = 1;

    if ((matrix[0][2] == 'X' || matrix[0][2] == 'O') && matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0])
        condition = 1;

    // Winning check
    if (condition == 1)
    {
        displaymatrix(matrix);
        if (chance == 1)
        {
            cout << "Player O won !!!";
        }
        else
        {
            cout << "Player X won !!!";
        }
        return 1;
    }
    else if (condition != 1 && matrixcount == 9)
    {
        cout << "Draw !";
        displaymatrix(matrix);
        return 1;
    }
    else
    {
        return 0;
    }
}
