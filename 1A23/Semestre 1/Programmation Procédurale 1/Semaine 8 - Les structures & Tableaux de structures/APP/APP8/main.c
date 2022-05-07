#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
int CIN;
char nom[20];
char prenom[20];
int facture;
int hotel;
}participant;

int main()
{
    participant p[40];
    int a, choix, c1, facture, c2, j, k=0, c3, i, h;
    bool trouve;

    printf("~~~~~~~~~~~~Menu: ~~~~~~~~~~~~\n");
    printf("0- Quit\n");
    printf("1- Ajouter un participant\n");
    printf("2- Calculer pour un participant le montant de sa facture\n");
    printf("3- Afficher les informations des participants\n");
    printf("4- Supprimer un participant donné par son identifiant\n");

    do{
        do{
            printf("\nTaper votre choix: "); scanf("%d", &choix);
        }while((choix<0)||(choix>5));

        switch(choix){
            case 0:
                printf("Au revoir\n");
                break;

            case 1:
                printf("Tapre votre CIN: "); scanf("%d", &p[k].CIN);
                printf("Taper votre nom: "); scanf("%s", p[k].nom);
                printf("Taper votre prenom: "); scanf("%s", p[k].prenom);
                p[k].facture = 0;
                k++;
                break;

            case 2:
                printf("Taper votre CIN: "); scanf("%d", &a);
                j = 0; trouve = false;
                while((j<k)&&(trouve == false)){
                    if(a == p[j].CIN){
                        facture = 0;
                        printf("Menu propose:\n\t1- dejeuner (15DT)\n\t2- diner (35DT)\n\t3- dejeuner et diner (50DT)\n\t4- Aucun (0DT)\n");
                        do{
                            scanf("%d", &c1);
                        }while((c1<0)||(c1>4));
                        switch(c1){
                            case 1:
                            facture = facture + 15;
                            break;

                            case 2:
                            facture = facture + 35;
                            break;

                            case 3:
                            facture = facture + 50;
                            break;

                            case 4:
                            break;
                            }
                        printf("Hotel propose:\n\t1- Hotel 4 etoiles (75DT)\n\t2- Hotel 5 etoiles (100DT)\n\t3- Aucun (0DT)\n");
                        do{
                            scanf("%d", &c2);
                        }while((c2<0)||(c2>2));
                        switch(c2){
                            case 1:
                            facture = facture + 75;
                            p[j].hotel = 4;
                            break;

                            case 2:
                            facture = facture + 100;
                            p[j].hotel = 5;
                            break;

                            case 3:
                            break;
                        }
                        p[j].facture = facture;
                        printf("Votre facture = %d DT\n", facture);
                        break;
                    }
                    else{
                        j++;
                    }
                }
                break;

            case 3:
                printf("Menu:\n1- Tous les participants sans aucun critere de recherche.\n");
                printf("2- les participants qui ont choisi de reserver un hotel 4 etoiles.\n");
                printf("3- les participants qui ont choisi de reserver un hotel 5 etoiles.\n");
                do{
                    printf("\nTaper votre choix:"); scanf("%d", &c3);
                }while((c3<0)||(c3>3));
                switch(c3){
                    case 1:
                    printf("\n______________________\n");
                    for(i=0; i<k; i++)
                        printf("%s %s\n", p[i].nom, p[i].prenom);
                    break;

                    case 2:
                    printf("\n______________________\n");
                    for(i=0; i<k; i++){
                        if(p[i].hotel == 4)
                            printf("%s %s\n", p[i].nom, p[i].prenom);
                    }
                    break;

                    case 3:
                    printf("\n______________________\n");
                    for(i=0; i<k; i++){
                        if(p[i].hotel == 5)
                            printf("%s %s\n", p[i].nom, p[i].prenom);
                    }
                    break;
                }
                break;

            case 4:
                printf("Taper votre CIN: "); scanf("%d", &a);
                for(i=0; i<k; i++){
                    if(a==p[i].CIN){
                        for (j=i; j<k-1; j++){
                            p[j] = p[j+1];
                        }
                    }
                }
                k--;
                break;

            case 5:
                for(i=0; i<k; i++)
                    printf("%d\t%s\t%s\t%d\n",p[i].CIN, p[i].nom, p[i].prenom, p[i].facture);
                break;

            default:
                printf("Invalid choix\n");
                break;
        }

    }while(choix!=0);

    return 0;
}
