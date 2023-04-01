#include <iostream>
#include <sstream>
#include <conio.h>
using namespace std;
void add(int matrixA[][3], int matrixB[][3]);
void multiply(int matrixA[][3], int matrixB[][3]);
void subtract(int matrixA[][3], int matrixB[][3]);
void scalar(int matrixA[][3], int matrixB[][3], string choose);
void printA(int matrixA[][3]);
void printB(int matrixB[][3]);
void showA(int matrixA[][3]);
void showB(int matrixB[][3]);
void menu();
int chooseOption();
string symbol();
void printC(int matrixC[][3]);
void identity(int matrixA[][3], int matrixB[][3], string choose);
void diagonal(int matrixA[][3], int matrixB[][3], string choose);
void transpose(int matrixA[][3], int matrixB[][3], string choose);
void symmteric(int matrixA[][3], int matrixB[][3], string choose);
void header();
void clearScreen();

main()
{
    int matrixA[3][3];
    int matrixC[3][3];
    int matrixB[3][3];
    int option;
    system("cls");
    header();
    menu();
    option = chooseOption();
    clearScreen();
    header();
    while (option != 9)
    {
        if (option == 1)
        {
            cout << " Adding of matrix " << endl;
            cout << endl;
            printA(matrixA);
            printB(matrixB);
            showA(matrixA);
            showB(matrixB);
            cout << "Sum of matrix A and B is ...." << endl;
            add(matrixA, matrixB);
            clearScreen();
            header();
            menu();
            option = chooseOption();
            clearScreen();
            header();
        }
        if (option == 2)
        {
            cout << "Subtraction of matrix" << endl;
            cout << endl;
            printA(matrixA);
            printB(matrixB);
            showA(matrixA);
            showB(matrixB);
            cout << "subtract of matrix A and B is ...." << endl;
            subtract(matrixA, matrixB);
            clearScreen();
            header();
            menu();
            option = chooseOption();
            clearScreen();
            header();
        }
        if (option == 3)
        {
            cout << "Multiplication of matrix" << endl;
            cout << endl;
            printA(matrixA);
            printB(matrixB);
            showA(matrixA);
            showB(matrixB);
            cout << "multiply of matrix A and B is ...." << endl;
            multiply(matrixA, matrixB);
            clearScreen();
            header();
            menu();
            option = chooseOption();
            clearScreen();
            header();
        }
        if (option == 4)
        {
            cout << "Scalar multiplication" << endl;
            cout << endl;
            string choose = symbol();
            if (choose == "A")
            {
                printA(matrixA);
                showA(matrixA);
            }
            else
            {
                printB(matrixB);
                showB(matrixB);
            }
            cout << " scalar multiply of matrix A and B is ...." << endl;
            scalar(matrixA, matrixB, choose);
            clearScreen();
            header();
            menu();
            option = chooseOption();
            clearScreen();
            header();
        }
        if (option == 5)
        {
            cout << "Identity matrix" << endl;
            cout << endl;
            string choose = symbol();
            if (choose == "A")
            {
                printA(matrixA);
                showA(matrixA);
            }
            else
            {
                printB(matrixB);
                showB(matrixB);
            }
            identity(matrixA, matrixB, choose);
            clearScreen();
            header();
            menu();
            option = chooseOption();
            clearScreen();
            header();
        }
        if (option == 6)
        {
            cout << " Diagonal matrix" << endl;
            cout << endl;
            string choose = symbol();
            if (choose == "A")
            {
                printA(matrixA);
                showA(matrixA);
            }
            else
            {
                printB(matrixB);
                showB(matrixB);
            }
            diagonal(matrixA, matrixB, choose);
            clearScreen();
            header();
            menu();
            option = chooseOption();
            clearScreen();
            header();
        }
        if (option == 7)
        {
            cout << "Transpose of matrix";
            cout << endl;
            string choose = symbol();
            if (choose == "A")
            {
                printA(matrixA);
                showA(matrixA);
            }
            else
            {
                printB(matrixB);
                showB(matrixB);
            }
            cout << " transpose  matrix  is ...." << endl;
            transpose(matrixA, matrixB, choose);
            clearScreen();
            header();
            menu();
            option = chooseOption();
            clearScreen();
            header();
        }
        if (option == 8)
        {
            cout << "Symmteric Matrix" << endl;
            cout << endl;
            string choose = symbol();
            if (choose == "A")
            {
                printA(matrixA);
                showA(matrixA);
            }
            else
            {
                printB(matrixB);
                showB(matrixB);
            }
            cout << " symmteric  matrix  is ...." << endl;
            cout << endl;
            symmteric(matrixA, matrixB, choose);
            clearScreen();
            header();
            menu();
            option = chooseOption();
            clearScreen();
            header();
        }
    }
}
void header()
{
    cout << "                _____  _____  ___    _  _    _     ___    _____  _      ___    _   _  _      _____  _____  _____  ___   " << endl;
    cout << "        /'\\_/`\\(  _  )(_   _)|  _`\\ (_)( )  ( )   (  _`\\ (  _  )( )    (  _`\\ ( ) ( )( )    (  _  )(_   _)(  _  )|  _`\\ " << endl;
    cout << "        |     || (_) |  | |  | (_) )| |`\\`\\/'/'   | ( (_)| (_) || |    | ( (_)| | | || |    | (_) |  | |  | ( ) || (_) ) " << endl;
    cout << "        | (_) ||  _  |  | |  | ,  / | |  >  <     | |  _ |  _  || |  _ | |  _ | | | || |  _ |  _  |  | |  | | | || ,  / " << endl;
    cout << "        | | | || | | |  | |  | |\\ \\ | | /'/\\`\\    | (_( )| | | || |_( )| (_( )| (_) || |_( )| | | |  | |  | (_) || |\\ \\ " << endl;
    cout << "        (_) (_)(_) (_)  (_)  (_) (_)(_)(_)  (_)   (____/'(_) (_)(____/'(____/'(_____)(____/'(_) (_)  (_)  (_____)(_) (_)" << endl;
    cout << endl;
    cout << endl;
}
void clearScreen()
{
    cout << "Press Any Key to Continue.." << endl;
    getch();
    system("cls");
}
void line()
{
    cout << "------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << endl;
}
void printA(int matrixA[][3])
{
    for (int idx = 0; idx < 3; idx++)
    {
        for (int idx1 = 0; idx1 < 3; idx1++)
        {
            cout << " Elements  of matrix A...";
            cin >> matrixA[idx][idx1];
        }
        cout << endl;
    }
}
void printB(int matrixB[][3])
{
    for (int idx = 0; idx < 3; idx++)
    {
        for (int idx1 = 0; idx1 < 3; idx1++)
        {
            cout << " Elements  of matrix B...";
            cin >> matrixB[idx][idx1];
        }
        cout << endl;
    }
}
void showA(int matrixA[][3])
{
    cout << " Elements  of matrix A..." << endl;
    for (int idx = 0; idx < 3; idx++)
    {
        for (int idx1 = 0; idx1 < 3; idx1++)
        {
            cout << matrixA[idx][idx1] << "   ";
        }
        cout << endl;
    }
}
void showB(int matrixB[][3])
{
    cout << " Elements  of matrix B..." << endl;
    for (int idx = 0; idx < 3; idx++)
    {
        for (int idx1 = 0; idx1 < 3; idx1++)
        {

            cout << matrixB[idx][idx1] << "   ";
        }
        cout << endl;
    }
}
void menu()
{
    cout << "----------------------------" << endl;
    cout << "Menu" << endl;
    cout << "------------------------------" << endl;
    cout << "1 . Add matrix " << endl;
    cout << "2 . Subtract matrix " << endl;
    cout << "3 . Multiply matrix " << endl;
    cout << "4 . Scalar matrix " << endl;
    cout << "5 . Identity matrix " << endl;
    cout << "6 . Diagonal matrix " << endl;
    cout << "7 . Transpose matrix " << endl;
    cout << "8 . Symmteric matrix " << endl;
}
int chooseOption()
{
    int option;
    cout << " Entre option ..";
    cin >> option;
    return option;
}
string symbol()
{
    string choose;
    cout << "Entre the matrix to whhich you want to check.";
    cin >> choose;
    return choose;
}
void printC(int matrixC[][3])
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << matrixC[row][col] << "   ";
        }
        cout << endl;
    }
}
void add(int matrixA[][3], int matrixB[][3])
{
    int matrixC[3][3];
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            matrixC[row][col] = matrixA[row][col] + matrixB[row][col];
        }
    }
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << matrixC[row][col] << "   ";
        }
        cout << endl;
    }
}
void subtract(int matrixA[][3], int matrixB[][3])
{
    int matrixC[3][3];
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            matrixC[row][col] = matrixA[row][col] - matrixB[row][col];
        }
    }
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << matrixC[row][col] << "   ";
        }
        cout << endl;
    }
}
void multiply(int matrixA[][3], int matrixB[][3])
{
    int matrixC[3][3];
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            matrixC[row][col] = 0;
            for (int k = 0; k < 3; k++)
            {
                matrixC[row][col] += matrixA[row][k] * matrixB[k][col];
            }
        }
    }
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << matrixC[row][col] << "   ";
        }
        cout << endl;
    }
}
void scalar(int matrixA[][3], int matrixB[][3], string choose)
{
    int matrixC[3][3];
    int scalar;
    cout << " Entre scalar value ....";
    cin >> scalar;
    if (choose == "A")
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                matrixC[row][col] = scalar * matrixA[row][col];
            }
        }
    }
    else
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                matrixC[row][col] = scalar * matrixB[row][col];
            }
        }
    }
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << matrixC[row][col] << "   ";
        }
        cout << endl;
    }
}
void identity(int matrixA[][3], int matrixB[][3], string choose)
{
    int matrixC[3][3];
    bool flag = false;
    if (choose == "A")
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (row == col && matrixA[row][col] == 1)
                {
                    flag = true;
                }
            }
        }
    }
    else
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (row == col && matrixB[row][col] == 1)
                {
                    flag = true;
                }
            }
        }
    }
    if (flag == true)
    {
        cout << " Identity Matrix" << endl;
    }
    else
    {
        cout << "Not an identity matrix" << endl;
    }
}
void diagonal(int matrixA[][3], int matrixB[][3], string choose)
{
    int matrixC[3][3];
    bool flag = false;
    if (choose == "A")
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (row != col && matrixA[row][col] == 0)
                {
                    flag = true;
                }
            }
        }
    }
    else
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (row != col && matrixB[row][col] == 0)
                {
                    flag = true;
                }
            }
        }
    }
    if (flag == true)
    {
        cout << " diagonal matrix" << endl;
    }
    elseggg
    {
        cout << " not diagonal matrix" << endl;
    }
}
void transpose(int matrixA[][3], int matrixB[][3], string choose)
{
    int matrixC[3][3];
    if (choose == "A")
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                matrixC[row][col] = matrixA[col][row];
            }
        }
    }
    else
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                matrixC[row][col] = matrixB[col][row];
            }
        }
    }
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << matrixC[row][col] << "   ";
        }
        cout << endl;
    }
}
void symmteric(int matrixA[][3], int matrixB[][3], string choose)
{
    int matrixC[3][3];
    bool flag = true;
    if (choose == "A")
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                matrixC[row][col] = matrixA[col][row];
            }
        }
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (matrixC[row][col] == matrixA[row][col])
                {
                    flag = true;
                }
            }
        }
    }
    else
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                matrixC[row][col] = matrixB[col][row];
            }
        }
    }
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (matrixC[row][col] == matrixB[row][col])
            {
                flag = true;
            }
        }
    }
    if (flag == true)
    {
        cout << "Is Symmteric" << endl;
    }
    else
    {
        cout << "Not symmteric" << endl;
    }
}