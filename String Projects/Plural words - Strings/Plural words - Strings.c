#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char word[20];
    printf("Enter a word to make it plural: ");
    scanf("%s", word);

    int length = strlen(word);

    if (tolower(word[length - 1]) == 'y')
    {
        word[length - 1] = '\0';
        strcat(word, "ies");
    }
    else if (tolower(word[length - 1]) == 's' ||
             (tolower(word[length - 2]) == 'c' && tolower(word[length - 1]) == 'h') ||
             (tolower(word[length - 2]) == 's' && tolower(word[length - 1]) == 'h') ||
             tolower(word[length - 1]) == 'x')
    {
        strcat(word, "es");
    }
    else
    {
        strcat(word, "s");
    }

    printf("Plural form: %s\n", word);

    return 0;
}
