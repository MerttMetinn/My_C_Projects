#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char sen[80];
    char word[20];
    char *ptr;
    int count = 0;

    printf("Enter a sentence: ");
    fgets(sen, 80, stdin);

    printf("Enter the word you are looking for: ");
    scanf("%s", word);

    ptr = strstr(sen, word);

    while (ptr != NULL)
    {
        count++;
        ptr++;
        ptr = strstr(ptr, word);
    }

    printf("The word \"%s\" appears %d times in the sentence.", word, count);

    return 0;
}
