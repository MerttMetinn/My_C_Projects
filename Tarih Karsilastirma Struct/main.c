#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Tarih
{
    int gun;
    int ay;
    int yil;
};

struct Tarih Kontrol (int gun, int ay, int yil)
{
    struct Tarih t;
    if(gun>31 || ay>12)
    {
        t.gun=0;
        t.ay=0;
        t.yil=0;
    }
    else
    {
        t.gun=gun;
        t.ay=ay;
        t.yil=yil;
    }

    return t;
}

int karsilastir(struct Tarih t1,struct Tarih t2)
{
    if((t1.yil>t2.yil) || ((t1.yil == t2.yil) && (t1.ay>t2.ay)) || ((t1.yil == t2.yil) && (t1.ay==t2.ay) && (t1.gun>t2.gun)))
    {
    return 1;
    }

    if((t1.yil == t2.yil) && (t1.ay==t2.ay) && (t1.gun==t2.gun))
    {
        return 0;
    }
    return -1;
}

int main()
{
    struct Tarih t3,t4;

    t3=Kontrol(1,5,2024);
    t4=Kontrol(4,5,2023);

    int sonuc = karsilastir(t3,t4);

    if(sonuc == 0)
    {
        printf("Esit");
    }
    else if(sonuc == 1)
    {
        printf("t1 tarihi t2 tarihinden buyuktur");
    }
    else
    {
        printf("t2 tarihi t1 tarihinden buyuktur");
    }
    return 0;
}
