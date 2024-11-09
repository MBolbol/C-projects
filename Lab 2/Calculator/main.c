#include <stdio.h>
#include <stdlib.h>

int main()
{
    double num1,num2;
    char op;
    char choice;


    do
    {
        system("cls");
        printf("Enter a number1 : \n");
        scanf("%lf", &num1);

        printf("Enter operator: \n");
        scanf(" %c", &op);


        printf("Enter a number2 : \n");
        scanf("%lf", &num2);


        switch(op)
        {
        case '+':
            printf("%lf \n", num1 + num2);
            break;

        case '-':
            printf("%lf \n", num1 - num2);
            break;
        case '*':
            printf("%lf \n", num1 * num2);
            break;
        case '/':
            printf("%lf \n", num1 / num2);
            break;

        }


        _flushall();
        printf("Continue ??? y or n\n");

        scanf("%c", &choice);

    }
    while(choice == 'y');

    printf("program end");


    return 0;
}
