#include "fonctions.h"

int main()
{
    int choix, n;
    char nomFich[30] = "Voyageurs.bin", id[20];
    voyageur v, *tab;

    DisplayLoadingData(nomFich);
    tab = charger_donnees(nomFich, &n);
    MenuDisplay();
    do{
        Choice(&choix);
        switch(choix){
            case 0:
                sauvegarder_donnees(nomFich, tab, n); liberer(tab);
                printf("...\n"); break;

            case 1:
                tester(tab, n); break;

            case 2:
                saisirVoyageur(&v); ajouter(v, tab, &n); break;

            case 3:
                printf("Taper l'identifiant du voyageur a supprimer: "); scanf("%s", id);
                supprimer(tab, id, &n); break;
        }
    }while(choix!=0);
    return 0;
}
