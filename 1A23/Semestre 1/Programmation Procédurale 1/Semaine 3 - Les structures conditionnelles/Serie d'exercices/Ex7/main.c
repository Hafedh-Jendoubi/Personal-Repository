#include <stdio.h>

int main()
{
    int j, m, a, r;
    char mois[10];

    printf("jour? "); scanf("%d", &j);
    printf("mois? "); scanf("%d", &m);
    printf("annee? "); scanf("%d", &a);

    if((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12))
        r = 31;
    else if((m==4)||(m==6)||(m==9)||(m==11))
        r = 30;
    else if((m==2)&&(a%4==0))
        r = 29;
    else
        r = 28;

    switch(m)
    {
    case 1: mois[9] = "Janvier"; break;
    case 2: mois[9] = "Fevrier"; break;
    case 3: mois[9] = "Mars"; break;
    case 4: mois[9] = "Avril"; break;
    case 5: mois[9] = "May"; break;
    case 6: mois[9] = "Juin"; break;
    case 7: mois[9] = "Juillet"; break;
    case 8: mois[9] = "Aout"; break;
    case 9: mois[9] = "Septembre"; break;
    case 10: mois[9] = "Octobre"; break;
    case 11: mois[9] = "Novembre"; break;
    case 12: mois[9] = "Decembre"; break;
    default: printf("Mal reponse!");
    }

    printf("\n%d %s %d\n", j, mois, a);
    printf("il reste %d jours avant la fin du mois.\n", r-j);

    return 0;
}
