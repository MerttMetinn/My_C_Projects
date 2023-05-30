#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr[8][8];
    int num1,num2;
    int found = 0;

    srand(time(NULL));

    for(int i = 0; i<8; i++)
    {
        for(int j = 0; j<8; j++)
        {
            arr[i][j] = '-';
        }
    }

    for(int i = 0; i<8; i++)
    {
        found = 0;
        while(1)
        {
            num1 = rand()%8;
            num2 = rand()%8;

            for(int j = 0; j<8; j++)
            {
                if(arr[num1][j]=='R')
                {
                    found = 1;
                    break;
                }
            }

            for(int j = 0; j<8; j++)
            {
                if(arr[j][num2]=='R')
                {
                    found = 1;
                    break;
                }
            }

            if(found==1)
            {
                found = 0;
                continue;
            }
            else
            {
                arr[num1][num2] = 'R';
                break;
            }


        }
    }

    for(int i = 0; i<8; i++)
    {
        for(int j = 0; j<8; j++)
        {
            printf("%c  ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
