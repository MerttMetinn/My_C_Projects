#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void censoring(char *sen, char *banned)
{
    char *token = strtok(banned, " ");

    while (token != NULL)
    {
        char *pos = strstr(sen, token); 
        for (; pos != NULL; pos = strstr(pos + 1, token))
        {
            memset(pos, '*', strlen(token));
        }
        token = strtok(NULL, " ");
    }

    printf("%s", sen);
}

int main()
{
    char sen[MAX_LENGTH];
    printf("Enter the sentence: \n");
    fgets(sen, MAX_LENGTH, stdin);

    sen[strcspn(sen, "\n")] = '\0';

    for (int i = 0; sen[i]; i++)
    {
        sen[i] = tolower(sen[i]);
    }

    char banned[MAX_LENGTH];
    printf("Enter the banned words: \n");
    fgets(banned, MAX_LENGTH, stdin);

    banned[strcspn(banned, "\n")] = '\0';

    for (int i = 0; banned[i]; i++)
    {
        banned[i] = tolower(banned[i]);
    }

    printf("------------------\n");
    censoring(sen, banned);

    return 0;
}
