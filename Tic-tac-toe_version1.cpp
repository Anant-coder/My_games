#include <iostream>
#include <windows.h>

// Author : Anant Mishra
// Any correction is welcome :)

using namespace std;

void displaymatrix(char matrix[9]);
int placechar(char matrix[9], int chance);
int checkwin(char matrix[9], int chance);

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

    char matrix1[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    displaymatrix(matrix1);
    changecolor(4);
    cout << "Player 1 : X" << endl;
    changecolor(2);
    cout << "Player 2 : O" << endl;
    char matrix[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    while (win == 0)
    {
        displaymatrix(matrix);
        chance = placechar(matrix, chance);
        win = checkwin(matrix, chance);
    }
    return 0;
}

void displaymatrix(char matrix[9])
{
    changecolor(11);
    printf("\n");
    printf("  %c  |  %c  |  %c \n", matrix[0], matrix[1], matrix[2]);
    printf("-----|-----|-----\n");
    printf("  %c  |  %c  |  %c \n", matrix[3], matrix[4], matrix[5]);
    printf("-----|-----|-----\n");
    printf("  %c  |  %c  |  %c \n", matrix[6], matrix[7], matrix[8]);
    printf("\n");
    changecolor(7);
}

int placechar(char matrix[9], int chance)
{
    int x;
    cout << endl;

    cout << "Player " << (chance == 1 ? "X" : "O") << " turn :-" << endl;

    cout << "Enter the position : " << endl;
    cin >> x;

    if (x <=9 && x > 0)
    {
        if (matrix[x-1] != 'O' && matrix[x-1] != 'X')
        {
            if (chance == 1)
            {
                matrix[x-1] = 'X';
                chance = 2;
                return chance;
            }
            else
            {
                matrix[x-1] = 'O';
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

int checkwin(char matrix[9], int chance)
{
    int matrixcount = 0, condition = 0;
    for (int i = 0; i < 9; i++)
    {
        matrixcount += (matrix[i] == 'X' && matrix[i] == 'O');
    }

    // Check rows
    for (int i = 0; i < 7; i+= 3)
    {
        if ((matrix[i] == 'X' || matrix[i] == 'O') && matrix[i] == matrix[i+1] && matrix[i] == matrix[i+2])
            condition = 1;
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if ((matrix[i] == 'X' || matrix[i] == 'O') && matrix[i] == matrix[i+3] && matrix[i] == matrix[i+6])
            condition = 1;
    }
    
    // Check diagonals
    if ((matrix[0] == 'X' || matrix[0] == 'O') && matrix[0] == matrix[4] && matrix[0] == matrix[8])
        condition = 1;

    if ((matrix[2] == 'X' || matrix[2] == 'O') && matrix[2] == matrix[4] && matrix[2] == matrix[6])
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
