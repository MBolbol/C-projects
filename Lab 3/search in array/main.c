#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int arr[10]= {0};
    printf("Enter the elements of arr:\n");
    for(int i = 0; i< 10; i++)
    {

        scanf("%d", &arr[i]);

    }

    printf("Enter num you want to search: ");
    scanf("%d", &num);
    int f = 0;
    if (f=1)
    {
        for(int i = 0; i< 10; i++)
        {
            if(num == arr[i])
            {
                printf("the num is : %d\n", arr[i]);
                printf("the index of your num in array is: %d\n", i);
                break;


            }
        }

    }
    else
    {
        printf("num not found");

    }

    return 0;
}
