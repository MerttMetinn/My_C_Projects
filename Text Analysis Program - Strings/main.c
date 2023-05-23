#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_vowels(char[]);
int count_consonants(char[]);
int count_digits(char[]);
int count_spaces(char[]);

int main()
{
    char line[100];
    int vowels = 0, consonants = 0, digits = 0, spaces = 0;

    printf("Enter text (maximum 100 characters): ");
    fgets(line, sizeof(line), stdin);

    vowels = count_vowels(line);
    consonants = count_consonants(line);
    digits = count_digits(line);
    spaces = count_spaces(line);

    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    printf("Number of digits: %d\n", digits);
    printf("Number of spaces: %d\n", spaces);

    return 0;
}

int count_vowels(char a[])
{
    int i, count = 0;
    for (i = 0; a[i] != '\0'; ++i)
    {
        if (isalpha(a[i]))
        {
            if (tolower(a[i]) == 'a' || tolower(a[i]) == 'e' ||tolower(a[i])== 'i' || tolower(a[i]) == 'o' || tolower(a[i]) == 'u')
            {
                ++count;
            }
        }
    }
    return count;
}

int count_consonants(char a[])
{
    int i, count = 0;
    for (i = 0; a[i] != '\0'; ++i)
    {
        if (isalpha(a[i]))
        {
            if (tolower(a[i]) != 'a' && tolower(a[i]) != 'e' && tolower(a[i]) != 'i' && tolower(a[i]) != 'o' && tolower(a[i]) != 'u')
            {
                ++count;
            }
        }
    }
    return count;
}

int count_digits(char a[])
{
    int i, count = 0;
    for (i = 0; a[i] != '\0'; ++i)
    {
        if (isdigit(a[i]))
        {
            ++count;
        }
    }
    return count;
}

int count_spaces(char a[])
{
    int i, count = 0;
    for (i = 0; a[i] != '\0'; ++i)
    {
        if (isspace(a[i]))
        {
            ++count;
        }
    }

    if (a[i-1] == '\n')
    {
        --count;
    }
    return count;
}
