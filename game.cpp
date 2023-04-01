# include <iostream>
# include<windows.h>
using namespace std;
void printMaze();
void gotoxy(int x , int y);
void printPacman (int x , int y);
void erase (int x , int y);
char getCharAtxy(short int x, short int y);
int scoreIncrease(int score);
void printGhost (int x , int y);
char getCharAtxy(short int x, short int y);
void clear (int x , int y , char previous);
void printGhostX1 (int x , int y);
void printGhostX2 (int x , int y);
void printGhostY1 (int x , int y);
void printGhostY2 (int x , int y);
void showGhost1();
void showGhost2();
void pacmanMove ();
    int gx = 4; 
    int gy = 7; 
    int gx2 = 10;
    int gy2 = 11;
    int  px = 4;
    int  py = 4;
    int score = 0;
    bool gameRunning = true;
    
main()
{
   
    char nextLocation;
    system ("cls");
    printMaze();
    printPacman ( px ,  py);
    printGhost (gx , gy);
    printGhost(gx2 , gy2);
    while(true)
    {
     Sleep(200);
     pacmanMove();                                                             
     showGhost1();
     showGhost2();
    if(nextLocation == 'G')  
             {
               gameRunning = false;
               while(false);
               gotoxy(81,22);
             }
    }        
} 
void pacmanMove ()
{

       char nextLocation = getCharAtxy(px , py);
        if(GetAsyncKeyState(VK_LEFT))
        {
            gameRunning = true;
            char nextLocation = getCharAtxy (px-1 , py);
            if(nextLocation == ' ' || nextLocation == '.')
            {
                erase(px , py);
                px = px - 1;
                printPacman(px , py);
            }
            if(nextLocation == '.')
               { 
                score = scoreIncrease(score);
                cout<<"score = "<<score;
               }
                 if(nextLocation == 'G')  
             {
                gotoxy(81 , 23);
                cout<< "exit";
             }
        }
        if(GetAsyncKeyState(VK_RIGHT))
        {
            gameRunning = true;
            char nextLocation = getCharAtxy (px+1 ,py);
            if(nextLocation == ' ' || nextLocation == '.')
            {
                erase(px , py);
                px = px+1;
                printPacman(px , py);
            }
            if(nextLocation == '.')
               { 
                score = scoreIncrease(score);
                cout<<"score = "<<score;
               }
             if(nextLocation == 'G')  
             {
                gotoxy(81 , 23);
                cout<< "exit";
             }

        }
        if(GetAsyncKeyState(VK_DOWN))
        {
            gameRunning = true;
            char nextLocation = getCharAtxy (px , py+1);
            if(nextLocation ==' ' || nextLocation == '.')
            {
                 erase (px, py);
                 py = py + 1;
                 printPacman(px , py);
            }
            if(nextLocation == '.')
               { 
                score = scoreIncrease(score);
                cout<<"score = "<<score;
               }
               if(nextLocation == 'G')  
             {
                 gotoxy(81 , 23);
                cout<< "exit";
             }
        }
        if(GetAsyncKeyState(VK_UP))
         {
            gameRunning = true;
            char nextLocation = getCharAtxy (px , py-1);
            if(nextLocation == ' ' || nextLocation == '.')
            {
                erase(px , py);
                py = py - 1;
                printPacman(px , py);
            }
            if(nextLocation == '.')
               { 
                score = scoreIncrease(score);
                cout<<"score = "<<score;
               }
               if(nextLocation == 'G')  
             {
                gotoxy(81 , 23);
                cout<< "exit";                
             }
         }     
        if(GetAsyncKeyState(VK_ESCAPE))
        {
           gameRunning = false;
        } 
    }   

    

