#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    int id;
    char name[12];
    int age;
};

int main()
{
    struct Employee e1;  //20B
    e1.id=1;
    strcpy( e1.name,"Sara");
    e1.age=22;

    struct Employee *empPtr; //4 or 8B
    empPtr=&e1; //T


    //execlusive with ptr to struct  -> arrow operator
    empPtr->id=1;

    strcpy(empPtr->name,"Ali");
    empPtr->age=22;


    printf("%d\n", e1.id);
    printf("%s\n", e1.name);
    printf("%d\n", e1.age);

}
