#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

// ASCII and Control Characters
#define Enter 13
#define Esc 27
#define Backspace 8
#define EXTENDED -32
#define Left 75
#define Right 77
#define Up 72
#define Down 80
#define Home 71
#define End 79
#define Del 83

void gotoxy(int column, int row) {
    COORD coord;
    coord.X = column;
    coord.Y = row;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textattr(int i) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

#define MaxLines 6
#define MaxCharsPerLine 20

// Multi-line editor function
char** multiLineEditor(int maxLines, int maxCharsPerLine, int xPos, int yPos, int startAscii, int endAscii) {
    // Allocate memory for each line
    char** lines = (char**)malloc(maxLines * sizeof(char*));
    for (int i = 0; i < maxLines; i++) {
        lines[i] = (char*)malloc((maxCharsPerLine + 1) * sizeof(char));  // +1 for null terminator
        memset(lines[i], '\0', maxCharsPerLine + 1); // Initialize with null characters
    }

    int currentLine = 0;
    int currX = xPos;
    char* pcurr = lines[currentLine];
    char* pfirst = lines[currentLine];
    char* plast = lines[currentLine];
    int flag = 1;
    char ch;

    do {
        // Display lines and position cursor
        for (int i = 0; i < maxLines; i++) {
            gotoxy(xPos, yPos + i);
            for (int j = 0; j < maxCharsPerLine; j++) {
                if (&lines[i][j] == pcurr) {
                    textattr(4); // Highlight cursor position
                } else {
                    textattr(7);
                }
                printf("%c", lines[i][j] != '\0' ? lines[i][j] : '-'); // Display char or placeholder
            }
        }

        gotoxy(currX, yPos + currentLine);
        ch = getch();

        switch (ch) {
            case EXTENDED:
                ch = getch();
                switch (ch) {
                    case Left:
                        if (pcurr > pfirst) {
                            pcurr--;
                            currX--;
                        }
                        break;
                    case Right:
                        if (pcurr < plast) {
                            pcurr++;
                            currX++;
                        }
                        break;
                    case Up:
                        if (currentLine > 0) {
                            currentLine--;
                            pfirst = lines[currentLine];
                            pcurr = plast = pfirst + strlen(lines[currentLine]);
                            currX = xPos + (pcurr - pfirst);
                        }
                        break;
                    case Down:
                        if (currentLine < maxLines - 1) {
                            currentLine++;
                            pfirst = lines[currentLine];
                            pcurr = plast = pfirst + strlen(lines[currentLine]);
                            currX = xPos + (pcurr - pfirst);
                        }
                        break;
                    case Home:
                        pcurr = pfirst;
                        currX = xPos;
                        break;
                    case End:
                        pcurr = plast;
                        currX = xPos + (plast - pfirst);
                        break;
                    case Del:
                        if (pcurr < plast) {
                            char* temp = pcurr;
                            while (temp < plast) {
                                *temp = *(temp + 1);
                                temp++;
                            }
                            plast--;
                        }
                        break;
                }
                break;
            case Enter:
                flag = 0; // End input on Enter
                break;
            case Backspace:
                if (pcurr > pfirst) {
                    pcurr--;
                    currX--;
                    char* temp = pcurr;
                    while (temp < plast) {
                        *temp = *(temp + 1);
                        temp++;
                    }
                    plast--;
                }
                break;
            default:
                if (isprint(ch) && ch >= startAscii && ch <= endAscii) {
                    if (pcurr < pfirst + maxCharsPerLine) {
                        if (pcurr == plast) {
                            *pcurr = ch;
                            pcurr++;
                            currX++;
                            plast++;
                        } else {
                            char* temp = plast;
                            while (temp > pcurr) {
                                *temp = *(temp - 1);
                                temp--;
                            }
                            *pcurr = ch;
                            pcurr++;
                            currX++;
                            plast++;
                        }
                    }
                }
                break;
        }
    } while (flag);

    textattr(7); // Reset text attribute to normal
    return lines;
}

// Employee structure
struct Employee {
    int id;
    char name[MaxCharsPerLine + 1];
    int age;
    float salary, commission, deduction;
};

// Function to print Employee details
void PrintEmployee(struct Employee emp) {
    printf("ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Age: %d\n", emp.age);
    printf("Salary: %.2f\n", emp.salary);
    printf("Commission: %.2f\n", emp.commission);
    printf("Deduction: %.2f\n", emp.deduction);
    printf("Net Salary: %.2f\n", (emp.salary + emp.commission) - emp.deduction);
}

// Main function
int main() {
    struct Employee emp;

    // Multi-line editor for input
    char** input = multiLineEditor(MaxLines, MaxCharsPerLine, 20, 5, '0', 'z'); // Accepts both numbers and letters

    // Parse the multi-line input into Employee fields
    emp.id = atoi(input[0]);
    strncpy(emp.name, input[1], MaxCharsPerLine);
    emp.name[MaxCharsPerLine] = '\0';
    emp.age = atoi(input[2]);
    emp.commission = atof(input[3]);
    emp.deduction = atof(input[4]);
    emp.salary = atof(input[5]);

    // Free allocated memory for lines
    for (int i = 0; i < MaxLines; i++) {
        free(input[i]);
    }
    free(input);

    system("cls"); // Clear screen
    PrintEmployee(emp); // Print Employee data

    return 0;
}
