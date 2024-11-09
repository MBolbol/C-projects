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
/*#define MaxLines 5
#define MaxCharPerLine 30*/
int main()
{
    int MaxLines= 5;
    int MaxCharPerLine= 30;
    //char lines[MaxLines][MaxCharPerLine]= {{0}};; // Each line can store up to 30 characters
    char **lines = (char **)malloc(MaxLines * sizeof(char *)); // Each line can store up to 30 characters
    for (int i = 0; i < MaxLines; i++)
    {
        lines[i] = (char *)malloc(MaxCharPerLine * sizeof(char));
        for (int j = 0; j <MaxCharPerLine; j++)
        {
            lines[i][j] = '\0';
        }
    }
    //char arr[30] = {};
    int first, curr, last;
    char *pfirst, *pcurr, *plast;
    int currentLine = 0;

    first = curr = last = 20;
    pfirst = pcurr = plast = lines[currentLine];

// Pointer to current character position in line

    char ch = 'a';
    int flag= 1;

    do
    {
        gotoxy(20,10);

        // Display each line
        for (int i = 0; i < MaxLines; i++)
        {
            gotoxy(20, 10 + i); // Position for each line
            for (int j = 0; j < MaxCharPerLine; j++)
            {
                if(pcurr == &lines[i][j])
                {
                    textattr(4);
                }
                else
                {
                    textattr(7);

                }
                if (lines[i][j] != '\0')
                {
                    printf("%c", lines[i][j]);
                }
                else
                {
                    printf("-");
                }
            }
        }

        gotoxy(curr,10 + currentLine);

        ch=getch();  //Enter
        switch (ch)
        {
        case EXTENDED:
            ch = getch();
            switch (ch)
            {
            case Left:
                if (pcurr > pfirst)
                {
                    pcurr--;
                    curr--;
                }
                break;
            case Right:
                if (pcurr < plast)
                {
                    pcurr++;
                    curr++;
                }
                break;
            case Up:
                if (currentLine > 0)
                {
                    currentLine--;
                    pfirst = lines[currentLine];
                    pcurr = plast = pfirst + strlen(lines[currentLine]);
                    curr = 20 + (pcurr - pfirst);
                }
                break;
            case Down:
                if (currentLine < MaxLines - 1)
                {
                    currentLine++;
                    pfirst = lines[currentLine];
                    pcurr = plast = pfirst + strlen(lines[currentLine]);
                    curr = 20 + (pcurr - pfirst);
                }
                break;
            case Home:
                pcurr = pfirst;
                curr = 20;
                break;
            case End:
                pcurr = plast;
                curr = 20 + (plast - pfirst);
                break;
            case Del:
                if (pcurr < plast)
                {
                    char *temp = pcurr;
                    while (temp < plast)
                    {
                        *temp = *(temp + 1);
                        temp++;
                    }
                    plast--;
                }
                break;
            }
            break;
        case Enter:
        case Esc:
            flag = 0;
            break;
        case Backspace:
            if (pcurr > pfirst)
            {
                pcurr--;
                curr--;
                char *temp = pcurr;
                while (temp < plast)
                {
                    *temp = *(temp + 1);
                    temp++;
                }
                plast--;
            }
            break;
        default:
            if (isprint(ch) && pcurr < pfirst + MaxCharPerLine)
            {
                // Check if we need to move to the next line when the current line is full
                if ((pcurr - pfirst) >= MaxCharPerLine)
                {
                    if (currentLine < MaxLines - 1)
                    {
                        // Move to the next line
                        currentLine++;
                        pfirst = lines[currentLine];
                        pcurr = pfirst;
                        plast = pfirst + strlen(lines[currentLine]);
                        curr = 20;
                    }
                }
                if (pcurr == plast)
                {
                    *pcurr = ch;
                    pcurr++;
                    curr++;
                    plast++;
                }
                else
                {
                    char *temp = plast;
                    while (temp > pcurr)
                    {
                        *temp = *(temp - 1);
                        temp--;
                    }
                    *pcurr = ch;
                    pcurr++;
                    curr++;
                    plast++;
                }
                /*if ((pcurr - lines[currentLine]) >= MaxCharPerLine)
                {
                    if (currentLine < MaxLines - 1)
                    {
                        // Move to the start of the next line
                        currentLine++;
                        pcurr = lines[currentLine];
                        pfirst = pcurr;
                        plast = pcurr + strlen(lines[currentLine]);
                        curr = 20;
                    }
                }*/
            }
            break;
        }

    }
    while (flag);

    // Print final text
    gotoxy(0, 12 + MaxLines);
    printf("Final text:\n");
    for (int i = 0; i < MaxLines; i++)
    {
        printf("Line %d: %s\n", i + 1, lines[i]);
    }

    // Free dynamically allocated memory
    for (int i = 0; i < MaxLines; i++)
    {
        free(lines[i]);
    }
    free(lines);

    return 0;
}
