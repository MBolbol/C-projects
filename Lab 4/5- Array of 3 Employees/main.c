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
void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
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
    int index;
    char choic;
    struct Employee employees[3];
    int x = 5, y = 5;


    do
    {
        do
        {
            printf("choose index in range 0 --> 2: \n");
            scanf("%d",&index);
        }
        while(index<0 || index>2);
        system("cls");

            printf("Employee # %d\n",index);


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


            gotoxy(8, 7);
            scanf("%i",&employees[index].id);
            _flushall();

            gotoxy(58, 7);
            gets(employees[index].name);
            _flushall();

            gotoxy(8, 12);
            scanf("%i",&employees[index].age);

            gotoxy(58, 12);
            scanf("%f",&employees[index].commission);

            gotoxy(8, 17);
            scanf("%f",&employees[index].deduction);

            gotoxy(58, 17);
            scanf("%f",&employees[index].salary);
            system("cls");

            _flushall();
            printf("Continue y or n \n");
            do
            {

                scanf("%c", &choic);


            }
            while(choic != 'y' && choic != 'n');
            _flushall();
            system("cls");
            index++;



    }
    while(choic == 'y');

    getch();


    for (int i = 0; i < 3; i++)
    {
        printf("Employee # %d\n",i+1);
        PrintEmployee(employees[i]);
        printf("##############\n");

    }





    return 0;
}
