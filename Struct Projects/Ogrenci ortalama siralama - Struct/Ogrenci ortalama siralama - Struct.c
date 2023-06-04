#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//KONU SONU CALISMA SORULARI

//1-Uyeleri asagidaki gibi olan ogrenci adindaki yapiyi tanimlayiniz. Bu yapi
//turunde tanimlanmis 10 elemanli bir dizi tanimlayip elemanlarini klavyeden giren ve
//ekranda ortalamasina gore buyukten kucuge olacak sekilde ekranda listeleyen programi
//yaziniz.

struct ogrenci
{
    char ad[20];
    char soyad[20];
    float ortalama;
};

int main()
{
    int kisiSayisi;
    printf("Kac kisi girilecek? ");
    if (scanf("%d", &kisiSayisi) != 1) {
        printf("Hata: Girdi okunamadi\n");
        return 1;
    }

    struct ogrenci kisiler[kisiSayisi];

    printf("\nUyari : \" isim (bosluk) soyisim (bosluk) ortalama \" tipinde giriniz.\n\n");

    for(int i=0; i<kisiSayisi ;i++)
    {
        printf("%d. kisinin adi,soyadi,ortalamasini giriniz: ",i+1);
        if (scanf("%s %s %f", kisiler[i].ad, kisiler[i].soyad, &kisiler[i].ortalama) != 3) {
            printf("Hata: Girdi okunamadi\n");
            return 1;
        }
    }

    struct ogrenci temp;
    for(int i=0; i<kisiSayisi-1 ;i++)
    {
        for(int j=0; j<kisiSayisi-1-i ;j++)
        {
            if(kisiler[j].ortalama < kisiler[j+1].ortalama)
            {
                temp = kisiler[j];
                kisiler[j] = kisiler[j+1];
                kisiler[j+1] = temp;
            }
        }
    }

    printf("\n\n----------------Liste---------------\n\n");

    for(int i=0; i<kisiSayisi ;i++)
    {
        printf("%s %s %.2f\n",kisiler[i].ad,kisiler[i].soyad,kisiler[i].ortalama);
    }

    return 0;
}
