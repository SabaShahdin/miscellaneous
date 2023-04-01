#include <iostream>
#include <fstream>
using namespace std;
void menu();
void loadSeats();
void storeSeats();
void printReserved();
void ticketType();
string seats[13][6] = {{"*", "*", "*", "*", "*", "*"},
                       {"*", "*", "*", "*", "*", "*"},
                       {"*", "*", "*", "*", "*", "*"},
                       {"*", "*", "*", "*", "*", "*"},
                       {"*", "*", "*", "*", "*", "*"},
                       {"*", "*", "*", "*", "*", "*"},
                       {"*", "*", "*", "*", "*", "*"},
                       {"*", "*", "*", "*", "*", "*"},
                       {"*", "*", "*", "*", "*", "*"},
                       {"*", "*", "*", "*", "*", "*"},
                       {"*", "*", "*", "*", "*", "*"},
                       {"*", "*", "*", "*", "*", "*"},
                       {"*", "*", "*", "*", "*", "*"}};

main()
{
    menu();
    int option;
    while (option != 5)
    {
        cout << "Entre any option " << endl;
        cin >> option;
        if (option == 1)
        {
            loadSeats();
        }
        if (option == 2)
        {
            ticketType();
        }
        if (option == 3)
        {
            printReserved();
        }
        if (option == 4)
        {
            storeSeats();
        }
    }
}
void menu()
{
    cout << "1. Load the reserved seats arrangement from the file" << endl;
    cout << "2. Ask the user for the ticket type and desired seat" << endl;
    cout << "3. Print the reserved seats arrangement" << endl;
    cout << "4. Store the reserved seats arrangement in the file" << endl;
    cout << "5. New Plane seats arrangement." << endl;
}
void loadSeats()
{
    fstream file;
    string word;
    int row = 0;
    file.open("seats.txt", ios ::in);
    while (getline(file, word))
    {
        for (int x = 0; x < word.length(); x++)
        {
            seats[row][x] = word[x];
        }
        row++;
    }
    file.close();
}
void printReserved()
{
    for (int row = 0; row < 13; row++)
    {
        for (int col = 0; col < 6; col++)
        {
            cout << seats[row][col];
        }
        cout << endl;
    }
}
void ticketType()
{

    int number;
    char  takeInput;
    char  takeInput1;
    string class2;
    cout << "Entre the location .... of row   ";
    cin >> takeInput;
    cout << "Entre the type of class   ";
    cin >> class2;
    cout << "Entre the location .... of col  ";
    cin >> takeInput1;
    number = takeInput - '0';
    int rowIndex;
    string output;
    if (takeInput1 == 'A')
    {
        rowIndex = 0;
    }
    else if (takeInput1 == 'B')
    {
        rowIndex = 1;
    }
    else if (takeInput1 == 'C')
    {
        rowIndex = 2;
    }
    else if (takeInput1 == 'D')
    {
        rowIndex = 3;
    }
    else if (takeInput1 == 'E')
    {
        rowIndex = 4;
    }
    else if (takeInput1 == 'F')
    {
        rowIndex = 5;
    }
    else if (number > 13)
    {
        cout << "Entre correct number";
    }
    else if (takeInput1 > 'F')
    {
        cout << "Entre correct number";
    }
    if (number == 1 || number == 2)
    {
        if (seats[number][rowIndex] == "*" && class2 == "first")
        {
            output = "Avaliable";
            seats[number][rowIndex] = "X";
        }
        else
        {
            output = "Reserved";
        }
    }
    if (number >= 3 || number <= 7)
    {
        if (seats[number][rowIndex] == "*" && class2 == "business")
        {
            output = "Avaliable";
            seats[number][rowIndex] = "X";
        }
        else
        {
            output = "Reserved";
        }
    }
    if (number >= 8 || number <= 13)
    {
        if (seats[number][rowIndex] == "*" && class2 == "economy")
        {
            output = "Avaliable";
            seats[number][rowIndex] = "X";
        }
        else
        {
            output = "Reserved";
        }
    }
    cout << output << endl;
}
void storeSeats()
{
    fstream file;
    file.open("seats.txt", ios ::out);
    for (int row = 0; row < 13; row++)
    {
        for (int col = 0; col < 6; col++)
        {
            file << seats[row][col];
        }
        file << endl;
    }
    file.close();
}