#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2;
    char arr[8][8];
    srand(time(NULL));

    for(int k = 0; k<8; k++)
    {
        for(int m = 0; m<8; m++)
        {
            arr[k][m] = '-';
        }
    }

    for(int k = 0; k<9; k++)
    {
        while(1)
        {
            num1 = rand()%8;
            num2 = rand()%8;
            if(arr[num1][num2]=='-')
            {
                arr[num1][num2] = '*';
                break;
            }
        }
    }

    for(int k = 0; k<8; k++)
    {
        for(int m = 0; m<8; m++)
        {
            printf("%c  ",arr[k][m]);
        }
        printf("\n");
    }


    return 0;
}
