#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10]= {0};
    printf("Enter the elements of arr:\n");
    for(int i = 0; i< 10; i++)
    {

        scanf("%d", &arr[i]);

    }
    printf("Array is: \n");
    for(int i = 0; i< 10; i++)
    {
        printf("%d\n", arr[i]);
    }
    int temp;


    for(int i = 0; i< 10; i++)
    {
        for(int j = 0; j< 10 ; j++)
        {

            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }
        }
    }
    printf("sorted Array is: \n");
    for(int i = 0; i< 10; i++)
    {
        printf("%d\n", arr[i]);
    }



    return 0;
}
