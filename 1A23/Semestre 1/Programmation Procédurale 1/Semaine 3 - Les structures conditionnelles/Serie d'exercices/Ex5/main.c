#include <stdio.h>

int main()
{
    int x, d, u, c, Somme, ope;

    do{
        printf("Taper un entier x entre 100 et 999: "); scanf("%d", &x);
    }while((x<100)||(x>999));

    c = x/100; d = (x%100)/10; u = x%10;

    Somme = c + d + u;

    if(Somme%2==0){
        ope = Somme*Somme;
        printf("%d --> %d+%d+%d=%d paire --> on fait le carre : %d^2 = %d", x, c, d, u, Somme, Somme, ope);
    }else{
        ope = sqrt(Somme);
        printf("%d --> %d+%d+%d=%d impaire --> on fait la racine carre : racine de %d = %d", x, c, d, u, Somme, Somme, ope);
    }

    return 0;
}
