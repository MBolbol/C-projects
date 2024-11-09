#include <stdio.h>
#include <stdlib.h>

void SwapA(int* left,int* right)
{
    int tmp;
    tmp=*left;
    *left=*right;
    *right=tmp;
}

int main()
{
    int x=3,y=5;
    printf("Before Swap\n");
    printf("x=%i\n",x); //3
    printf("y=%i\n",y); //5
    SwapA(&x,&y);   //pass by addresses
    printf("After Swap\n");
    printf("x=%i\n",x); //5
    printf("y=%i\n",y); //3
}
