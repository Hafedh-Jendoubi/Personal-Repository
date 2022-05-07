#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nom[20];
    char identifiant[20];
    int type;
}alerte;

typedef struct{
    char login[20];
    char pass[20];
    int role;
}personnel;

void remplissageper(int n, personnel T[])
{
    int i;

    for(i=0; i<n; i++){
        printf("Personnel n%d: \n", i+1);
        printf("Taper votre login: "); fflush(stdin); gets(T[i].login);
        printf("Taper votre password: "); fflush(stdin); gets(T[i].pass);
        printf("Quel est votre role: ([0]Agent - [1]Administrateur) ");
        do{
            scanf("%d", &T[i].role);
        }while((T[i].role!=0)&&(T[i].role!=1));
    }
    system("cls");
}

int authentification(int n, personnel T[])
{
    char typedlogin[20], typedpass[20];
    int i, result=0, trouve, k;

    printf("Login: "); fflush(stdin); gets(typedlogin);
    printf("Password: "); fflush(stdin); gets(typedpass);
    trouve = 0; k = 0;
    while((trouve==0)&&(k<n)){
        if((strcmp(T[k].login, typedlogin)==0)&&(strcmp(T[k].pass, typedpass)==0)&&(T[k].role==0)){
            trouve = 1;
            result = 2;
        }
        else if((strcmp(T[k].login, typedlogin)==0)&&(strcmp(T[k].pass, typedpass)==0)&&(T[k].role==1)){
            trouve = 1;
            result = 1;
        }
        else{
            k++;
        }
    }
    if(trouve==0)
        result = -1;

    return result;
}

void roles(int a)
{
    if(a==1)
        printf("Votre role est: Administrateur\n");
    else if(a==2)
        printf("Votre role est: Agent\n");
    else
        printf("Vous n'existe pas!");
}

void agentmenu()
{
    printf("~~~~~~~~~~ Menu des Agents: ~~~~~~~~~~\n");
    printf("0- Exit.\n");
    printf("1- Ajouter une nouvelle alerte.\n");
    printf("2- Chercher une alerte et retourner sa position si elle existe.\n");
    printf("3- Afficher ou modifier ou supprimer une alerte donnee par son identifiant.\n");
    printf("4- Afficher la liste des alertes.\n");
    printf("5- Deconnection.\n");
}

void adminmenu()
{
    printf("~~~~~~~~~~ Menu des Administrateurs: ~~~~~~~~~~\n");
    printf("0- Exit.\n");
    printf("1- Afficher la liste des alertes.\n");
    printf("2- Afficher le pourcentage des alertes par rapport au nombre total d'alertes.\n");
    printf("3- Deconnection.\n");
}

void affichage(int n , alerte A[])
{
    int i;

    for(i=0; i<n; i++)
         printf("id: %s \nnom de la zone: %s \ntype: %d\n",A[i].identifiant,A[i].nom,A[i].type);
}

