#include <stdio.h>
#include <stdlib.h>

int main()
{
    //5-2D Array
    //array [3][4]
    //calculate average of columns
    //int avg[4]
    int arr[3][4];
    int sum[4]= {0};
    printf("Enter the elements of arr:\n");

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            printf("Enter # at index %i,%i\n",i,j);
            scanf("%i",&arr[i][j]);
        }
    }
    int avg[4] = {0};
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<3; j++)
        {
            sum[i]+=arr[j][i];

        }
        avg[i] = sum[i] / 3;
        printf("average is: %d\n", avg[i]);
    }





    return 0;
}
