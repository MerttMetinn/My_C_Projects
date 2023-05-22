#include <stdio.h>
#include <string.h>

int main() {
   char kelime[20];
   printf("Bir kelime girin: ");
   scanf("%s", kelime);

   int uzunluk = strlen(kelime);
   char son_harf = kelime[uzunluk - 1];

   if (son_harf == 's' || son_harf == 'x' || son_harf == 'z' || (son_harf == 'h' && kelime[uzunluk - 2] == 's')) {
      printf("%ses\n", kelime);
   } else if (son_harf == 'y') {
      printf("%sies\n", kelime);
   } else {
      printf("%ss\n", kelime);
   }

   return 0;
}
