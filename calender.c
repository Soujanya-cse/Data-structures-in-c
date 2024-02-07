/*program to create a calender*/
#include <stdio.h>
#include <stdlib.h> //for malloc function

struct day
{
    char *dayname;
    int date, month, year;
    char *activity;
};

void create(struct day calender[7]);
void read(struct day calender[7]);
void display(struct day calender[7]);

int main()
{
    struct day calender[7];
    create(calender);
    read(calender);
    display(calender);
    return 0;
}

void create(struct day calender[7])
{
    for (int i = 0; i < 7; i++)
    {
        calender[i].dayname = NULL;
        calender[i].date = 0;
        calender[i].month = 0;
        calender[i].year = 0;
        calender[i].activity = NULL;
    }
}

void read(struct day calender[7])
{
    for (int i = 0; i < 7; i++)
    {
        calender[i].dayname = (char *)malloc(10 * sizeof(char));
        calender[i].activity = (char *)malloc(20 * sizeof(char));
        printf("Enter the name of day %d:\n", i + 1);
        scanf("%s", calender[i].dayname);
        printf("Enter the date of the day %d:\n", i + 1);
        scanf("%d%d%d", &calender[i].date, &calender[i].month, &calender[i].year);
        printf("Enter the activity for the day %d:\n", i + 1);
        scanf("%s", calender[i].activity);
    }
}

void display(struct day calender[7])
{
    printf("\nWeekly Report\n");
    for (int i = 0; i < 7; i++)
    {
        printf("Day %d:%s\tDate:%d/%d/%d\tActivity:%s\n", i + 1, calender[i].dayname, calender[i].date, calender[i].month, calender[i].year, calender[i].activity);
    }
}