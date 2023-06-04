#include <stdio.h>
#include <string.h>
#include <unistd.h>

void print_name(char *name)
{
    int i, j;
    float delay_time = 0.5;
    for(i=strlen(name) ; i>0 ; i--)
    {
        for(j=0; j<i ; j++)
        {
            printf("%c", name[j]);
        }
        printf("\n");
        usleep(delay_time * 1000000);
    }
}

int main()
{
    char name[100];
    printf("Please enter a name: ");
    scanf("%s", name);
    print_name(name);
    return 0;
}
