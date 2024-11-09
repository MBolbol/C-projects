#include <stdio.h>
#include <stdlib.h>

int main()
{
//program to identify ascii for any normal or Extended key
    char ch;
    printf("Enter ch\n");
    ch = getch();
    switch(ch)
    {
        case -32:
        ch=getch();
        printf("Extended with ascii %i",ch);
        break;
        default:
        printf("normal with ascii %i",ch);
        break;
    }

    return 0;
}