void printMaze()
{
 cout <<" ################################################################################  "<<endl;
 cout <<" ||.. .........................................   .......   ..............     ||  "<<endl;
 cout <<" ||.. %%%%%%%%%%%%%%        ...      %%%%%%%%%%%%%%        |%|...    %%  ..    ||  "<<endl;
 cout <<" ||..      |%|    |%|     |%|...      |%|        |%|        |%|...    |%|      ||  "<<endl;
 cout <<" ||..      |%|    |%|     |%|...      |%|        |%|        |%|...    |%|      ||  "<<endl;
 cout <<" ||..      %%%%%%%%%% ... |%|...      %%%%%%%%%%%%%%           ...    %%%.     ||  "<<endl;
 cout <<" ||..      |%|        ... |%|...      .................... |%|...       ..     ||  "<<endl;
 cout <<" ||..      %%%%%%%%%% ... |%|...      %%%%%%%%%%%%%%%%     |%|...    %% ..     ||  "<<endl;
 cout <<" ||..             |%|.                |%|......            |%|...     |%|      ||  "<<endl;
 cout <<" ||..      .......|%|.                |%|......|%|            ....    |%|..    ||  "<<endl;
 cout <<" ||..|%|   |%|%%%%|%|.|%|.|%|            ......|%|            ....|%| |%|..    ||  "<<endl;
 cout <<" ||..|%|   |%|    |%|..   %%%%%%%%%%%%   ......|%|            ....|%| |%|..    ||  "<<endl;
 cout <<" ||..|%|   |%|    |%|..         ....|%|    %%%%%%     |%|      ...|%|    ..|%| ||  "<<endl;
 cout <<" ||..|%|                        ....|%|               |%|       ..|%|     .|%| ||  "<<endl;
 cout <<" ||.................................................  |%|       ..|%|.  .....  ||  "<<endl;
 cout <<" ||   ..............................................                   ....... ||  "<<endl;
 cout <<" ||..|%|   |%|   |%|..      %%%%%%%%%%    ......|%|       |%|   ..|%|%%%%%%%%  ||  "<<endl;
 cout <<" ||..|%|   %%%%%%%%%%              ...|%|    %%%%%%       |%|   ..|%|..        ||  "<<endl;
 cout <<" ||.................................................      |%|   ..|%|........  ||  "<<endl;
 cout <<" ################################################################################  "<<endl;
}
 void gotoxy(int x , int y)
{
  COORD coordinates;
  coordinates.X = x;
  coordinates.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void printPacman (int x , int y)
{
  gotoxy(x , y);
  cout<<"P";
}
void erase (int x , int y)
{
  gotoxy( x , y);
  cout<<" " ;
}
char getCharAtxy(short int x, short int y)
{
 CHAR_INFO ci;
 COORD xy = {0, 0};
 SMALL_RECT rect = {x, y, x, y};
 COORD coordBufSize;
 coordBufSize.X = 1;
 coordBufSize.Y = 1;
 return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar
: ' ';
}
int scoreIncrease(int score)
{
    int result = score;
    gotoxy(80 , 22);
    result ++ ;
    return result;
}
void showGhost1()
    {
        string direction = "right";
        char previousChar = ' ';
        if(direction == "right")
        {
          char nextLocation = getCharAtxy(gx+1 , gy);
          if(nextLocation == '|' || nextLocation == '%' )
          {
             direction = "left";
               printGhostX1 (gx , gy); 
                cout<<" ";   
                 gotoxy(gx+1 , gy);
                 gx =4;
          }
          else if(nextLocation == ' ' || nextLocation == '.' )
          {
            clear(gx , gy , previousChar);
            gx = gx + 1;
            previousChar = nextLocation;
            printGhost(gx , gy);
        }
      
        }
        if(direction == "left")
        {
            char nextLocation = getCharAtxy(gx-1 , gy);
            if(nextLocation == '|' || nextLocation == '%')
            {
                direction = "right";
                  printGhostX2 (gx , gy);
                  cout<<" "; 
                 gotoxy(gx-1 , gy); 
                 gx =4;
                
            }
            else if(nextLocation == ' '  || nextLocation == '.')
            {
                clear(gx , gy , previousChar);
                gx = gx - 1 ;
                printGhost( gx , gy);
            }
        
        }
}  
    void showGhost2()
{
          string direction = "down";
          char previousChar = ' ';

        if(direction == "down")
        {
            char nextLocation = getCharAtxy(gx2 , gy2 + 1);
            if(nextLocation == '#')
            {
                direction = "up";
               printGhostY1 (gx2 , gy2);
                cout<<" ";
                 gotoxy(gx2 , gy2-1);
                 cout<<" ";
                 gy2 =11;
            }
            else if(nextLocation  == ' ' || nextLocation == '.')
            {
                clear (gx2 , gy2 , previousChar);
                gy2 = gy2 + 1;
                printGhost( gx2 , gy2);
            }
          
        }
        if(direction == "up")
        {
            char nextLocation = getCharAtxy(gx2 , gy2 - 1);
            if(nextLocation == '#')
            {
                direction = "down";
                printGhostY2 (gx2 , gy2);
                cout<<" ";  
                gotoxy(gx2 , gy2-1);
                gy2 =4;
            }
            else if(nextLocation  == ' ' || nextLocation == '.')
            {
                clear (gx2 , gy2 , previousChar);
                gy2 = gy2 - 1;
                printGhost( gx2 , gy2);
            }
        
        }
 }
void clear (int x , int y , char previous)
{
    gotoxy(x , y);
    cout<<previous;
}
void printGhost (int x , int y)
{
  gotoxy(x , y);
  cout<<"G";
}
void printGhostX1 (int x , int y)
{
   gotoxy(x-1,y);
    cout<<" ";
    Sleep(300);
}
void printGhostY1 (int x , int y)
{
   gotoxy(x,y-1);
    cout<<" ";
     gotoxy(x , y);
    cout<<" ";
    Sleep(300);
}
void printGhostX2 (int x , int y)
{
   gotoxy(x+1,y);
    cout<<" ";
    Sleep(300);
}
void printGhostY2 (int x , int y)
{
   gotoxy(x,y+1);
    cout<<" ";
     gotoxy(x , y);
    cout<<" ";
    Sleep(300);
}