void menu(int a, alerte A[])
{
    int cho, k=0, i, trouve, m, pos, choix1, c, cpt;
    char idalr[20], cherche_zone[20];

    if(a==2){
        system("cls");
        agentmenu();
        do{
            do{
                printf("\nTaper votre choix: "); scanf("%d", &cho);
            }while((cho<0)&&(cho>5));

            switch(cho){
                case 0:
                //Exit:
                    printf("...");
                    break;

                case 1:
                //Ajout d'une alerte:
                    printf("Taper le nom de l'alerte: "); fflush(stdin); gets(A[k].nom);
                    printf("Taper l'identifiant de l'alerte: "); fflush(stdin); gets(A[k].identifiant);
                    do{
                        printf("Taper le type de l'alrete: ([0]Non Critique - [1]Critique)"); scanf("%d", &A[k].type);
                    }while((A[k].type!=0)&&(A[k].type!=1));
                    printf("NOUVELLE ALERTE AJOUTEE!\n");
                    printf("Nom: %s\tIdentifiant: %s\tType: %d\n", A[k].nom, A[k].identifiant, A[k].type);
                    k++;
                    break;

                case 2:
                //Chercher une alerte:
                    printf("Taper l'identifiant de l'alerte que vous etes en train de chercher: "); fflush(stdin); gets(idalr);
                    trouve = 0; m = 0;
                    while((trouve==0)&&(m<k)){
                        if(strcmp(idalr, A[m].identifiant)==0){
                            trouve = 1;
                            printf("L'alerte %s existe dans la position %d.\n", idalr, m);
                        }else{
                            m++;
                        }
                    }
                    if(trouve==0)
                        printf("L'alerte %s n'existe pas.\n", idalr);
                    break;

                case 3:
                //Afficher, Modifier ou Supprimer une alerte:
                    printf("Taper l'identifiant de l'alerte que vous devez Afficher, Modifer ou Supprimer: "); fflush(stdin); gets(idalr);
                    trouve = 0; m = 0;
                    while((trouve==0)&&(m<k)){
                        if(strcmp(idalr, A[m].identifiant)==0){
                            trouve = 1;
                            printf("Alerte:\n");
                            printf("Nom: %s\tIdentifiant: %s\tType: %d\n", A[m].nom, A[m].identifiant, A[m].type);
                            do{
                                printf("Taper votre choix: ([1] Modifer - [2] Supprimer)"); scanf("%d", &choix1);
                            }while((choix1!=1)&&(choix1!=2));
                            if(choix1==1){
                                printf("1- Changer le nom.\n2- Changer l'identifiant.\n3- Changer le type.\n"); scanf("%d", &c);
                                switch(c){
                                case 1: printf("Taper le nouveau nom: "); fflush(stdin); gets(A[m].nom); break;
                                case 2: printf("Taper le nouveau identifiant: "); fflush(stdin); gets(A[m].identifiant); break;
                                case 3: printf("Taper le nouveau type: ([0]Non Critique - [1]Critique)"); scanf("%d", A[m].type);
                                }
                            }else{
                                for(i=m; i<k; i++){
                                    strcpy(A[i].nom, A[i+1].nom);
                                    strcpy(A[i].identifiant, A[i+1].identifiant);
                                    A[i].type = A[i+1].type;
                                }
                                k--;
                            }
                        }
                        else{
                            m++;
                        }
                    }
                    if(trouve==0)
                        printf("La zone d'identifiant %s n'existe pas.\n", idalr);
                    break;

                case 4:
                //Affichage des alertes:
                    printf("~~~~~~~~~~ Alertes: ~~~~~~~~~~\n");
                    affichage(k, A);
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    break;

                case 5:
                //Deconnection:
                    system("cls");
                    authentification(k, A);
                    agentmenu();
                    break;
            }
        }while(cho!=0);
    }else if(a==1){
        system("cls");
        adminmenu();
        do{
            do{
                printf("\nTaper votre choix: "); scanf("%d", &cho);
            }while((cho<0)&&(cho>3));

            switch(cho){
                case 0:
                //Exit:
                    printf("...\n");
                    break;

                case 1:
                //Affichage des alertes:
                    printf("~~~~~~~~~~ Alertes: ~~~~~~~~~~\n");
                    affichage(k, A);                                        //**Les alertes enregistré depuis un agent, on ne peut pas les voir ici!!**
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    break;

                case 2:
                //Pour une zone donnée, afficher le pourcentage des alertes par rapport au nombre total d’alertes:
                    printf("Donner une zone\n") ;fflush(stdin); gets(cherche_zone);
                    for(i=0; i<k; i++){
                        if(strcmp(cherche_zone, A[i].nom)==0)              //**Si Alertes sera fixé, cette fonction fonctionnera!**
                            cpt++;
                    }
                    printf("Le pourcentage d'alerte de cette zone par rapport aux autres est: %f", cpt);
                    break;

                case 3:
                //Deconnection:
                    system("cls");
                    authentification(k, A);
                    adminmenu();
                    break;
            }
        }while(cho!=0);
    }else{
        printf("ERROR\n");
    }
}

int main()
{
    personnel T[20];
    alerte A[20];
    int n, ch;

    printf("Donner le nombre de personnel: "); scanf("%d", &n);
    remplissageper(n, T);
    printf("~~~~~~~~ Menu: ~~~~~~~~~~\n");
    printf("0- Exit\n");
    printf("1- Afficher le role de l'utilisateur\n");
    printf("2- Afficher le menu principale\n");
    do{
        do{
            printf("\nTaper votre choix: "); scanf("%d", &ch);
        }while((ch<0)&&(ch>2));
        switch(ch){
            case 0: printf("..."); break;
            case 1: roles(authentification(n, T)); break;
            case 2: menu((authentification(n, T)), A); break;
        }
    }while(ch!=0);

    return 0;
}
