#include "functions.h"

int main()
{
    int choix, rdv, sansRdv;
    Patient p;
    liste tete = NULL;
    char ch[15] = "patients.txt";

    tete = recupererListePatients(tete, ch);
    menuprincipal();
    do{
        choix = menu();
        switch(choix){
            case 0:
                printf("...\n"); sauvegarderPatients(tete, ch); break;

            case 1:
                Test(tete); break;

            case 2:
                saisirPatient(&p); tete = AjoutPatient(tete, p); break;

            case 3:
                RendezVous(tete, &rdv, &sansRdv); break;

            case 4:
                tete = SupprimePatient(tete); break;

            case 5:
                ConsulterSalleAttente(tete); break;
        }
    }while(choix!=0);

    return 0;
}
