#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//Normal ASCII
#define Enter 13
#define Esc 27
#define Tab 9
//Extended ASCII
#define EXTENDED -32
#define Up 72
#define Down 80
#define Home 71
#define End 79

void gotoxy( int column, int row )
{
    COORD coord;
    coord.X = column;
    coord.Y = row;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}
void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

int main()
{
    char menu[4][10]={"File","New","Display","Exit"};
    int cursor=0;
    int flag=555;
    char ch;
    do
    {
        //clear screen
        system("cls");
        for (int i = 0; i < 4; i++)
        {
            if(i==cursor){textattr(4);} //R
            else{textattr(7);} //W
            gotoxy(15,15+i);
            _cprintf("%s",menu[i]);
        }
        //
        ch=getch();  //Enter
        switch(ch)
        {
            case EXTENDED:
            ch=getch();
            switch(ch)
            {
                case Up:
                cursor--;
                if(cursor<0){cursor=3;}
                break;
                case Down:
                cursor++;
                if(cursor>3){cursor=0;}
                break;
                case Home:
                cursor=0;
                break;
                case End:
                cursor=3;
                break;
            }
            break;
            case Enter:
            switch(cursor)
            {
                case 0:
                system("cls");
                printf("File Page");
                //wait to see
                getch();
                break;
                case 1:
                system("cls");
                printf("New Page");
                //wait to see
                getch();
                break;
                case 2:
                system("cls");
                printf("Display Page");
                //wait to see
                getch();
                break;
                case 3:
                flag=0;
                break;
            }
            break;
            case Esc:
            flag=0;
            break;
            case Tab:
            cursor++;
            if(cursor>3){cursor=0;}
            break;
        }

    }
    while(flag==555);


    return 0;
}
