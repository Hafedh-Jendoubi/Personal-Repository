#include <stdio.h>

int main()
{
    int choix, mj, i, k, nmin, nmax;
    float T[15], H[15], max, min, moyt, moyh, sommh, moy, p, sommp, s;
    char reponse, reponse1;

    //Saisi des données:
    do{
    printf("Specifier le nombre de mesures journalieres (maximum 15): "); scanf("%d", &mj);
    }while((mj<=0)||(mj>15));

    for(i=0; i<mj; i++){
        printf("Saisir les donnees de Temperature (reels) pour le capteur n%d: ", i+1); scanf("%f", &T[i]);
        printf("Saisir les donnees de Humidite (reels) pour le capteur n%d: ", i+1); scanf("%f", &H[i]);
    }

    //Menu pour l'utilisateur:
    printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Menu: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("0) Quitter\n");
    printf("1) Afficher les mesures de la temperature\n");
    printf("2) Afficher les mesures de l'Humidite\n");
    printf("3) Modifier la valeur d'une prise\n");
    printf("4) Afficher l'Humidite maximale et minimale et leurs numéros de prise associee\n");
    printf("5) Afficher la moyenne humidite et temperature\n");
    printf("6) Afficher l'ecart type de l'humidite pour detecter les pannes du systeme d'irrigation\n\n");

    do{
        printf("\nTaper votre choix: "); scanf("%d", &choix);

        switch(choix){
        case 1:
            printf("Temperature |");
            for(i=0; i<mj; i++){
                    printf("| %.1f |", T[i]);
                    }
            break;
        case 2:
            printf("Humidite |");
            for(i=0; i<mj; i++){
                    printf("| %.1f |", H[i]);
                    }
            break;
        case 3:
            do{
                printf("Voulez vous changez la Temperature ou l'Humidite (T/H): "); fflush(stdin); scanf("%c", &reponse1);
            }while((reponse1!='T')&&(reponse1!='H'));
            if(reponse1=='T'){
                printf("Saisir le nombre du case vous voulez changez: "); scanf("%d", &k);
                printf("Saisir la nouvelle valeur de la Temperature: "); scanf("%f", &T[k-1]);
            }
            else{
                printf("Saisir le nombre du case vous voulez changez: "); scanf("%d", &k);
                printf("Saisir la nouvelle valeur d'Humidite: "); scanf("%f", &H[k-1]);
            }
            break;
        case 4:
            max = H[0]; min = H[0];
            for(i=0; i<mj; i++){
                if(H[i]>=max){
                    max = H[i];
                    nmax = i+1;
                }
                if(H[i]<=min){
                    min = H[i];
                    nmin = i+1;
                }
            }
            printf("L'humidite maximale = %.1f\n           position = %d\nL'humidite minimale = %.1f\n           position = %d", max, nmax, min, nmin);
            break;
        case 5:
            moyt = 0; moyh = 0;
            for(i=0; i<mj; i++){
                moyt = moyt + T[i];
                moyh = moyh + H[i];
            }
            moyt = moyt/mj; moyh = moyh/mj;
            printf("La moyenne humidite = %.2f\nLa moyenne temperature = %.2f", moyh, moyt);
            break;
        case 6:
            sommh = 0;
            for(i=0; i<mj; i++){
                sommh = sommh + H[i];
            }
            moy = sommh/mj;
            sommp = 0;
            for(i=0; i<mj; i++){
                p = (H[i]-moy)*(H[i]-moy);
                sommp = sommp + p;
            }
            s = sqrt(sommp/mj);
            printf("L'ecart type de l'humidite = %.2f", s);
            break;
        default: printf("Invalid choix..");
        }

    }while(choix!=0);

    return 0;
}
