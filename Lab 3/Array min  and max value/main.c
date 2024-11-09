#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Arrays of 10 places of integer int arr[10]
    //Read ALL Data From user in Runtime
    int arr[10]={0};
    printf("Enter the elements of arr:\n");
    for(int i = 0; i< 10; i++)
    {

        scanf("%d", &arr[i]);

    }
    int max = arr[0];
    for(int i = 0; i< 10; i++){

        if (arr[i] > max)
        {
            max = arr[i];

        }
    }
    int min = arr[0];
    for(int i = 0; i< 10; i++){

        if (arr[i]< min)
        {
            min = arr[i];

        }
    }
    printf("Array is: \n");
    for(int i = 0; i< 10; i++)
    {
         printf("%d\n", arr[i]);
    }

printf("the max value is: %d\n",max);
printf("the min value is: %d",min);



    return 0;
}
