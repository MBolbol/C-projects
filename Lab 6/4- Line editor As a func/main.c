#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

// Normal ASCII
#define Enter 13
#define Esc 27
#define Backspace 8

// Extended ASCII
#define EXTENDED -32
#define Left 75
#define Right 77
#define Home 71
#define End 79
#define Del 83

void gotoxy(int column, int row)
{
    COORD coord;
    coord.X = column;
    coord.Y = row;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

// Line editor function

char *lineEditor(int maxChars, int xPos, int yPos, int startAscii, int endAscii)
{
    char *arr = malloc((maxChars +1) * sizeof(char));
    for (int i = 0; i < maxChars + 1; i++)
    {
        arr[i] = '\0';
    }


    //if (!arr) return NULL;

    int first,curr,last;
    first = curr = last = xPos;

    int *pfirst, *pcurr, *plast;
    pfirst = pcurr = plast = arr;

    int ch;
    int flag = 1;


    /* for(int i=0; i< maxChars;i++){

         printf("-");
     }*/

    do
    {
        gotoxy(xPos, yPos);

        for(int i=0; i< maxChars; i++)
        {
            //gotoxy(xPos+1, yPos);

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


        gotoxy(curr, yPos);
        ch = getch();

        switch(ch)
        {
        case EXTENDED:
            ch = getch();
            switch(ch)
            {
            case Left:
                if(pcurr > pfirst)
                {
                    pcurr--;
                    curr--;
                }
                break;

            case Right:
                if(pcurr< plast)
                {
                    pcurr++;
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
                if(pcurr < plast)
                {
                    char *temp = pcurr;
                    while(temp < plast-1)
                    {
                        *temp = *(temp+1);
                        temp++;
                    }
                    *temp = '\0';
                    plast--;
                    last--;
                }
                break;
            }
            break;

        case Enter:
        case Esc:
            *plast = '\0';
            flag =0;
            break;
        case Backspace:
            pcurr--;
            curr--;
            if (pcurr > pfirst)
            {
                char *temp = pcurr;
                while(temp < plast - 1)
                {
                    *temp = *(temp+1);
                    temp++;

                }
                *temp = '\0';
                plast--;
                last--;

            }
            break;
        default:
            if(isprint(ch))
            {
                if(pcurr < pfirst + maxChars && ch >= startAscii && ch <= endAscii)
                    if(pcurr == plast)
                    {
                        *pcurr = ch;
                        pcurr++;
                        curr++;
                        plast++;
                        last++;
                    }
                    else
                    {
                        *pcurr = ch;
                        pcurr++;
                        curr++;


                    }
            }
        }

        break;

    }
    while(flag == 1);



    return arr;

}

int main()
{
    char *input = lineEditor(30, 20, 15, 65, 90);
    printf("Your Line Editor: %s\n",input);
    free(input);
    return 0;
}
