#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
char identifiant[30];
char nom[20];
char prenom[20];
float moyenne;
}etudiant;

int main()
{
    etudiant E[35];
    int i, n, choix, k, j=0;
    char t[10];
    bool trouve;

    do{
        printf("Taper le nombre d'eleves dans cette classe: "); scanf("%d", &n);
    }while((n<0)||(n>35));

    printf("\n~~~~~~~~~~~~~~Menu: ~~~~~~~~~~~~~~\n");
    printf("0- Quitter\n");
    printf("1- Remplir un tableau d'etudiants\n");
    printf("2- Afficher la liste des etudiants de la classe\n");
    printf("3- Rechercher un etudiant identifie par un identifiant saisie au clavier et afficher le nom et le prenom de l'etudiant s'il existe\n");
    printf("4- Supprimer un etudiant identifie par un identifiant saisi au clavier\n");
    printf("5- Afficher la moyenne de la classe");

    do{
        do{
            printf("\n\nTaper votre choix: "); scanf("%d", &choix);
        }while((choix<0)||(choix>5));

        switch(choix){
        case 0 :
            //Quit
            printf("Au revoir!\n");
            break;

        case 1 :
            //Remplisser
            for(i=0; i<n; i++){
                printf("\nTaper l'identifiant de l'eleve n%d: ", i+1); scanf("%s", E[i].identifiant);
                printf("Taper Le nom de l'eleve n%d: ", i+1); scanf("%s", E[i].nom);
                printf("Taper le prenom de l'eleve n%d: ", i+1); scanf("%s", E[i].prenom);
                do{
                    printf("Taper la moyenne de l'eleve n%d: ", i+1); scanf("%f", &E[i].moyenne);
                }while((E[i].moyenne<0)||(E[i].moyenne>20));
            }
            break;

        case 2 :
            //Afficher
            for(i=0; i<n-j; i++)
                printf("Identifiant: %s\t|\tNom: %s\t|\tPrenom: %s\t|\tMoyenne: %.2f\n", E[i].identifiant, E[i].nom, E[i].prenom, E[i].moyenne);
            break;

        case 3 :
            //Chercher
            printf("Taper l'identifiant: "); scanf("%s", t);
            k = 0; trouve = false;
            while((k<n)&&(trouve==false)){
                if(strcmp(E[k].identifiant, t)==0){
                    trouve = true;
                }else{
                    k++;
                }
            }
            if(trouve == true){
                printf("L'etudiant ayant l'identifiant %s est: %s %s\n", t, E[k].nom, E[k].prenom);
            }else{
                printf("L'etudiant ayant l'identifiant %s n'existe pas\n", t);
            }
            break;

        case 4 :
            //Suprimmer
            printf("Taper l'identifiant: "); scanf("%s", t);
            k = 0;
            while(k<n){
                if(strcmp(E[k].identifiant, t)==0){
                    for(i=k; i<n; i++){
                        strcpy(E[i+1].identifiant, E[i].identifiant);
                        strcpy(E[i+1].nom, E[i].nom);
                        strcpy(E[i+1].prenom, E[i].prenom);
                        E[i].moyenne = E[i+1].moyenne;
                    }
                    j++;
                    break;
                }
                else{
                    k++;
                }
            }
            break;

        default:
            printf("Invalid choix!");
        }

    }while(choix!=0);

    return 0;
}
