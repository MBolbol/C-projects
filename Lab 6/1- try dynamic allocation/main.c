#include <stdio.h>
#include <stdlib.h>

int main()
{
    // for pointer to integer read and write  2ways
    int _size;
    printf("Enter Array size\n");
    scanf("%d", &_size);
    int *ptr= malloc(_size * sizeof(int));
    //v1
    /*for (int i = 0; i < _size; i++)
    {
        printf("Enter # at index %i\n",i);
        scanf("%i",ptr+i);
    }
    for (int i = 0; i < _size; i++)
    {
        printf("# at index %i=%i\n",i,*(ptr+i));
    }*/

    //v2
    for (int i = 0; i < _size; i++)
    {
        printf("Enter # at index %i\n",i);
        scanf("%i",&ptr[i]);
    }
    for (int i = 0; i < _size; i++)
    {
        printf("# at index %i=%i\n",i,ptr[i]);
    }

    return 0;
}
