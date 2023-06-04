#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
END OF SUBJECT STUDY QUESTIONS

8-Define the structure named student whose members are as follows.
In this type of structure you have defined, define two variables named a1 and a2 within the main function.
Specify their initial values as (2, "Ahmet", "Gedik" , 2.3, 'M') and (5, "Oya" , "Turkali" , 4.3 , 'F').
Write a function called swap that takes these two variables and transfers their values to each other.
After the function is finished, the value in a1 should be transferred to a2, and the values in a2 should be transferred to al.
To show this, print the values of the variables to the screen after the function call.

*/

struct student
{
    int order;
    char name[20];
    char surname[20];
    float average;
    char gender;
};

void swap(struct student *a, struct student *b)
{
    struct student temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    struct student a1 = {2, "Ahmet", "Gedik", 2.3, 'M'};
    struct student a2 = {5, "Oya", "Turkali", 4.3, 'F'};

    printf("a1: %d %s %s %.1f %c\n", a1.order, a1.name, a1.surname, a1.average, a1.gender);
    printf("a2: %d %s %s %.1f %c\n", a2.order, a2.name, a2.surname, a2.average, a2.gender);

    swap(&a1, &a2);
    printf("\nAfter the swapping\n\n");

    printf("a1: %d %s %s %.1f %c\n", a1.order, a1.name, a1.surname, a1.average, a1.gender);
    printf("a2: %d %s %s %.1f %c\n", a2.order, a2.name, a2.surname, a2.average, a2.gender);

    return 0;
}
