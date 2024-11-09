#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

// Define keys
#define Enter 13
#define Esc 27
#define Tab 9
#define EXTENDED -32
#define Up 72
#define Down 80
#define Home 71
#define End 79

// Utility functions
void gotoxy(int column, int row) {
    COORD coord;
    coord.X = column;
    coord.Y = row;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textattr(int i) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

// Define Employee structure
struct Employee {
    int ssn;
    char name[20];
    int age;
    float salary, commission, deduction, netSalary;
};

// Print an Employee's data
void PrintEmployee(struct Employee param) {
    printf("SSN=%i\n", param.ssn);
    printf("name=%s\n", param.name);
    printf("age=%i\n", param.age);
    printf("commission=%f\n", param.commission);
    printf("deduction=%f\n", param.deduction);
    printf("salary=%f\n", param.salary);
    printf("netSalary=%f\n", (param.salary + param.commission) - param.deduction);
}

// Display all employees
void DisplayAllEmployees(struct Employee employees[], int count) {
    for (int i = 0; i < count; i++) {
        if (employees[i].ssn != -1) {
            printf("Employee # %d\n", i + 1);
            PrintEmployee(employees[i]);
            printf("##############\n");
        }
    }
    getch(); // Pause
}

// Display an employee by SSN
void DisplayBySSN(struct Employee employees[], int count, int ssn) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (employees[i].ssn == ssn) {
            PrintEmployee(employees[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with SSN %d not found.\n", ssn);
    }
    getch();
}

// Display an employee by Name
void DisplayByName(struct Employee employees[], int count, char name[20]) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].name, name) == 0) {
            PrintEmployee(employees[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with name %s not found.\n", name);
    }
    getch();
}

// Delete an employee by SSN
void DeleteBySSN(struct Employee employees[], int count, int ssn) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (employees[i].ssn == ssn) {
            employees[i].ssn = -1; // Mark as deleted
            found = 1;
            printf("Employee with SSN %d deleted.\n", ssn);
            break;
        }
    }
    if (!found) {
        printf("Employee with SSN %d not found.\n", ssn);
    }
    getch();
}

// Delete an employee by Name
void DeleteByName(struct Employee employees[], int count, char name[20]) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].name, name) == 0) {
            employees[i].ssn = -1;
            found = 1;
            printf("Employee with name %s deleted.\n", name);
            break;
        }
    }
    if (!found) {
        printf("Employee with name %s not found.\n", name);
    }
    getch();
}

// Delete all employees
void DeleteAll(struct Employee employees[], int count) {
    for (int i = 0; i < count; i++) {
        employees[i].ssn = -1;
    }
    printf("All employees have been deleted.\n");
    getch();
}

int main() {
    char menu[8][15] = {"New", "DisplayAll", "DisplayBySSN", "DisplayByName", "DeleteById", "DeleteByName", "DeleteAll", "Exit"};
    int cursor = 0;
    int flag = 1;
    char ch;
    int ssn;
    char name[20];
    int index;
    char choic;
    struct Employee employees[10];
    int empCount = 0;

    for (int i = 0; i < 10; i++) {
        employees[i].ssn = -1;   // Initialize as empty
    }

    do {
        system("cls");
        for (int i = 0; i < 8; i++) {
            textattr(i == cursor ? 4 : 7);
            gotoxy(50, 10 + i);
            printf("%s", menu[i]);
        }
        ch = getch();
        switch (ch) {
            case EXTENDED:
                ch = getch();
                if (ch == Up) cursor = cursor > 0 ? cursor - 1 : 7;
                else if (ch == Down) cursor = cursor < 7 ? cursor + 1 : 0;
                else if (ch == Home) cursor = 0;
                else if (ch == End) cursor = 7;
                break;
            case Enter:
                switch (cursor) {
                    case 0:  // New employee
                        system("cls");
                        if (empCount < 10) {
                            do {
                                printf("Employee #%d\n", empCount + 1);
                                printf("Enter SSN: ");
                                scanf("%d", &employees[empCount].ssn);
                                printf("Enter Name: ");
                                scanf("%s", employees[empCount].name);
                                printf("Enter Age: ");
                                scanf("%d", &employees[empCount].age);
                                printf("Enter Salary: ");
                                scanf("%f", &employees[empCount].salary);
                                printf("Enter Commission: ");
                                scanf("%f", &employees[empCount].commission);
                                printf("Enter Deduction: ");
                                scanf("%f", &employees[empCount].deduction);

                                empCount++;
                                if (empCount >= 10) {
                                    printf("Max employees reached.\n");
                                    break;
                                }

                                printf("Continue adding? (y/n): ");
                                do {
                                    scanf(" %c", &choic);
                                } while (choic != 'y' && choic != 'n');

                            } while (choic == 'y' && empCount < 10);

                        } else {
                            printf("Max employees reached.\n");
                        }
                        getch();
                        break;

                    case 1:  // Display All Employees
                        system("cls");
                        DisplayAllEmployees(employees, empCount);
                        break;

                    case 2:  // Display by SSN
                        system("cls");
                        printf("Enter SSN to display: ");
                        scanf("%d", &ssn);
                        DisplayBySSN(employees, empCount, ssn);
                        break;

                    case 3:  // Display by Name
                        system("cls");
                        printf("Enter Name to display: ");
                        scanf("%s", name);
                        DisplayByName(employees, empCount, name);
                        break;

                    case 4:  // Delete by SSN
                        system("cls");
                        printf("Enter SSN to Delete: ");
                        scanf("%d", &ssn);
                        DeleteBySSN(employees, empCount, ssn);
                        break;

                    case 5:  // Delete by Name
                        system("cls");
                        printf("Enter Name to delete: ");
                        scanf("%s", name);
                        DeleteByName(employees, empCount, name);
                        break;

                    case 6:  // Delete All
                        system("cls");
                        DeleteAll(employees, empCount);
                        break;

                    case 7:  // Exit
                        flag = 0;
                        break;
                }
                break;

            case Esc:
                flag = 0;
                break;

            case Tab:
                cursor = (cursor + 1) % 8;
                break;
        }

    } while (flag);

    return 0;
}
