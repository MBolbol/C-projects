#include <stdio.h>
#include <stdlib.h>

int main()
{
//2- pointer to array  read and write   3 ways


/*
    int arr[5];

    int *ptr;



    ptr=arr;


   /* //V1 Rarely used
    *ptr=10;
    ptr++;
    *ptr=20;
    ptr++;
    *ptr=30;
    ptr++;
    *ptr=40;
    ptr++;
    *ptr=50;
    ptr++;
    //REMEBER
    //put ptr points fst element of array AGAIN
    ptr=arr;
    printf("%i",*ptr);
    ptr++;
    printf("%i",*ptr);
    ptr++;
    printf("%i",*ptr);
    ptr++;
    printf("%i",*ptr);
    ptr++;
    printf("%i",*ptr);
    ptr++;
    //REMEMBER
    ptr=arr;



    int arr[5];
    int *ptr=arr;
    //V2
    *(ptr+0)=10;
    *(ptr+1)=20;
    *(ptr+2)=30;
    *(ptr+3)=40;
    *(ptr+4)=50;

    printf("%i",*(ptr+0));
    printf("%i",*(ptr+1));
    printf("%i",*(ptr+2));
    printf("%i",*(ptr+3));
    printf("%i",*(ptr+4));

*/
    int arr[5]={0};
    int *ptr=arr;

    //V3 [Most commonly used]
    //when pointer points array
    //,it acts like an array [indexer]



    for (int i = 0; i < 5; i++)
    {
        scanf("%i",&ptr[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%i",ptr[i]);
    }



    return 0;
}
