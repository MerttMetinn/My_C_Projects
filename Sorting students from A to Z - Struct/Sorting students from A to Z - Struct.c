#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*END OF SUBJECT STUDY QUESTIONS

2-Define the structure with the name of the student whose members are as follows.
Write a program that defines a 10-element array defined in this structure type,
enters its elements from the keyboard, and lists them on the screen in alphabetical
order from A to Z according to their surname.
*/
struct student
{
    char name[20];
    char surname[20];
    float average;
};

int main()
{
    int count;
    printf("How many people will enter? ");
    if (scanf("%d", &count) != 1)
    {
        printf("Error: Input could not be read\n");
        return 1;
    }

    struct student persons[count];

    printf("\nWarning :Enter in \" name (space) surname (space) average \" type.\n\n");

    for(int i=0; i<count ; i++)
    {
        printf("%d-) Enter the name , surname , average : ",i+1);
        if (scanf("%s %s %f", persons[i].name, persons[i].surname, &persons[i].average) != 3)
        {
            printf("Error: Input could not be read\n");
            return 1;
        }
    }

    struct student temp;
    for(int i=0; i<count-1 ; i++)
    {
        for(int j=0; j<count-1-i ; j++)
        {
            if(strcmp(persons[j].surname, persons[j+1].surname) > 0)
            {
                temp = persons[j];
                persons[j] = persons[j+1];
                persons[j+1] = temp;
            }
        }
    }

    printf("\n\n----------------List---------------\n\n");

    for(int i=0; i<count ; i++)
    {
        printf("%s %s %.2f\n",persons[i].name,persons[i].surname,persons[i].average);
    }

    return 0;
}
