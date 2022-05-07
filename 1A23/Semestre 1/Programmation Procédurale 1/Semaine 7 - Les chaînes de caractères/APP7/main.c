#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int choix,i,k,j,nb ,n,nbmots,ordre,lg;
     char phrase[30];
     char voyelles[10];
     char phaux[10];
     char phrase1[30][30];
     char tab[30][30];
     char correcte[30];
     char s;

    printf("*************************************\n");
    printf("1: Afficher les mots d'une phrase\n");
    printf("2: Afficher les voyelles et leur nombre dans un mot\n");
    printf("3: Connstruire une phrase\n");
    printf("0: Quitter\n");
    printf("*************************************\n");
    printf("Veuillez saisir un choix!\n");
    scanf("%d", &choix);
    //--------------------------------------------------------------//
    switch(choix)
    {
        case 1:
            printf("donner une phrase a dissocier:\n");
            fflush(stdin);
            gets(phrase);
            nbmots=1;
            for(i=0; i<strlen(phrase) ; i++)
            {
                if(phrase[i]==' ')
                    nbmots++;
            }
            printf("cette phrase est constituee de %d mots\n",nbmots);

            j=0;k=0;i=0;
            for( i=0; i<strlen(phrase) ; i++)
            {
               if (phrase[i]==' ')
               {
                   phrase1[j][k]='\0';
                   j++;
                   k=0;
               }
                else if (phrase[i]!= ' ')
                {
                    phrase1[j][k]=phrase[i];
                        k++;
                }
            }

            puts(phrase1);



        break;

        case 2:
            puts("donner un mot a afficher ses voyelles et leur nombres\n");
            fflush(stdin);
            gets( voyelles );
            printf("liste des voyelles:  ");
            for (k=0 ; k <(strlen(voyelles)) ; k++)
            {
    if ( (voyelles[k]=='a') || (voyelles[k]=='e') || (voyelles[k]=='i') || (voyelles[k]=='o') || (voyelles[k]=='u') || (voyelles[k]=='y') )
       {
             printf(" %s ",voyelles[k]);
                nb++;               }
            }
            printf("\nle nombre des voyelles est: %d",nb);

        break;

        case 3:
            printf("donner le nombre de mot dans votre phrase\n");

            scanf("%d",&n);
            printf("ce message est dedie au prof: veuillez saisir la phrase correctement\n");



            for (i=0 ; i<n ; i++)
            {

                printf("donner un des mots de la phrase\n");
                fflush(stdin);
                gets(tab[i]);
            }
            printf("voici la liste des mots: ");
            for(i=0 ; i<n ; i++)
            {
                printf(" '%s'",tab[i]);
            }
            printf("\n");
            for (i=0 ; i<n ; i++)
            {
                printf("\ndonner l'ordre du mot %s dans la phrase: \n",tab[i]);
                scanf("%d",&ordre);
                strcpy (tab[ordre-1],tab[i]);
            }
              for(i=0 ; i<n ; i++)
            {
                printf(" '%s'",tab[i]);
            }

        break;

        case 0:
        system("EXIT");
        break;
    }


    return 0;
}
