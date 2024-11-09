#include <stdio.h>
#include <stdlib.h>

int main()
{
    //2- read string from user   char array[50]
    //   then print it reversly
    //while(ch=getch()!=13){}  Do it with while and read character by character
    //Enter message
    // my name is Mohamed
    //demahoM si eman ym

    char name[50]="Ali";
    char ch;
    int i=0;
    printf("Enter Message: \n");
    while((ch=getche())!=13)
    {
        name[i]=ch;
        i++;

    }
    name[i]='\0';

    printf("message: %s\n", name);

    /*
    while (name[i]!='\0')
    {
        printf("%c",name[i]);
        i++;

    }*/
    printf("Reversed message: \n");


    for(int j = i-1 ; j >= 0; j--)
    {
        printf("%c", name[j]);
    }
    return 0;
}
