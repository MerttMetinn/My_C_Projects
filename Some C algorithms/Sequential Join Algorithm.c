#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main(void)
{
    int A[SIZE], B[SIZE], C[SIZE*2];

    srand(time(0));
    for (int i = 0; i < SIZE; i++)
    {
        A[i] = rand() % 50;
        B[i] = rand() % 50 + 25;
    }

    for (int i = 0; i < SIZE; i++)
    {
        C[i] = A[i];
        C[i + SIZE] = B[i];
    }

    for (int i = 0; i < SIZE*2; i++)
    {
        for (int j = i + 1; j < SIZE*2; j++)
        {
            if (C[i] > C[j])
            {
                int temp = C[i];
                C[i] = C[j];
                C[j] = temp;
            }
        }
    }

    for (int i = 0; i < SIZE*2; i++)
    {
        printf("%d ", C[i]);
    }
    printf("\n");

    return 0;
}
