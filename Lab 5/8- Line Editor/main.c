#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

//Normal ASCII
#define Enter 13
#define Esc 27
#define Backspace 8

//Extended ASCII
#define EXTENDED -32
#define Left 75
#define Right 77
#define Up 72
#define Down 80
#define Home 71
#define End 79
#define Del 83

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

    char arr[30] = {};
    int first, curr, last;
    char *pfirst, *pcurr, *plast;

    first = curr = last = 20;
    pfirst = pcurr = plast = arr;

    char ch = 'a';
    int flag= 1;

    do
    {
        gotoxy(20,10);

        for (int i = 0; i < 30; i++)
        {
            if(pcurr == &arr[i])
            {
                textattr(4);
            }
            else
            {
                textattr(7);

            }
            if (arr[i] != '\0')
            {
                printf("%c", arr[i]);
            }
            else
            {
                printf("-");
            }
        }

        gotoxy(curr,10);

        ch=getch();  //Enter
        switch(ch)
        {
        case EXTENDED:
            ch=getch();
            switch(ch)
            {
            case Left:
                if(pcurr > pfirst)
                {

                    pcurr --;
                    curr--;

                }
                break;
            case Right:
                if(pcurr < plast)
                {
                    pcurr ++;
                    curr++;

                }
                break;

            case Home:
                pcurr = pfirst;
                curr = first;
                break;
            case End:
                pcurr = plast;
                curr = last;
                break;
            case Del:
                if (pcurr < plast)
                {
                    // Shift each character to the left, starting from pcurr
                    char *temp = pcurr;
                    while (temp < plast - 1)    // Move until reaching one position before plast
                    {
                        *temp = *(temp + 1);    // Shift left by copying the next character
                        temp++;
                    }
                    *temp = '\0';               // Add null terminator at the new end
                    plast--;
                    last--;
                }
                break;
            }
            break;
        case Enter:
        case Esc:
            *pcurr = '\0';
            flag=0;
            break;
        case Backspace:
            if (pcurr > pfirst)
            {
                // Move the cursor one position back to the location to delete
                pcurr--;
                curr--;
                // Shift each character to the left, starting from pcurr
                char *temp = pcurr;
                while (temp < plast - 1)    // Shift characters left until the end
                {
                    *temp = *(temp + 1);    // Copy the next character
                    temp++;
                }
                *temp = '\0';               // Add null terminator at the new end

                plast--;
                last--;
            }
            break;

        default:
            if(isprint(ch))
            {
                if(pcurr < pfirst+30)
                {

                    if(pcurr == plast)
                    {

                        *pcurr = ch;
                        printf("%c", ch);
                        pcurr++;
                        curr++;
                        plast++;
                        last++;
                    }
                    else
                    {

                        *pcurr = ch;
                        printf("%c", ch);
                        pcurr++;
                        curr++;
                    }
                }
            }
            break;
        }
    }
    while(flag==1);

    gotoxy(0, 12);
    printf("Final text: %s\n", arr);

    return 0;
}
