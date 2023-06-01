#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool asalmi(int s1)
{
    bool sonuc = true;
    int i;
    for(i=2 ; i<s1 ; i++)
    {
        if(s1%i == 0)
        {
            sonuc = false;
            break;
        }
    }
    return sonuc;
}

int main ()
{
    int sayi;
    scanf("%d",&sayi);
    asalmi(sayi) ? printf("\nAsaldir") :  printf("\nAsal degildir");
    return 0;
}
