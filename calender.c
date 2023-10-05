#include <stdio.h>

int firstDayOfYear(int year)
{
    int day = (year*365 + ((year-1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7;
    return day;
}

int main(void)
{
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int daysInMonth [] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int i,j,totalDays, weekDay=0,spaceCounter = 0, year;

    printf("Enter the Year: ");
    scanf("%d", &year);
    printf("------------------ Welcome to %d --------------------", year);

    if((year%4==0 && year % 100 != 0) || (year % 400 == 0)) daysInMonth[1] = 29;

    weekDay = firstDayOfYear(year);

    for(i=0; i<12; i++)
    {
        printf("\n\n____________________    %s  ______________________\n\n", months[i]);
        printf("\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n");


        for(spaceCounter = 1; spaceCounter<=weekDay; spaceCounter++) printf("      ");

        totalDays = daysInMonth[i];
        for(j=1; j<=totalDays;j++)
        {
            printf("%6d", j);
            weekDay++;
            if(weekDay>6)
            {
                weekDay =0;
                printf("\n");
            }
        }
    }
    return 0;
}