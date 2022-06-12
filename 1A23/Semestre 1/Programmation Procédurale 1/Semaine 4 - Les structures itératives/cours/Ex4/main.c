#include <stdio.h>

int main()
{
   int NInverse = 0, n;

   do{
   printf("Entrez un nombre à inverser\n");
   scanf("%d", &n);
   }while(n<=0);

   while (n != 0)
   {
      NInverse = NInverse * 10;
      NInverse = NInverse + n%10;
      n = n/10;
   }

   printf("Le nombre en sens inverse est = %d\n", NInverse);

   return 0;
}
