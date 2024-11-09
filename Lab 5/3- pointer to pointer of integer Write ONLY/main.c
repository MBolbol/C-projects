#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Pointer to Pointer to integer

    int x=10;
    int *ptr;
    int* *ptrTptr;
    ptr=&x;
    ptrTptr=&ptr;



    printf("%d",   **ptrTptr   ); //10


    return 0;
}
