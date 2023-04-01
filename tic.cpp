#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

void printGrid(char grid[][3]);
void player1(int rowNumber, int columnNumber, char grid[][3], char symbol);
void player2(int rowNumber1, int columnNumber1, char grid[][3], char symbol1);
bool checkDiagonals(char symbol, int gridSize, char grid[][3]);
bool isWinner(char symbol, int gridSize, char grid[][3]);
bool checkRows(char symbol, int gridSize, char grid[][3]);
bool checkColumns(char symbol, int gridSize, char grid[][3]);
bool checkDiagonals2(char symbol1, int gridSize, char grid[][3]);
bool isWinner2(char symbol1, int gridSize, char grid[][3]);
bool checkRows2(char symbol1, int gridSize, char grid[][3]);
bool checkColumns2(char symbol1, int gridSize, char grid[][3]);
void menu();
char choose();
void storeSeats(char grid[][3]);
void loadSeats(char grid[][3]);
void storeSeats1(char grid[][3]);
void loadSeats1(char grid[][3]);
main()
{
    system("cls");
    bool gameRunning = true;
    int rowNumber;
    int columnNumber;
    int rowNumber1;
    int columnNumber1;
    int gridSize = 3;
    char symbol = 'S';
    char symbol1 = 'W';
    bool flag;
    char grid[3][3] = {{'X', 'X', 'X'},
                       {'X', 'X', 'X'},
                       {'X', 'X', 'X'}};

    menu();
  
    char option = choose();
    while (option != '4')
    {
        if (option == '1')
        {
            loadSeats(grid);
            printGrid(grid);
            int numberOfMoves = 0;
            while (gameRunning == true)
            {
                player1(rowNumber, columnNumber, grid, symbol);
                numberOfMoves++;
                bool flag1 = isWinner(symbol, gridSize, grid);
                if (flag1 == true)
                {
                    cout << " Player 1  wins" <<endl;
                    gameRunning = false;
                    menu();
                    option = choose();
                }
                player2(rowNumber1, columnNumber1, grid, symbol1);
                bool flag2 = isWinner2(symbol1, gridSize, grid);
                if (flag2 == true)
                {
                    cout << " Player 2  wins" <<endl;
                    gameRunning = false;
                    menu();
                    option = choose();
                }

                if (grid[3][3] != 'X' && gameRunning == true && numberOfMoves >= 5)
                {
                    cout << " Match TIE" << endl;
                    gameRunning = false;
                    Sleep(200);
                    menu();
                    option = choose();
                }
            }
        }
        if (option == '2')
        {
            storeSeats(grid);
            menu();
            option = choose();
        }
         if (option == '3')
        {
            storeSeats1(grid);
            loadSeats1(grid);
            printGrid(grid);
            int numberOfMoves = 0;
            while (gameRunning == true)
            {
                player1(rowNumber, columnNumber, grid, symbol);
                numberOfMoves++;
                bool flag1 = isWinner(symbol, gridSize, grid);
                if (flag1 == true)
                {
                    cout << " Player 1  wins" <<endl;
                    gameRunning = false;
                    menu();
                    option = choose();
                }
                player2(rowNumber1, columnNumber1, grid, symbol1);
                bool flag2 = isWinner2(symbol1, gridSize, grid);
                if (flag2 == true)
                {
                    cout << " Player 2  wins" <<endl;
                    gameRunning = false;
                    menu();
                    option = choose();
                }

                if (grid[3][3] != 'X' && gameRunning == true && numberOfMoves >= 5)
                {
                    cout << " Match TIE" << endl;
                    gameRunning = false;
                    Sleep(200);
                    menu();
                    option = choose();
                }
            }

        }
    }
}
char choose()
{
    char option;
    cout << " entre Your option...";
    cin >> option;
    return option;
}
void menu()
{
    cout << " 1. Start a game" << endl;
    cout << " 2 . Pause a game." << endl;
    cout <<"  3 . new board" <<endl;
    cout << " 4.  Exit" << endl;
}
void printGrid(char grid[][3])
{
    int x = 0;
    cout << "     "
         << "       "
         << "  0    "
         << "     "
         << "  1      "
         << "   "
         << "2      "
         << "     " << endl;
    cout << endl;
    for (int row = 0; row < 3; row++)
    {
        cout << "    " << x << "    ";
        for (int col = 0; col < 3; col++)
        {
            cout << "     " << grid[row][col] << "     ";
        }
        cout << endl;
        cout << endl;
        x++;
    }
}
void player1(int rowNumber, int columnNumber, char grid[][3], char symbol)
{
    cout << " Player ONe turn";
    cout << " Entre row number ...";
    cin >> rowNumber;
    cout << " entre column number...";
    cin >> columnNumber;
    grid[rowNumber][columnNumber] = symbol;
    printGrid(grid);
}
void player2(int rowNumber1, int columnNumber1, char grid[][3], char symbol1)
{
    cout << " Player TWO turn";
    cout << " Entre row number ...";
    cin >> rowNumber1;
    cout << " entre column number...";
    cin >> columnNumber1;
    grid[rowNumber1][columnNumber1] = symbol1;
    printGrid(grid);
}
bool checkRows(char symbol, int gridSize, char grid[][3])
{
    int count = 0;
    for (int row = 0; row < gridSize; row = row + 1)
    {
        count = 0;
        for (int col = 0; col < gridSize; col = col + 1)
        {
            if (grid[row][col] == symbol)
            {
                count = count + 1;
            }
        }
        if (count == gridSize)
        {
            return 1;
        }
    }
    return 0;
}
bool checkColumns(char symbol, int gridSize, char grid[][3])
{
    int count = 0;
    for (int col = 0; col < gridSize; col = col + 1)
    {
        count = 0;
        for (int row = 0; row < gridSize; row = row + 1)
        {
            if (grid[row][col] == symbol)
            {
                count = count + 1;
            }
        }
        if (count == gridSize)
        {
            return 1;
        }
    }
    return 0;
}
bool checkDiagonals(char symbol, int gridSize, char grid[][3])
{
    int count = 0;
    for (int idx = 0; idx < gridSize; idx = idx + 1)
    {
        if (grid[idx][idx] == symbol)
        {
            count = count + 1;
        }
    }
    if (count == gridSize)
    {
        return 1;
    }
    count = 0;
    for (int row = 0, col = 2; row < gridSize; row++, col--)
    {
        if (grid[row][col] == symbol)
        {
            count = count + 1;
        }
    }
    if (count == gridSize)
    {
        return 1;
    }
    return 0;
}
bool isWinner(char symbol, int gridSize, char grid[][3])
{
    if (checkRows(symbol, gridSize, grid) || checkColumns(symbol, gridSize, grid) || checkDiagonals(symbol, gridSize, grid))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool checkRows2(char symbol1, int gridSize, char grid[][3])
{
    int count = 0;
    for (int row = 0; row < gridSize; row = row + 1)
    {
        count = 0;
        for (int col = 0; col < gridSize; col = col + 1)
        {
            if (grid[row][col] == symbol1)
            {
                count = count + 1;
            }
        }
        if (count == gridSize)
        {
            return 1;
        }
    }
    return 0;
}
bool checkColumns2(char symbol1, int gridSize, char grid[][3])
{
    int count = 0;
    for (int col = 0; col < gridSize; col = col + 1)
    {
        count = 0;
        for (int row = 0; row < gridSize; row = row + 1)
        {
            if (grid[row][col] == symbol1)
            {
                count = count + 1;
            }
        }
        if (count == gridSize)
        {
            return 1;
        }
    }
    return 0;
}
bool checkDiagonals2(char symbol1, int gridSize, char grid[][3])
{
    int count = 0;
    for (int idx = 0; idx < gridSize; idx = idx + 1)
    {
        if (grid[idx][idx] == symbol1)
        {
            count = count + 1;
        }
    }
    if (count == gridSize)
    {
        return 1;
    }
    count = 0;
    for (int row = 0, col = 2; row < gridSize; row++, col--)
    {
        if (grid[row][col] == symbol1)
        {
            count = count + 1;
        }
    }
    if (count == gridSize)
    {
        return 1;
    }
    return 0;
}
bool isWinner2(char symbol1, int gridSize, char grid[][3])
{
    if (checkRows2(symbol1, gridSize, grid) || checkColumns2(symbol1, gridSize, grid) || checkDiagonals2(symbol1, gridSize, grid))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void storeSeats(char grid[][3])
{
    fstream file;
    file.open("maze.txt", ios ::out);
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            file << grid[row][col];
        }
        file << endl;
    }
    file.close();
}
void loadSeats(char grid[][3])
{
    fstream file;
    string word;
    int row = 0;
    file.open("maze.txt", ios ::in);
    while (getline(file, word))
    {
        for (int x = 0; x < word.length(); x++)
        {

            grid[row][x] = word[x];
        }
        row++;
    }
    file.close();
}
void storeSeats1(char grid[][3])
{
    fstream file;
    file.open("maze1.txt", ios ::out);
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            file << grid[row][col];
        }
        file << endl;
    }
    file.close();
}
void loadSeats1(char grid[][3])
{
    fstream file;
    string word;
    int row = 0;
    file.open("maze1.txt", ios ::in);
    while (getline(file, word))
    {
        for (int x = 0; x < word.length(); x++)
        {

            grid[row][x] = word[x];
        }
        row++;
    }
    file.close();
}