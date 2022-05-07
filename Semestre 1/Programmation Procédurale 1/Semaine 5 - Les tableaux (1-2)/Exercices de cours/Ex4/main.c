#include <stdio.h>

int main()
{
    int i, j, x, k, choix, lignes, colones, M[50][50];

    do{
    printf("Taper le nombre de lignes de cette matrice: "); scanf("%d", &lignes);
    }while(lignes<=0);
    do{
        printf("Taper le nombre de colones de cette matrice: "); scanf("%d", &colones);
    }while(colones<=0);

    printf("~~~~~~~~~~~~~~~~~~ Menu: ~~~~~~~~~~~~~~~~~~\n");
    printf("0) Exit\n");
    printf("1) Remplir une matrice d'entiers et de l'afficher\n");
    printf("2) Cherchez le nombre d'occurences d'un entier saisi au clavier\n");
    printf("3) Chercher un entier donne par l'utilisateur\n");

    do{
        do{
            printf("\n\nTaper votre choix: "); scanf("%d", &choix);
        }while((choix<0)||(choix>3));

        switch(choix){
    case 0:
        printf("Au revoir!\n");
        break;

    case 1:
        for(i=0; i<lignes; i++){
            for(j=0; j<colones; j++){
                printf("Remplissez M[%d][%d] = ", i+1, j+1); scanf("%d", &M[i][j]);
            }
            printf("\n");
        }
        for(i=0; i<lignes; i++){
            for(j=0; j<colones; j++){
                printf("%d | ", M[i][j]);
            }
            printf("\n");
        }
        break;

    case 2:
        printf("Taper le nombre: "); scanf("%d", &x);
        k = 0;
        for(i=0; i<lignes; i++){
            for(j=0; j<colones; j++){
                if(M[i][j]==x)
                    k = k + 1;
            }
        }
        printf("Le nombre d'occurence de %d est %d\n", x, k);
        break;

    case 3:
        printf("Taper le nombre: "); scanf("%d", &x);
        for(i=0; i<lignes; i++){
            for(j=0; j<colones; j++){
                if(M[i][j]==x){
                    printf("Le nombre %d existe dans la ligne %d et colone %d\n", x, i+1, j+1);
                }
            }
        }

    default:
        printf("Invalid Choix!");
    }

    }while(choix!=0);

    return 0;
}
