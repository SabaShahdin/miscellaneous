#include <iostream>
using namespace std;

char objects[5][5] = {
    {'-', '#', '#', '-', '#'},
    {'#', '-', '-', '#', '-'},
    {'-', '#', '-', '-', '-'},
    {'#', '-', '#', '-', '#'},
    {'#', '-', '-', '-', '-'}};
bool gravity = false;
bool isBlackHole = true;
void displayWorld()
{
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            cout << objects[row][col];
            cout << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
void setGravityStatus(bool value)
{
    gravity = value;
}
void setHoleStatus(bool value)
{
    isBlackHole = value;
}

void timeTick(int times)
{
    int count = 0;
    if (gravity && isBlackHole)
    {
        while (count < times)
        {
            for (int row = 3 ; row >= 0; row--)
            {
                for (int col = 0; col < 5; col++)
                {

                    if (objects[row][col] == '#')
                    {
                        if (objects[row + 1][col] == '-')
                        {
                            objects[row + 1][col] = '#';
                            objects[row][col] = '-';
                        }
                    }
                    else if (isBlackHole && row == 5 - 1)
                    {
                         row = 0;
                         if (objects[row + 1][col] == '-')
                        {
                            objects[row + 1 ][col] = '#';
                            objects[row][col] = '-';
                        }                
                    }
                    count = count + 1;
                }
            }
        }
    }
}
    main()
    {
        int tick;
        displayWorld();
        setGravityStatus(true);
        cout <<"Entre number of tick..." ;
        cin >> tick;
        timeTick(tick);
        cout << "Updated word" << endl;
        displayWorld();
    }
