#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void giris(char cumle[])
{
    fgets(cumle, 100, stdin);

    if (cumle[strlen(cumle) - 1] == '\n')
    {
        cumle[strlen(cumle) - 1] = '\0';
    }

    printf("Girilen cumle: %s", cumle);
}

int elemansayisi(char cumle[])
{
    return strlen(cumle);
}

void bosluk_temizle(char cumle[])
{
    int i, j;
    for (i = 0, j = 0; cumle[i] != '\0'; i++)
    {
        if (cumle[i] != ' ')
        {
            cumle[j] = cumle[i];
            j++;
        }
    }
    cumle[j] = '\0';
}

int palindrome(char dizi[])
{
    int i;
    int j = strlen(dizi) - 1;

    for (i = 0; i < strlen(dizi) / 2; i++)
    {
        if (dizi[i] != dizi[j])
        {
            return 0;
        }
        j--;
    }

    return 1;
}

void ters_cevir(char cumle[], char ters[])
{
    int i, j = 0;

    for (i = strlen(cumle) - 1; i >= 0; i--)
    {
        ters[j] = cumle[i];
        j++;
    }

    ters[j] = '\0';

    printf("\nTers Cevrilen Cumle: %s", ters);
}

int main()
{
    char cumle[100];
    printf("Lutfen bir cumle giriniz: ");
    giris(cumle);
    printf("\nGirilen cumle %d karakter uzunlugundadir", elemansayisi(cumle));
    bosluk_temizle(cumle);

    printf("\nBosluklar temizlendi: ");
    printf("%s", cumle);
    printf("\nTemizlendikten sonra cumle, %d karakter uzunlugundadir", elemansayisi(cumle));

    char ters[100];
    ters_cevir(cumle, ters);

    if (palindrome(cumle))
    {
        printf("\nBu bir palindromdur.");
    }
    else
    {
        printf("\nBu bir palindrom degildir.");
    }

    return 0;
}
