#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu()
{
    printf("~~~~~~~~~~~~ Menu: ~~~~~~~~~~~~\n");
    printf("0- Exit\n");
    printf("1- Taper une chaine ou un caractere\n");
    printf("2- Chercher la position finale d'un caractere dans une chaine\n");
    printf("3- Determiner tous les occurences d'un caractere dans une chaine\n");
    printf("4- Supprimer toutes les occurences d'un caractere dans ine chaine\n");
    printf("5- Calculer le nombre d'occurence dans une chaine\n");
}

int search(char a, char ch[])
{
    int i, pos, trouve;

    trouve = 0;
    for(i=0; i<strlen(ch); i++){
        if(ch[i] == a){
            trouve = 1;
            pos = i+1;
        }
    }
    if(trouve==0)
        pos = -1;

    return pos;
}

void search_all(char a, char ch[])
{
    int i;

    printf("Les positions de %c sont :\n", a);
    for(i=0; i<strlen(ch); i++){
        if(a == ch[i]){
            printf("%d | ", i+1);
        }
    }
}

char delete_all(char a,  char ch[])
{
    int i, k;

    k=0;
    while(k<strlen(ch)){
        if(ch[k] == a){
            for(i=k; i<strlen(ch); i++){
                ch[i] = ch[i+1];
            }
        }else{
            k++;
        }
    }

    return ch;
}

int nb_Occ(char a, char ch[])
{
    int i, k;

    k=0;
    for(i=0; i<strlen(ch); i++){
        if(ch[i] == a){
            k++;
        }
    }

    return k;
}

int main()
{
    char c, ch[20];
    int choix, cho;

    menu();
    do{
        do{
            printf("\nTaper votre choix: "); scanf("%d", &choix);
        }while((choix<0)||(choix>5));
        switch(choix){
            case 0:
                printf("...\n");
                break;

            case 1:
                printf("1- Taper une chaine\n");
                printf("2- Taper une caractere\n");
                printf("Select 1 or 2: "); scanf("%d", &cho);
                switch(cho){
                    case 1: printf("> "); fflush(stdin); gets(ch); break;
                    case 2: printf("> "); fflush(stdin); scanf("%c", &c);
                }
                break;

            case 2:
                printf("La position final de %c est: %d\n", c, search(c, ch));
                break;

            case 3:
                search_all(c, ch);
                break;

            case 4:
                delete_all(c, ch);
                puts(ch); break;

            case 5:
                printf("Le nombre d'occurence de %c est: %d\n", c, nb_Occ(c, ch));
                break;
        }
    }while(choix!=0);

    return 0;
}
