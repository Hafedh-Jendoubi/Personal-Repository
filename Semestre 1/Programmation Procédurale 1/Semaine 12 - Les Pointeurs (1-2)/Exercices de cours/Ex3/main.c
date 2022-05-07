#include <stdio.h>
#include <stdlib.h>

void Hafedh_Union(int E1[], int E2[], int n1, int n2)
{
    int i;

    printf("L'union des ensembles E1 et E2 est: \n");
    for(i=0; i<n1; i++)
        printf("%d | ", E1[i]);
    for(i=0; i<n2; i++)
        printf("%d | ", E2[i]);
}

void Hafedh_Intersection(int E1[], int E2[], int n1, int n2)
{
    int i, j;

    printf("L'intersection des ensembles E1 est E2 est:\n");
    for(i=0; i<n1; i++){
        for(j=0; j<n2; j++){
            if(E1[i]==E2[j])
                printf("%d | ", E1[i]);
        }
    }
}

void Hafedh_Fusion(int E1[], int E2[], int n1, int n2)
{
    printf("J'ai aucune idee c'est quoi la Fusion! Desolee\n");
}

int main()
{
    int E1[50], E2[50], n1, n2, i, ch;

    printf("Taper le nombre d'elements de E1: "); scanf("%d", &n1);
    printf("Taper le nombre d'elements de E2: "); scanf("%d", &n2);
    for(i=0; i<n1; i++){
        printf("E1[%d] = ", i+1); scanf("%d", &E1[i]);
    }
    for(i=0; i<n2; i++){
        printf("E2[%d] = ", i+1); scanf("%d", &E2[i]);
    }
    system("cls");

    printf("~~~~~~~~ Menu: ~~~~~~~~\n");
    printf("0- Exit\n");
    printf("1- Determnier l'union\n");
    printf("2- Determiner l'intersection\n");
    printf("3- Determiner la fusion\n");

    do{
        do{
            printf("\nTaper votre choix: "); scanf("%d", &ch);
        }while((ch<0)||(ch>3));

        switch(ch){
            case 0:
                printf("...\n"); break;

            case 1:
                Hafedh_Union(E1, E2, n1, n2); break;

            case 2:
                Hafedh_Intersection(E1, E2, n1, n2); break;

            case 3:
                Hafedh_Fusion(E1, E2, n1, n2); break;
        }
    }while(ch!=0);

    return 0;
}
