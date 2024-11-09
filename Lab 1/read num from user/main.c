#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;

    printf("Enter the number: ");
    scanf("%d", &x);

    printf("address is: %x", &x);
    return 0;
}
