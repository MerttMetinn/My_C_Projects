#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int max = 0;
    int temp;
    char sentence[100];
    fgets(sentence, 100, stdin);

    for (int i = 97; i <= 122; i++)
    {
        int count = 0;
        for (int j = 0; j < strlen(sentence); j++)
        {
            if ((int)sentence[j] == i)
            {
                count++;
            }
        }
        if (count > max)
        {
            max = count;
            temp = i;
        }
    }
    printf("%c : %d", temp, max);
    return 0;
}
