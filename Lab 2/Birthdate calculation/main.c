#include <stdio.h>
#include <stdlib.h>

int main()
{

    int currentYear= 2024;
    int currentMonth= 10;
    int currentday= 28;

    int birthYear;
    int birthMonth;
    int birthDay;

    int resYear = 0;
    int resMonth = 0;
    int resDay = 0;

    int maxDay ;

    // إدخال السنة وتحقق من أنها بين 1980 و2024

    do
    {
        printf("plz enter your year: \n");
        scanf("%d", &birthYear);

    }
    while(birthYear < 1980 || birthYear > 2024);
    //////////////////////////////////////////////////////////
    // إدخال الشهر وتحقق من أنه بين 1 و12
    do
    {
        printf("plz enter your month: \n");
        scanf("%d", &birthMonth);
    }
    while(birthMonth < 1 || birthMonth > 12);
///////////////////////////////////////////////////////////////////////////

    // حساب الحد الأقصى لعدد الأيام في شهر الميلاد

    switch (birthMonth)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            maxDay = 31;

            break;
        case 4:
        case 6:
        case 9:
        case 11:
            maxDay = 30;


            break;
        case 2:
            if(birthYear % 4 == 0 && (birthYear % 100 != 0 || birthYear % 400 == 0))
            {
                maxDay = 29;
            }
            else
            {
                maxDay = 28;

            }

            break;

        }
    do
    {
        printf("plz enter your day: \n");
        scanf("%d", &birthDay);
    }
    while(birthDay < 1 || birthDay > maxDay);


    if (currentday < birthDay)
    {
        currentMonth -= 1;

        switch (currentMonth)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                currentday += 31;

                break;
            case 4:
            case 6:
            case 9:
            case 11:
                currentday += 30;

                break;

            case 2:
                if(currentYear % 4 == 0 && (currentYear % 100 != 0 || currentYear % 400 == 0))
                {
                    currentday += 29;

                }
                else
                {
                    currentday += 28;

                }
                break;

        }
    }


    // تعديل الشهر إذا كان الشهر الحالي أقل من شهر الميلاد

    if (currentMonth < birthMonth)
    {
        currentYear -= 1;
        currentMonth += 12;
    }

    resYear = currentYear - birthYear;
    resMonth = currentMonth - birthMonth;
    resDay = currentday - birthDay;


    printf("Your Birthdate is: %d years %d month %d days",resYear, resMonth, resDay);

    return 0;
}
