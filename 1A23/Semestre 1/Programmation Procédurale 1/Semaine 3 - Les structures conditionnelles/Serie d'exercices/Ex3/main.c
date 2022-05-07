#include <stdio.h>

int main()
{
    int h1, h2; float montant;

    printf("Pour minuit, il faut taper 24h\n\n");
    printf("Saisir h1: (en h)\n"); scanf("%d", &h1);
    printf("Saisir h2: (en h)\n"); scanf("%d", &h2);

    if(h2<=21){
        montant = (h2-h1)*1.5;
        printf("Le montant que doit payer est: %.2f dinars", montant);
    }else if(h1>=21){
        montant = (h2-h1)*4.5;
        printf("Le montant que doit payer est: %.2f dinars", montant);
    }else{
        montant = (h2-21)*4.5+(21-h1)*1.5;
        printf("Le montant que doit payer est: %.2f dinars", montant);
    }

    return 0;
}
