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



    int first,curr,last;
    first = curr = last = xPos;

    char *pfirst, *pcurr, *plast;
    pfirst = pcurr = plast = arr;

    char ch= 'a';
    int flag = 1;


    /* for(int i=0; i< maxChars;i++){

         printf("-");
     }*/

    do
    {
        gotoxy(xPos, yPos);

        for(int i=0; i< maxChars; i++)
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
                if(pcurr < pfirst + maxChars && ch >= startAscii && ch <= endAscii)
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
    while(flag == 1);
    return arr;
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


    emp.id = atoi(lineEditor(5, 8, 7, 48, 57));

    strcpy(emp.name, lineEditor(15, 58, 7, 65, 122));

    emp.age = atoi(lineEditor(3, 8, 12, 48, 57));

    emp.commission = atof(lineEditor(10, 58, 12, 48, 57));

    emp.deduction = atof(lineEditor(10, 8, 17, 48, 57));

    emp.salary = atof(lineEditor(10, 58, 17, 48, 57));
    system("cls");
    PrintEmployee(emp);

    //free(emp.name);
    return 0;
}
