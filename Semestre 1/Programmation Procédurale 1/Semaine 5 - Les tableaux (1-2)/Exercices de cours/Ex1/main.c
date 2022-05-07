#include <stdio.h>
#include <stdbool.h>

int main()
{
    int i, n, x, j, k, w=0, o=0, choix, T[50];
    bool test;

    printf("~~~~~~~~~~~~~~~~~~ Menu: ~~~~~~~~~~~~~~~~~~\n");
    printf("0) Exit\n");
    printf("1) Remplir un tableau d’entiers et fficher le tableau\n");
    printf("2) Cherchez le nombre d’occurrences d’un entier\n");
    printf("3) Chercher un entier donner par l'utilisateur\n");
    printf("4) Supprimer la premiere occurence d'un entier donne par l'utilisateur\n");
    printf("5) Supprimer toutes les occurences d'un entier donne par l'utilisateur\n");

    do{
        do{
            printf("\n\nTaper votre choix: "); scanf("%d", &choix);
        }while((choix<0)||(choix>5));
        switch(choix){
        case 0:
            printf("Au revoir!");
            break;

        case 1:
            do{
                printf("Taper la taille du tableau: "); scanf("%d", &n);
            }while((n<=0)||(n>50));
            for(i=0; i<n; i++){
                printf("Remplissez T[%d] = ", i+1); scanf("%d", &T[i]);
            }
            for(i=0; i<n; i++)
                printf("%d | ", T[i]);
            break;

        case 2:
            printf("Taper l'entier: "); scanf("%d", &x);
            k = 0;
            for(i=0; i<n; i++){
                if(x==T[i])
                    k = k + 1;
            }
            printf("L'entier %d se repete %d fois", x, k);
            break;

        case 3:
            printf("Taper l'entier: "); scanf("%d", &x);
            test = false;
            for(i=0; i<n; i++){
                if(T[i]==x){
                    test = true;
                    printf("%d existe dans la case %d\n", x, i+1);
                }
            }
            if(test == false)
                printf("%d n'existe pas dans ce tableau", x);
            break;

        case 4:
            printf("Taper l'entier: "); scanf("%d", &x);
            o = o + 1;
            for(i=0; i<n; i++){
                if(T[i]==x){
                    for(j=i; j<n; j++)
                        T[j]=T[j+1];
                    break;
                }
            }
            for(i=0; i<n-o-w; i++)
                printf("%d | ", T[i]);
            break;

        case 5:
            printf("Taper l'entier: "); scanf("%d", &x);
            for(i=0; i<n; i++){
                if(T[i]==x){
                    w = w + 1;
                    for(j=i; j<n; j++)
                        T[j]=T[j+1];
                }
            }
            for(i=0; i<n-w-o; i++)
                printf("%d | ", T[i]);
            break;

        default:
            printf("Invalid choix!");
        }
    }while(choix!=0);

    return 0;
}
