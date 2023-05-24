#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct banka_hesabi
{
    char ad[50];
    int hesap_no;
    float bakiye;
};

void para_yatir(struct banka_hesabi *hesap, float miktar)
{
    hesap->bakiye += miktar;
    printf("%s hesabina %.2f TL yatirildi. Yeni bakiye: %.2f TL\n", hesap->ad, miktar, hesap->bakiye);
}

void para_cek(struct banka_hesabi *hesap, float miktar)
{
    if (hesap->bakiye >= miktar)
    {
        hesap->bakiye -= miktar;
        printf("%s hesabindan %.2f TL cekildi. Yeni bakiye: %.2f TL\n", hesap->ad, miktar, hesap->bakiye);
    }
    else
    {
        printf("Hesap bakiyesi yetersiz. Mevcut bakiye: %.2f TL\n", hesap->bakiye);
    }
}

void bakiye_sorgula(struct banka_hesabi *hesap)
{
    printf("%s hesabinin bakiyesi: %.2f TL\n", hesap->ad, hesap->bakiye);
}

int main()
{
    struct banka_hesabi musteri;
    int secim;
    float miktar;

    printf("Adiniz: ");
    fgets(musteri.ad,50,stdin);
    musteri.ad[strcspn(musteri.ad, "\n")] = '\0';
    //Burada strcspn fonksiyonunu kullanarak fgets ile aldýðýmýz metinin son karakteri olan '\n' karakterini '\0' ile deðiþtiriyoruz

    printf("Hesap no: ");
    scanf("%d",&musteri.hesap_no);

    printf("Bakiyeniz: ");
    scanf("%f",&musteri.bakiye);

    do
    {
        printf("\n1- Bakiye sorgula\n");
        printf("2- Para yatir\n");
        printf("3- Para cek\n");
        printf("4- Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        switch (secim)
        {
        case 1:
            bakiye_sorgula(&musteri);
            break;
        case 2:
            printf("Yatirilacak miktar: ");
            scanf("%f", &miktar);
            para_yatir(&musteri, miktar);
            break;
        case 3:
            printf("Cekilecek miktar: ");
            scanf("%f", &miktar);
            para_cek(&musteri, miktar);
            break;
        case 4:
            printf("Programdan cikiliyor.\n");
            break;
        default:
            printf("Gecersiz secim.\n");
            break;
        }

    }
    while (secim != 4);

    return 0;
}
