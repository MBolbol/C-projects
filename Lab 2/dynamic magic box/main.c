#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy( int column, int row )
{
    COORD coord;
    coord.X = column;
    coord.Y = row;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}

int main()
{
    int size;

    printf("plz enter odd size not 1: ");
    scanf("%d", &size);

    int col;
    int row;
    row=1;
    col=(size/2) +1;

    for(int i=1; i<=size*size; i++)
    {
        gotoxy(col*3,row*3);
        printf("%i",i);
        //check and reassign coordinates row,col before i++
        if(i%size!=0) //reminder exists
        {
            row--;
            col--;
            if(col<1)
            {
                col=size;
            }
            if(row<1)
            {
                row=size;
            }
        }
        else  //no reminder
        {
            row++;
        }
    }
    return 0;

}
