#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct ogrenci
{
    char numara[20];
    char adsoyad[50];
    float ortalama;
    int akts;
    int giris_yili;
};

struct ogrenci BasariliOgrenciBul(struct ogrenci o1, struct ogrenci o2)
{
    if(o1.ortalama == o2.ortalama)
    {
        if(o1.akts == o2.akts)
        {
            if(o1.giris_yili == o2.giris_yili)
            {
                if(rand()%2==0)
                {
                    return o1;
                }
                return o2;
            }
            else
            {
                if(o1.giris_yili > o2.giris_yili)
                {
                    return o2;
                }
                return o1;
            }
        }
        else
        {
            if(o1.akts > o2.akts)
            {
                return o1;
            }
            return o2;
        }
    }
    else
    {
        if(o1.ortalama > o2.ortalama)
        {
            return o1;
        }
        return o2;
    }
};

int main()
{
    struct ogrenci o1, o2, o3;

    printf("Birinci ogrencinin bilgilerini giriniz:\n");
    printf("Numara: ");
    fgets(o1.numara, 20, stdin);
    printf("Ad soyad: ");
    fgets(o1.adsoyad, 50, stdin);
    printf("Ortalama: ");
    scanf("%f", &o1.ortalama);
    printf("Akts: ");
    scanf("%d", &o1.akts);
    printf("Giris yili: ");
    scanf("%d", &o1.giris_yili);

    getchar();

    printf("\nIkinci ogrencinin degerlerini giriniz:\n");
    printf("Numara: ");
    fgets(o2.numara, 20, stdin);
    printf("Ad soyad: ");
    fgets(o2.adsoyad, 50, stdin);
    printf("Ortalama: ");
    scanf("%f", &o2.ortalama);
    printf("Akts: ");
    scanf("%d", &o2.akts);
    printf("Giris yili: ");
    scanf("%d", &o2.giris_yili);

    o3 = BasariliOgrenciBul(o1, o2);

    printf("\nDaha basarili ogrenci:\n");
    printf("Numarasi: %s", o3.numara);
    printf("Adi soyadi: %s", o3.adsoyad);
    printf("Ortalamasi: %.2f\n", o3.ortalama);
    printf("Akts: %d\n", o3.akts);
    printf("Giris yili: %d\n", o3.giris_yili);

    return 0;
}
