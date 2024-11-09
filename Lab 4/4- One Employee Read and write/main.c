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
struct Employee
{
    int id;
    char name[20];
    int age;
    float salary;
};
void PrintEmployee(struct Employee param)
{
    printf("id=%i\n",param.id);
    printf("name=%s\n",param.name);  //puts(param.name)
    printf("age=%i\n",param.age);
    printf("salary=%f\n",param.salary);
}
int main()
{
    struct Employee e1;

    gotoxy(5, 5);
    printf("Enter Id\n");
    _flushall();
    gotoxy(7, 7);
    scanf("%i",&e1.id);

    gotoxy(55, 5);
    printf("Enter Name\n");
    _flushall();
    gotoxy(57, 7);
    gets(e1.name);

    gotoxy(5, 20);
    printf("Enter Age\n");
    gotoxy(7, 22);
    scanf("%i",&e1.age);

    gotoxy(55, 20);
    printf("Enter Salary\n");
    gotoxy(57, 22);
    scanf("%f",&e1.salary);





    system("cls");
    PrintEmployee(e1);


    return 0;
}
