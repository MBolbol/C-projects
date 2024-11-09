#include <stdio.h>
#include <stdlib.h>

int main()
{
//3*3     *    3*2   =  3*2
    int arr1[3][3]={0};
    int arr2[3][2]={0};
    int arr3[3][2]={0};

    printf("arr1 is:\n");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("Enter # at index %i,%i\n",i,j);
            scanf("%i",&arr1[i][j]);
        }
    }
    printf("arr2 is:\n");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<2; j++)
        {
            printf("Enter # at index %i,%i\n",i,j);
            scanf("%i",&arr2[i][j]);
        }
    }
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<2; j++)
        {
            for (int k=0; k<3; k++)
            {
                arr3[i][j] += arr1[i][k]*arr2[k][j] ;
            }
        }
    }
    printf("arr3 is:\n");
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<2; j++)
        {
            printf("%d\n", arr3[i][j]);
        }
    }

    return 0;
}

