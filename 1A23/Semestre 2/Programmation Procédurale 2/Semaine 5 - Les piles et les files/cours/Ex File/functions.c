#include "functions.h"

void menuprincipal()
{
    printf("~~~~~~~~~ Menu: ~~~~~~~~~~~\n");
    printf("1: Test\n");
    printf("2: Ajouter Client\n");
    printf("3: Servir Client\n");
    printf("4: Calculer recette totale\n");
    printf("0: Exit\n");
}

int menu()
{
    int choix;

    do{
        printf("\nTaper votre choix: "); scanf("%d", &choix);
    }while((choix<0)||(choix>4));

    return choix;
}

file initFile()
{
    file f;

    f.tete = NULL;
    f.queu = NULL;

    return f;
}

client saisir_client()
{
    client c;

    printf("Prix total de ses achats: "); scanf("%d", &c.prix_tot);
    printf("Mode de paiment: ([1] especes - [2] Carte Bancaire - [3] cheque) ");
    do{
        scanf("%d", &c.mode_payment);
    }while((c.mode_payment<1)||(c.mode_payment>3));

    return c;
}

file ajouter_client(file f)
{
    client c;
    cellule *nouv;

    c = saisir_client();
    nouv = (cellule*) malloc(sizeof(cellule));
    nouv->c = c;
    nouv->suivant = NULL;
    if((f.tete == NULL)&&(f.queu == NULL)){ /**File Empty**/
        f.tete = nouv;
        f.queu = nouv;
    }else{ /**File Not Empty**/
        f.queu->suivant = nouv;
        f.queu = nouv;
    }

    return f;
}

file servir_client(file f, int *a)
{
    cellule *suppr=f.tete;

    if(suppr == NULL)
        printf("Pas de client a servir!\n");
    else{
        *a = *a + f.tete->c.mode_payment;
        f.tete = f.tete->suivant;
        free(suppr);
        printf("Client servit!\n");
        if(f.tete == NULL) /** Last client case **/
            f.queu = NULL;
    }

    return f;
}

void test(file f)
{
    cellule *parc = f.tete;

    while(parc!=NULL){
        printf("%d\n", parc->c.mode_payment);
        parc = parc->suivant;
    }
}
