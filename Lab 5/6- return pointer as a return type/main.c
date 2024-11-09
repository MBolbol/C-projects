#include <stdio.h>
#include <stdlib.h>

float* TryMe()
{
    static float tmpArr[5]={1,2,3,4,5};
    return tmpArr; //return address
}
int main()
{
    float *ptr = TryMe();

    ptr[0] = 100;
    ptr[3] =50.12;

    for (int i = 0; i < 5; i++) {
        printf("%f ", ptr[i]);
    }
    printf("\n");

    return 0;
}
