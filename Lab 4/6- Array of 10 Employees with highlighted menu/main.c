#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

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

struct Employee
{

    int ssn;
    char name[20];
    int age;
    float salary,commission,deduction,netSalary;

};
void PrintEmployee(struct Employee emp)
{
    printf("SSN=%i\n",emp.ssn);
    printf("name=%s\n",emp.name);
    printf("age=%i\n",emp.age);
    printf("commission=%f\n",emp.commission);
    printf("deduction=%f\n",emp.deduction);
    printf("salary=%f\n",emp.salary);
    printf("netSalary=%f\n",(emp.salary + emp.commission) - emp.deduction );

}
void DisplayAllEmployees(struct Employee employees[],int count)
{
    for (int i = 0; i < count; i++)
    {
        if(employees[i].ssn != -1)
        {
            printf("Employee # %d\n",i+1);
            PrintEmployee(employees[i]);
            printf("##############\n");
        }

    }
    //wait to see
    getch();
}
void DisplayBySSN(struct Employee employees[],int count,int ssn)
{
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (employees[i].ssn == ssn)
        {
            PrintEmployee(employees[i]);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Employee with SSN %d not found.\n", ssn);
    }
    getch();
}
void DisplayByName(struct Employee employees[],int count, char name[20])
{
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(employees[i].name, name) == 0)
        {
            PrintEmployee(employees[i]);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Employee with name %s not found.\n", name);
    }
    getch();
}
void DeleteBySSN(struct Employee employees[],int count,int ssn)
{
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (employees[i].ssn == ssn)
        {
            employees[i].ssn = -1; // Mark as deleted
            found = 1;
            printf("Employee with SSN %d deleted.\n", ssn);
            break;
        }
    }
    if (!found)
    {
        printf("Employee with SSN %d not found.\n", ssn);
    }
    getch();
}
void DeleteByName(struct Employee employees[],int count,char name[20])
{
    int found = 0;
    for(int i=0; i<count; i++)
    {
        if(strcmp(employees[i].name, name) == 0)
        {
            employees[i].ssn = -1;
            found = 1;
            printf("Employee with name %s deleted.\n", name);
            break;
        }
    }
    if (!found)
    {
        printf("Employee with name %s not found.\n", name);
    }
    getch();
}
void DeleteAll(struct Employee employees[], int count)
{
    for (int i = 0; i < count; i++)
    {
        employees[i].ssn = -1;
    }
    printf("All employees have been deleted.\n");
    getch();
}

int isSSNUnique(struct Employee employees[], int count, int ssn)
{
    for (int i = 0; i < count; i++)
    {
        if (employees[i].ssn == ssn)
        {
            return 0; // SSN is not unique
        }
    }
    return 1; // SSN is unique
}

int main()
{
    char menu[8][15]= {"New","DisplayAll","DisplayBySSN","DisplayByName","DeleteById","DeleteByName","DeleteAll","Exit"};
    int cursor = 0;
    int flag =1;
    char ch;
    int ssn;
    char name[20];
    int index;
    char choic;
    struct Employee employees[10];
    int empCount = 0;

    for (int i = 0; i < 10; i++)
    {
        employees[i].ssn = -1;   // Initialize as empty
    }
    do
    {
        system("cls");
        for (int i = 0; i < 8; i++)
        {
            if(i==cursor)
            {
                textattr(4);
            }
            else
            {
                textattr(7);
            }
            gotoxy(50,10+i);
            _cprintf("%s",menu[i]);
        }
        ch=getch();
        switch(ch)
        {
        case EXTENDED:
            ch=getch();
            switch(ch)
            {
            case Up:
                cursor--;
                if(cursor<0)
                {
                    cursor=7;
                }
                break;
            case Down:
                cursor++;
                if(cursor>7)
                {
                    cursor=0;
                }
                break;
            case Home:
                cursor=0;
                break;
            case End:
                cursor=7;
                break;
            }
            break;
        case Enter:
            switch(cursor)
            {
            case 0:// New employee
                system("cls");
                if (empCount < 10)
                {
                    struct Employee emp;
                    do
                    {
                        do
                        {
                            printf("choose index in range 1 --> 10: \n");
                            scanf("%d",&index);
                        }
                        while(index<1 || index>10);
                        system("cls");

                        printf("Employee # %d\n",index);

                        gotoxy(5, 5);
                        printf("Enter SSN : \n");

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

                        do
                        {
                            gotoxy(8, 7);
                            scanf("%i",&emp.ssn);
                            _flushall();
                            if (!isSSNUnique(employees, empCount, emp.ssn))
                            {
                                printf("SSN %d already exists. Please enter a unique SSN.\n", emp.ssn);
                            }
                        }
                        while (!isSSNUnique(employees, empCount, emp.ssn));

                        gotoxy(58, 7);
                        gets(emp.name);
                        _flushall();

                        gotoxy(8, 12);
                        scanf("%i",&emp.age);

                        gotoxy(58, 12);
                        scanf("%f",&emp.salary);


                        gotoxy(8, 17);
                        scanf("%f",&emp.commission);

                        gotoxy(58, 17);
                        scanf("%f",&emp.deduction);

                        employees[empCount++] = emp;
                        index ++;
                        if (empCount >= 10)
                        {
                            printf("Max employees reached.\n");
                            break;
                        }
                        system("cls");
                        printf("Continue adding? (y/n): ");
                        _flushall();
                        do
                        {

                            scanf("%c", &choic);
                        }
                        while(choic != 'y' && choic != 'n');

                        system("cls");



                    }
                    while (choic == 'y' && empCount < 10);


                }
                else
                {
                    printf("Max employees reached.\n");
                }


                //wait to see
                getch();
                break;
            case 1://DisplayAll
                system("cls");

                DisplayAllEmployees(employees, empCount);
                getch();
                break;
            case 2: // Display by SSN
                system("cls");
                printf("Enter SSN to display: ");
                scanf("%d", &ssn);
                DisplayBySSN(employees, empCount, ssn);

                getch();
                break;
            case 3:// Display by Name
                system("cls");

                printf("Enter Name to display: ");
                scanf("%s", name);
                DisplayByName(employees, empCount,name);

                getch();
                break;
            case 4:// Delete by SSN
                system("cls");
                printf("Enter SSN to Delete: ");
                scanf("%d", &ssn);
                DeleteBySSN(employees,empCount,ssn);

                getch();
                break;
            case 5:// Delete by Name
                system("cls");
                printf("Enter Name to delete: ");
                scanf("%s", name);
                DeleteByName(employees,empCount, name);

                getch();
                break;
            case 6:// Delete All
                system("cls");
                DeleteAll(employees,empCount);

                getch();
                break;
            case 7:// Exit
                flag=0;
                break;
            }
            break;
        case Esc:
            flag=0;
            break;
        case Tab:
            cursor++;
            if(cursor>7)
            {
                cursor=0;
            }
            break;
        }

    }
    while(flag==1);

    return 0;
}
