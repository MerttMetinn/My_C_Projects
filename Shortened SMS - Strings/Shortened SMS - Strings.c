#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100

void shortened_sms(char sentence[MAX_SENTENCE_LENGTH])
{
    int sentence_length = strlen(sentence);

    for (int i = 0; i < sentence_length + 2; i++)
    {
        printf("-");
    }
    printf("\n");

    printf("Shortened SMS: ");

    printf("%c", sentence[0]);

    for (int i = 1; i < sentence_length; i++)
    {
        if (tolower(sentence[i]) == 'a' || tolower(sentence[i]) == 'e'
                || tolower(sentence[i]) == 'o' || tolower(sentence[i]) == 'u' || tolower(sentence[i]) == 'i')
        {
            if (sentence[i-1] == ' ')
            {
                printf("%c", sentence[i]);
            }
        }
        else
        {
            printf("%c", sentence[i]);
        }
    }
}

int main()
{
    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    shortened_sms(sentence);

    return 0;
}
