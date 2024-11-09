#include <stdio.h>
#include <stdlib.h>

int main()
{
    //1-Read first name ,last name
    // then fill in container full name
/////  and print it
//////strcat ,strcpy    fn[10]   ln[10]      fulln[21]
////// gets() puts()
    char fname[10]= "Abdo";
    char lname[10]= "Bolbol";
    char fullName[21];

    printf("Enter your first name: %s\n", fname);
    gets(fname);
    printf("Enter your last name: %s\n", lname);
    gets(lname);


    strcpy(fullName,fname);
    strcat(fullName," ");
    strcat(fullName,lname);

    printf("your full name is: \n%s", fullName);

    return 0;
}
