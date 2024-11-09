#include <stdio.h>
#include <stdlib.h>

int main()
{
//pointer to integer  read & write

    int x;
    int *ptr;
    ptr = &x;
    scanf("%d", ptr);
    printf("%d", *ptr);


    return 0;
}
