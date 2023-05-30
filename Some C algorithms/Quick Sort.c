#include <stdio.h>
#include <stdlib.h>

int compare_integers(const void *a, const void *b)
{
    int int_a = *((int *)a);
    int int_b = *((int *)b);

    if (int_a < int_b)
        return -1;
    if (int_a > int_b)
        return 1;
    return 0;
}

int main()
{
    int numbers[] = {5, 3, 1, 4, 2};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    qsort(numbers, n, sizeof(int), compare_integers);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }

    return 0;
}
