#include <stdio.h>

int main()
{
    int batons, tir1, i, tir2;

    do{
        printf("Saisir le nombre du batons: "); scanf("%d", &batons);
    }while(batons<=0);

    for(i=0; i<batons; i++){
            printf("I");
        }

    while(batons>=0){
        do{
        printf("\nJoueur 1, entrez le nombre de batons à tirer: "); scanf("%d", &tir1);
        }while((tir1<=0)||(tir1>3));
        batons = batons - tir1;
        for(i=0; i<batons; i++){
            printf("I");
        }
        if(batons<=0){
            printf("\nJoueur 1 a perdu!");
            break;
        }
        do{
        printf("\nJoueur 2, entrez le nombre de batons à tirer: "); scanf("%d", &tir2);
        }while((tir2<=0)||(tir2>3));
        batons = batons - tir2;
        for(i=0; i<batons; i++){
            printf("I");
        }
        if(batons<=0){
            printf("\nJoueur 2 a perdu!");
            break;
        }
    }

    return 0;
}
