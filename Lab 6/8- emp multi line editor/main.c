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
#define MaxLines 5
#define MaxCharPerLine 30
char **multiLineEditor(int maxLines, int maxCharsPerLine, int xPos, int yPos, int startAscii, int endAscii)
{
    // Allocate memory for each line pointer
    char **lines = (char **)malloc(maxLines * sizeof(char *));
    for (int i = 0; i < maxLines; i++)
    {
        lines[i] = (char *)calloc(maxCharsPerLine, sizeof(char));
    }


    int first,curr,last;
    first = curr = last = xPos;
    int currentLine = 0;

    char *pfirst, *pcurr, *plast;
    pfirst = pcurr = plast = lines[currentLine];

    char ch= 'a';
    int flag = 1;


// Pointer to current character position in line



    do
    {
        gotoxy(xPos, yPos);

        for (int i = 0; i < maxLines; i++)
        {
            gotoxy(xPos, yPos + i);
            for (int j = 0; j < maxCharsPerLine; j++)
            {
                if (pcurr == &lines[i][j])
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
            break;;
        default:
            if(isprint(ch))
            {
                if(pcurr < pfirst + maxCharsPerLine && ch >= startAscii && ch <= endAscii)
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
                        char *temp = plast;
                        while (temp > pcurr)
                        {
                            *temp = *(temp - 1);
                            temp--;
                        }
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
    while(flag == 1);
    return lines;
}
struct Employee
{
    int id;
    char name[20];
    int age;
    float salary,commission,deduction,netSalary;

};
void PrintEmployee(struct Employee param)
{
    printf("id=%i\n",param.id);
    printf("name=%s\n",param.name);  //puts(param.name)
    printf("age=%i\n",param.age);
    printf("commission=%f\n",param.commission);
    printf("deduction=%f\n",param.deduction);
    printf("salary=%f\n",param.salary);
    printf("netSalary=%f\n",(param.salary + param.commission) - param.deduction );

}


int main()
{
    struct Employee emp;
    char **inputLine;

    gotoxy(5, 5);
    printf("Enter Id : \n");

    gotoxy(55, 5);
    printf("Enter Name : \n");


    gotoxy(5, 10);
    printf("Enter Age : \n");

    gotoxy(55, 10);
    printf("Enter commission : \n");


    gotoxy(5, 15);
    printf("Enter deduction : \n");


    gotoxy(55, 15);
    printf("Enter Salary : \n");


    //emp.id = atoi(lineEditor(5, 8, 7, 48, 57));
    inputLine = multiLineEditor(3, MaxCharPerLine, 10, 5, 32, 126);
    strncpy(emp.name, inputLine[1], 19);
    emp.name[19] = '\0';  // Ensure null termination
    //strcpy(emp.name, lineEditor(15, 58, 7, 65, 122));

    /*emp.age = atoi(lineEditor(3, 8, 12, 48, 57));

    emp.commission = atof(lineEditor(10, 58, 12, 48, 57));

    emp.deduction = atof(lineEditor(10, 8, 17, 48, 57));

    emp.salary = atof(lineEditor(10, 58, 17, 48, 57));*/
    system("cls");
    PrintEmployee(emp);

    // Free allocated memory
    for (int i = 0; i < 3; i++)
    {
        free(inputLine[i]);
    }
    free(inputLine);

    //free(emp.name);
    return 0;
}
