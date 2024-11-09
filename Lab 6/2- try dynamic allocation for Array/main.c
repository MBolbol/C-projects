#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Array of pointers to integers read and write
    int col, _size = 3;
    printf("enter col size\n");
    scanf("%d",&col);

    int *ptrArr[_size];

    for(int i=0 ; i<_size; i++)
    {
        ptrArr[i] = malloc(col * sizeof(int));
    }

    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < col; j++) {
            printf("Enter value for element [%d][%d]: ", i, j);
            scanf("%d", &ptrArr[i][j]);
        }
    }

    printf("The 2D array values are:\n");
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element [%d][%d] = %d\n", i, j, ptrArr[i][j]);
        }
    }

    // Free allocated memory
    for (int i = 0; i < _size; i++) {
        free(ptrArr[i]);
    }
    return 0;
}
