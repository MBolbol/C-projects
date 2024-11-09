#include <stdio.h>
#include <stdlib.h>

int main()
{
    int col,row;
    printf("Enter row size: \n");
    scanf("%d", &row);
    printf("Enter col size: \n");
    scanf("%d", &col);


    int* *ptrArr;

    ptrArr = malloc(row * sizeof(int *));

    for(int i=0 ; i<row; i++)
    {

        ptrArr[i] = malloc(col * sizeof(int));


    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter # at index [%d][%d] \n",i,j);
            scanf("%i",&ptrArr[i][j]);
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("# at index [%d][%d]=%d\n",i,j,ptrArr[i][j]);
        }
    }

    // Free allocated memory
    for (int i = 0; i < row; i++)
    {
        free(ptrArr[i]);
    }
    free(ptrArr);
    return 0;
}
