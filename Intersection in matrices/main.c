#include <stdio.h>
#include <stdlib.h>

void enterArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int value;
        do
        {
            printf("Enter element %d: ", i+1);
            scanf("%d", &value);
            if (value < 0 || value > 100)
            {
                printf("Invalid input. Number should be between 0 and 100.\n");
            }
        }
        while (value < 0 || value > 100);

        int exists = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] == value)
            {
                exists = 1;
                break;
            }
        }
        if (exists)
        {
            printf("Invalid input. Number already exists in the array.\n");
            i--;
        }
        else
        {
            arr[i] = value;
        }
    }
}

void intersectionOfArrays(int arr1[], int size1, int arr2[], int size2, int intersectionArr[], int *newSize)
{
    int count = 0;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                int exists =0;
                for (int k = 0; k < count; k++)
                {
                    if (intersectionArr[k] == arr1[i])
                    {
                        exists = 1;
                        break;
                    }
                }
                if (!exists)
                {
                    intersectionArr[count] = arr1[i];
                    count++;
                }
                break;
            }
        }
    }
    *newSize = count;
}

void sortArray(int arr[], int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void printArray(int arr[], int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i != size-1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

int main()
{
    int size1, size2, size3;
    int arr1[15], arr2[15], intersectionArr[15];

    do
    {
        printf("Enter size of first array (4-15): ");
        scanf("%d", &size1);
        if(size1 < 4 || size1 > 15)
        {
            printf("Invalid size. Size should be between 4 and 15.\n");
        }
    }
    while (size1 < 4 || size1 > 15);
    enterArray(arr1, size1);

    do
    {
        printf("Enter size of second array (4-15): ");
        scanf("%d", &size2);
        if (size2 < 4 || size2 > 15)
        {
            printf("Invalid size. Size should be between 4 and 15.\n");
        }
    }
    while (size2 < 4 || size2 > 15);
    enterArray(arr2, size2);

    intersectionOfArrays(arr1, size1, arr2, size2, intersectionArr, &size3);
    sortArray(intersectionArr, size3);

    if (size3 == 0)
    {
        printf("Intersection of arrays is empty.\n");
    }
    else
    {
        printf("Intersection of arrays: ");
        printArray(intersectionArr, size3);
    }

    return 0;
}
