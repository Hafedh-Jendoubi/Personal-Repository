#include <stdio.h>
#include <string.h>

typedef struct{
int j;
int m;
int a;
}date;

typedef struct{
char destination[30];
date d;
}voyage;

typedef struct{
int identifiant;
char nom[20];
char prenom[20];
int n_voyages;
voyage e_voyage[50];
}client;

int main()
{
    int n, choix, i, j, max, k, a, trouve, compteur, Max, permute, m_test, m_dem, s, T1[100];
    client T[100];
    char des[30], desR[30], tt="";
    voyage kes;

    printf("~~~~~~~~~~~~~~Menu: ~~~~~~~~~~~~~~\n");
    printf("0- Quit\n");
    printf("1- Remplir un tableau de clients.\n");
    printf("2- Afficher le tableau des clients.\n");
    printf("3- Trier les voyages des clients selon l'ordre decroissant de la date.\n");
    printf("4- Afficher le voyageur le plus fidele.\n");
    printf("5- Afficher la destination la plus demandee pour un voyageur sachant son identifiant.\n");
    printf("6- Afficher le mois de l'annee avec le plus grand nombre de reservations.\n");

    do{
        do{
            printf("\nTaper votre choix: "); scanf("%d", &choix);
        }while((choix<0)||(choix>6));

        switch(choix){
            case 0:
                //Exit:
                printf("Au revoir!\n");
                break;

            case 1:
                //Remplissage:
                do{
                    printf("Taper le nombre de clients: "); scanf("%d", &n);
                }while((n<0)||(n>100));
                for(i=0; i<n; i++){
                    printf("\nTaper l'identifiant du client n%d: ", i+1); scanf("%d", &T[i].identifiant);
                    printf("Taper le nom du client n%d: ", i+1); scanf("%s", T[i].nom);
                    printf("Taper le prenom du client n%d: ", i+1); scanf("%s", T[i].prenom);
                    printf("Taper le nombre de voyage du client n%d: ", i+1); scanf("%d", &T[i].n_voyages);
                    for(j=0; j<T[i].n_voyages; j++){
                        printf("Taper la destination du voyage n%d: ", j+1); fflush(stdin); gets(T[i].e_voyage[j].destination);
                        printf("Taper le jour du voyage n%d: ", j+1); scanf("%d", &T[i].e_voyage[j].d.j);
                        printf("Taper le mois du voyage n%d: ", j+1); scanf("%d", &T[i].e_voyage[j].d.m);
                        printf("Taper l'annee du voyage n%d: ", j+1); scanf("%d", &T[i].e_voyage[j].d.a);
                    }
                }
                break;

            case 2:
                //Affichage:
                printf("________Liste des Clients:________\n");
                for(i=0; i<n; i++){
                    printf("\nClient n%d: \n", i+1);
                    printf("Identifiant: %d\n", T[i].identifiant);
                    printf("Nom: %s\n", T[i].nom);
                    printf("Prenom: %s\n", T[i].prenom);
                    printf("Nombre de voyages: %d\n", T[i].n_voyages);
                    printf("Ensemble de voyages:\n");
                    for(j=0; j<T[i].n_voyages; j++){
                        printf("\tDestination du voyage n%d: %s\n", j+1, T[i].e_voyage[j].destination);
                        printf("\tDate de voyage: %d/%d/%d\n", T[i].e_voyage[j].d.j, T[i].e_voyage[j].d.m, T[i].e_voyage[j].d.a);
                    }
                }
                break;

            case 3:
                //Tri les voyages des clients:
                for(i=0;i<n;i++){
                    do{
                        permute=0;
                        for(j=0;j<T[i].n_voyages;j++){
                            if((T[i].e_voyage[j].d.a<T[i].e_voyage[j+1].d.a)||((T[i].e_voyage[j].d.a==T[i].e_voyage[j+1].d.a)&&(T[i].e_voyage[j].d.m<T[i].e_voyage[j+1].d.m)) ||
                            (((T[i].e_voyage[j].d.a==T[i].e_voyage[j+1].d.a)&&(T[i].e_voyage[j].d.m==T[i].e_voyage[j+1].d.m))&&((T[i].e_voyage[j].d.j<T[i].e_voyage[j+1].d.j)))){
                                permute=1;
                                kes=T[i].e_voyage[j];
                                T[i].e_voyage[j]=T[i].e_voyage[j+1];
                                T[i].e_voyage[j+1]=kes;
                            }
                        }
                    }while(permute==1);
                }
                break;

            case 4:
                //Affichage du voyageur plus fidèle:
                max = T[0].n_voyages; k = 0;
                for(i=1; i<n; i++){
                    if(T[i].n_voyages>max)
                        k = i;
                        max=T[i].n_voyages;
                }
                printf("Le voyageur le plus fidele est: %s %s d'identifiant: %d\n", T[k].nom, T[k].prenom, T[k].identifiant);
                break;

            case 5:
                //Affichage du destination plus demandé:
                printf("Taper l'identifiant du client: "); scanf("%d", &a);
                trouve = 0; k = 0;
                while((trouve==0)&&(k<n)){
                    if(T[k].identifiant==a){
                        trouve = 1;
                        if(T[k].n_voyages==1){
                            printf("La destination plus demande est: %s\n", T[k].e_voyage[1].destination);
                        }else{
                            Max = 0;
                            for(i=0; i<T[k].n_voyages; i++){
                                compteur = 0; strcpy(des, T[k].e_voyage[i].destination);
                                for(j=0; j<T[k].n_voyages; j++){
                                    if(strcmp(des, T[k].e_voyage[j].destination)==0){
                                        compteur = compteur + 1;
                                    }
                                }
                                if(compteur>Max){
                                        Max = compteur;
                                        strcpy(desR, des);
                                    }
                            }
                            printf("La destination plus demande est: %s\n", desR);
                        }
                    }
                    else{
                        k++;
                    }
                }
                if(trouve==0)
                    printf("Vérifier votre numero d'identifiant! (%d n'existe pas)\n", a);
                break;

            case 6:
                //Affichage du mois d'année avec le plus grand nombre de réservations:
                for(k=0; k<n; k++){
                    T1[k]=0;
                }
                for(k=0; k<n; k++){
                    for(i=0; i<n; i++){
                        for(j=0; j<T[i].n_voyages; j++){
                            if(T[i].e_voyage[j].d.m==k)                       //Cette solution ne travaille pas.. Domage!
                                T1[k]++;
                        }
                    }
                }
                s=0; Max=0; Max=T1[0];
                for(k=0; k<n; k++){
                    if(T1[k]>Max){
                        Max=T1[k];
                        s=k;
                    }
                }
                printf("le mois qui a connu le plus de reservation est %d de %d reservations\n", s+1, Max);
                break;
        }
    }while(choix!=0);

    return 0;
}
