#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int matrix[7][7];
    int i, j, num;
    int used[49] = {0};

    srand(time(NULL));

    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            while (1)
            {
                num = rand() % 49 + 1;
                if (used[num - 1] == 0)
                {
                    matrix[i][j] = num;
                    used[num - 1] = 1;
                    break;
                }
            }
        }
    }

    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
