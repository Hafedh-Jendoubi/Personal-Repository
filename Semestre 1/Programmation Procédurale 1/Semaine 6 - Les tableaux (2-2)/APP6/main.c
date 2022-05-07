#include <stdio.h>

int main()
{
    int i, j, k, n, fin, debut, trouve, milieu, rayons, min, pajour, prodtot, nrayon, produits, longprixtot, tampon, choix, tot[50], prix[50], prixtot[50], M[50][50];

    //Nombre de rayons & produits:
    do{
    printf("Taper le nombre de rayons: "); scanf("%d", &rayons);
    }while((rayons<=0)||(rayons>50));
    do{
    printf("Taper le nombre de type de produits: "); scanf("%d", &produits);
    }while((produits<=0)||(produits>50));

    //Menu:
    printf("\n~~~~~~~~~~~~~~~~~~~ Menu: ~~~~~~~~~~~~~~~~~~~\n");
    printf("0) Quitter\n");
    printf("1) Saisir la quantite presente de chaque produit dans les differents rayon de l'entrepot\n");
    printf("2) Mettre a jour la quantite d'un produit donne dans un rayon donne\n");
    printf("3) Calculer et afficher la quantite totale de chaque produit\n");
    printf("4) Saisir le prix unitaire de chaque produit\n");
    printf("5) Calculer le prix total des produits\n");
    printf("6) Supprimer du tableau des prix totaux toutes les cases ayant un prix égale à zéro\n");
    printf("7) Afficher le matrice\n"); //Seulement pour tester chaque fonction

    //Les fonctions:
    do{
        printf("\nTaper votre choix: "); scanf("%d", &choix);
        switch(choix){
        case 0 :
            printf("Passant au tri!\n\n");
            break;

        case 1 :
            for(i=0; i<produits; i++){
                for(j=0; j<rayons; j++){
                    printf("Taper la quantite du produit n%d dans le rayon n%d: ", i+1, j+1);
                    scanf("%d", &M[j][i]);
                }
            }
            break;

        case 2 :
            do{
            printf("Taper le type de produit: "); scanf("%d", &pajour);
            }while((pajour<=0)||(pajour>produits));
            do{
            printf("Taper le rayon: "); scanf("%d", &nrayon);
            }while((nrayon<=0)||(nrayon>rayons));
            printf("Taper la nouvelle valeur: "); scanf("%d", &M[nrayon-1][pajour-1]);
            break;

        case 3 :
            for(i=0; i<produits; i++){
                prodtot = 0;
                for(j=0; j<rayons; j++){
                    prodtot = prodtot + M[j][i];
                }
                printf("La quantite totale du produit n%d est: %d\n", i+1, prodtot);
                tot[i] = prodtot;
            }
            break;

        case 4 :
            for(i=0; i<produits; i++){
            printf("Saisir le prix unitaire de produit n%d: ", i+1);
            scanf("%d", &prix[i]);
            }
            break;

        case 5 :
            for(i=0; i<produits; i++)
                prixtot[i] = tot[i] * prix[i];
            printf("Stockage des valeurs terminee!\n");
            for(i=0; i<produits; i++)
                printf("%d | ", prixtot[i]);
            break;

        case 6 :
            k=0;
            for(i=0; i<produits; i++){
                if(prixtot[i]==0){
                    k=k+1;
                    for(j=i; j<produits; j++){
                        prixtot[j]=prixtot[j+1];
                    }
                }
            }
            longprixtot = produits - k;
            for(i=0; i<longprixtot; i++)
                printf("%d | ", prixtot[i]);
            break;

        //Cette fonction pour tester!
        case 7 :
            for (i=0; i<rayons; i++){
                for (j=0; j<produits; j++){
                    printf("%d | ", M[i][j]);
                }
                printf("\n");
            }
            break;

        default :
            printf("Invalid choix!\n");
        }
    }while(choix!=0);

    //Tri par selection:
    for (i=0;i<longprixtot-1;i++){
        min=i ;
        for (j=i+1;j<longprixtot;j++){
            if (prixtot[j]<prixtot[min])
                min=j;
        }
        tampon=prixtot[i];
        prixtot[i]=prixtot[min];
        prixtot[min]=tampon;
    }

    //Affichage
    for(i=0; i<longprixtot; i++)
        printf("%d | ", prixtot[i]);

    //Recherche dichotomique:
    printf("\n\nTaper une valeur: "); scanf("%d", &n);
    trouve = -1; debut = 0 ; fin = longprixtot-1 ;
    while ((trouve == -1)&&(debut <= fin )){
        milieu = (debut + fin)/2;
        if (prixtot[milieu] > n )
            fin=milieu - 1;
        else if (prixtot[milieu] < n)
            debut = milieu + 1;
        else
            trouve=1;
    }
    if(trouve == 1)
        printf("%d existe dans le tableau\n", n);
    else
        printf("%d n'existe pas dans le tableau\n", n);

    return 0;
}
