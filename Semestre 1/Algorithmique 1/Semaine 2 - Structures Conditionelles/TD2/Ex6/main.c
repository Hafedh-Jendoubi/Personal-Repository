#include <stdio.h>

int main()
{
   int a, b, c, delta;
   float x1, x2;

   printf("Pour resoudre une equation de deuxieme degree, il fault taper a, b et c or 'ax^2+bx+c=0'\n\n");
   printf("Taper a: "); scanf("%d", &a);
   printf("Taper b: "); scanf("%d", &b);
   printf("Taper c: "); scanf("%d", &c);
   delta = (b*b)-(4*a*c);
   if(delta>0){
        x1 = (-b-sqrt(delta))/(2*a);
        x2 = (-b+sqrt(delta))/(2*a);
        printf("Les solutions sont:\nx1 = %.2f\nx2 = %.2f\n", x1, x2);
   }
   else if(delta==0){
        x1 = (-b)/(2*a);
        printf("La solution est:\nx1 = x2 = %.2f\n", x1);
   }else{
        printf("Votre equation n'admet pas de solution!");
   }
   return 0;
}
