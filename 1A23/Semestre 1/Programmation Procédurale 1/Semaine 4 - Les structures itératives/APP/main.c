#include <stdio.h>

int main()
{
    srand(time(NULL));
    int reponse, x, mystere, tentative;
    char c_mystere = "abcdefghijklmnopqrstuvwxyz"[rand()%26];
    char c;

    printf("------------Bienvenu au jeu du mystere------------\n");
    printf("------------Veuillez choisir le niveau------------\n");
    printf("0: Quitter\n");
    printf("1: Niveau Facile\n");
    printf("2: Niveau moyen\n");
    printf("3: Niveau Difficile\n\n");

    do{
        printf("Taper votre choix: "); scanf("%d", &reponse);

        switch(reponse){
            case 0: printf("Merci d'avoir joue a ce jeu!\n\n"); break;
            case 1: mystere = rand()%100;
                    tentative = 15;
                    printf("Niveau Facile : Le mystere est un nombre entre 0 et 100\n");
                    printf("Donner le mystere entre 0 et 100\n"); scanf("%d", &x);
                    tentative = tentative - 1;
                    while(tentative!=0){
                        if(x<mystere){
                            printf("C'est moins, Il vous reste %d tentatives\n", tentative);
                            printf("Donner le mystere entre 0 et 100\n"); scanf("%d", &x);
                            tentative = tentative - 1;
                        }
                        else if(x>mystere){
                            printf("C'est plus, Il vous reste %d tentatives\n", tentative);
                            printf("Donner le mystere entre 0 et 100\n"); scanf("%d", &x);
                            tentative = tentative - 1;
                        }else{
                            printf("Bravo ! Vous avez gangne au bout de %d tentatives\n\n", 15-tentative); break;
                        }
                    }
                    if(tentative==0)
                        printf("Vous avez perdu!\nLe nombre mystere est %d\n\n", mystere);
                    break;
            case 2: mystere = rand()%10000;
                    tentative = 10;
                    printf("Niveau Moyen : Le mystere est un nombre entre 0 et 10000\n");
                    printf("Donner le mystere entre 0 et 10000\n"); scanf("%d", &x);
                    tentative = tentative - 1;
                    while(tentative!=0){
                        if(x<mystere){
                            printf("C'est moins, Il vous reste %d tentatives\n", tentative);
                            printf("Donner le mystere entre 0 et 10000\n"); scanf("%d", &x);
                            tentative = tentative - 1;
                        }
                        else if(x>mystere){
                            printf("C'est plus, Il vous reste %d tentatives\n", tentative);
                            printf("Donner le mystere entre 0 et 10000\n"); scanf("%d", &x);
                            tentative = tentative - 1;
                        }else{
                            printf("Bravo ! Vous avez gangne au bout de %d tentatives\n\n", 10-tentative); break;
                        }
                    }
                    if(tentative==0)
                        printf("Vous avez perdu!\nLe nombre mystere est %d\n\n", mystere);
                        break;
            case 3: mystere = (rand()%90)+10;
                    tentative = 10;
                    printf("Donner le caractere mystere entre a et z\n"); fflush(stdin); scanf("%c", &c);
                    printf("Donner le nombre mystere entre 10 et 100\n"); scanf("%d", &x);
                    tentative = tentative - 1;
                    while(tentative!=0){
                        if((x<mystere)&&(c<c_mystere))
                            printf("C'est plus pour le nombre\tLe caractere est avant\n");
                        else if((x<mystere)&&(c>c_mystere))
                            printf("C'est plus pour le nombre\tLe caractere est apres\n");
                        else if((x<mystere)&&(c==c_mystere))
                            printf("C'est plus pour le nombre\tLe caractere est correct *%c\n", c_mystere);
                        else if((x==mystere)&&(c>c_mystere))
                            printf("Le nombre est correct: *%d\tLe caractere est apres\n", mystere);
                        else if((x==mystere)&&(c<c_mystere))
                            printf("Le nombre est correct: *%d\tLe caractere est avant\n", mystere);
                        else if((x>mystere)&&(c<c_mystere))
                            printf("C'est moins pour le nombre\tLe caractere est avant\n");
                        else if((x>mystere)&&(c==c_mystere))
                            printf("C'est moins pour le nombre\tLe Caractere est correct *%c\n", c_mystere);
                        else if((x>mystere)&&(c>c_mystere))
                            printf("C'est moins pour le nombre\tLe caractere est apres\n");
                        else{
                            printf("Bravo ! vouz avez gagne au bout de %d tentatives\n\n", 10-tentative);
                            break;
                        }
                    printf("Il vous reste %d tentatives\n", 10-tentative);
                    printf("Donner le caractere mystere entre a et z\n"); fflush(stdin); scanf("%c", &c);
                    printf("Donner le nombre mystere entre 10 et 100\n"); scanf("%d", &x);
                    tentative = tentative - 1;
                    }
                    if(tentative==0)
                        printf("Vouz avez perdu!\nLe nombre mystere est: %d\tLe caractere mystere est: %c\n\n", mystere, c_mystere);
                    break;
            default: printf("Invalid choix!\n");
            }

        }while(reponse!=0);

    return 0;
}
