#include <stdio.h>
#include <stdlib.h>

int main()
{
    //3*2    *  2*1  =  3*1
    int arr1[3][2]={0};
    int arr2[2][1]={0};
    int arr3[3][1]={0};

    printf("arr1 is:\n");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<2; j++)
        {
            printf("Enter # at index %i,%i\n",i,j);
            scanf("%i",&arr1[i][j]);
        }
    }
    printf("arr1 is:\n");
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<1; j++)
        {
            printf("Enter # at index %i,%i\n",i,j);
            scanf("%i",&arr2[i][j]);
        }
    }
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<1; j++)
        {
            for (int k=0; k<2; k++)
            {
                arr3[i][j] += arr1[i][k]*arr2[k][j] ;
            }
        }
    }
    printf("arr3 is:\n");
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<1; j++)
        {
            printf("%d\n", arr3[i][j]);
        }
    }

    return 0;
}
