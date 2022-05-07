#include <stdio.h>
#include <stdlib.h>

int main()
{
    int annee, taille, poids, inter_chirurgicale, arret_travail, reponse, Aucun, VHA, VHB, VHC, VIH, Budget, niveau;
    float IMC;

    printf("Veulliez entrer vos donnees:\n\tAnnee de naissance: "); scanf("%d", &annee);
    printf("\tTaille: "); scanf("%d", &taille);
    printf("\tPoids: "); scanf("%d", &poids);
    printf("\tantecedents medicaux:\n");
    do{
        printf("\t\tintervention chirurgicale lors des 10 dernieres annees (1 si oui, 0 si non): ");
        scanf("%d", &inter_chirurgicale);
       }while((inter_chirurgicale != 0)&&(inter_chirurgicale != 1));
    do{
        printf("\t\tun arret de travail de plus d'un mois lors des 5 dernieres annees (1 si oui, 0 si non): ");
        scanf("%d", &arret_travail);
       }while((arret_travail != 0)&&(arret_travail != 1));
    do{
        printf("\t\tdepistage de serologies virales (0 si aucun, 1 si VHA[hepatite A], 2 si VHB[hepatite B], 3 si VHC[hepatite C] et 4 si VIH[SIDA]): ");
        scanf("%d", &reponse);
       }while((reponse!=0)&&(reponse!=1)&&(reponse!=2)&&(reponse!=3)&&(reponse!=4));

    switch(reponse)
    {
        case 0: Aucun = 1; break;
        case 1: VHA = 1; break;
        case 2: VHB = 1; break;
        case 3: VHC = 1; break;
        case 4: VIH = 1; break;
    }

    printf("\tBudget maximal: "); scanf("%d", &Budget);
    printf("...\n");

    IMC = poids/((taille/100)*(taille/100));

    if((inter_chirurgicale==1)||(arret_travail==1)||(VHB==1)||(VHC==1)||(VIH==1)){
        printf("Demande d'adhesion rejetee\n");
    }
    else if((2021-annee>50)||(VHA==1)||(IMC<16,5)||(IMC>30)){
        printf("Liste des niveaux de prestations possibles: ");
        if(Budget<1725)
            printf("Votre budget est tres insuffisant!");
        else if((Budget>=1725)&&(Budget<2070))
            printf("Liste des niveaux de prestations possibles:\n\tniveau 1 : maximum de prestations remboursees = 3000 DT par an et par prestataire\n\t\tTarif de cotisation total = 1725 DT.");
        else if((Budget>=1725)&&(Budget<2415))
            printf("Liste des niveaux de prestations possibles:\n\tniveau 1 : maximum de prestations remboursees = 3000 DT par an et par prestataire\n\t\tTarif de cotisation total = 1725 DT.\n\tniveau 2 : maximum de prestations remboursees = 3500 DT par an et par prestataire\n\t\tTarif de cotisation total = 2070 DT.");
        else
            printf("Liste des niveaux de prestations possibles:\n\tniveau 1 : maximum de prestations remboursees = 3000 DT par an et par prestataire\n\t\tTarif de cotisation total = 1725 DT.\n\tniveau 2 : maximum de prestations remboursees = 3500 DT par an et par prestataire\n\t\tTarif de cotisation total = 2070 DT.\n\tniveau 3 : maximum de prestations remboursees = 5000 DT par an et par prestataire\n\t\tTarif de cotisation de base est de 2415 DT.");
        do{
                printf("\nVeuillez choisir le niveau de prestations souhaite: ");
                scanf("%d", &niveau);
           }while((niveau!=1)&&(niveau!=2)&&(niveau!=3));
        if(niveau==1)
            printf("Niveau 1: details des plafonds de remboursement:\n\tConsultations: 20 DT / acte\n\tMedicaments: 400 DT\n\tAnalyses: 150 DT\n\tRadiologie: 180 DT\n\tChirurgie: 1500 DT\nMaximum de prestations remboursées = 3000 DT par prestataire et par an\n");
        else if(niveau==2)
            printf("Niveau 2: details des plafonds de remboursement:\n\tConsultations: 30 DT / acte\n\tMedicaments: 600 DT\n\tAnalyses: 200 DT\n\tRadiologie: 250 DT\n\tChirurgie: 1800 DT\nMaximum de prestations remboursées = 3500 DT par prestataire et par an\n");
        else
            printf("Niveau 3: details des plafonds de remboursement:\n\tConsultations: 40 DT / acte\n\tMedicaments: 600 DT\n\tAnalyses: 300 DT\n\tRadiologie: 300 DT\n\tChirurgie: 2000 DT\nMaximum de prestations remboursées = 5000 DT par prestataire et par an\n");
    }
    else{
        printf("Liste des niveaux de prestations possibles: ");
        if(Budget<1500)
            printf("Votre budget est tres insuffisant!");
        else if((Budget>=1500)&&(Budget<1800))
            printf("Liste des niveaux de prestations possibles:\n\tniveau 1 : maximum de prestations remboursees = 3000 DT par an et par prestataire\n\t\tTarif de cotisation total = 1500 DT.");
        else if((Budget>=1500)&&(Budget<2100))
            printf("Liste des niveaux de prestations possibles:\n\tniveau 1 : maximum de prestations remboursees = 3000 DT par an et par prestataire\n\t\tTarif de cotisation total = 1500 DT.\n\tniveau 2 : maximum de prestations remboursees = 3500 DT par an et par prestataire\n\t\tTarif de cotisation total = 1800 DT.");
        else
            printf("Liste des niveaux de prestations possibles:\n\tniveau 1 : maximum de prestations remboursees = 3000 DT par an et par prestataire\n\t\tTarif de cotisation total = 1500 DT.\n\tniveau 2 : maximum de prestations remboursees = 3500 DT par an et par prestataire\n\t\tTarif de cotisation total = 1800 DT.\n\tniveau 3 : maximum de prestations remboursees = 5000 DT par an et par prestataire\n\t\tTarif de cotisation de base est de 2100 DT.");
        do{
                printf("\nVeuillez choisir le niveau de prestations souhaite: ");
                scanf("%d", &niveau);
           }while((niveau!=1)&&(niveau!=2)&&(niveau!=3));
        if(niveau==1)
            printf("Niveau 1: details des plafonds de remboursement:\n\tConsultations: 20 DT / acte\n\tMedicaments: 400 DT\n\tAnalyses: 150 DT\n\tRadiologie: 180 DT\n\tChirurgie: 1500 DT\nMaximum de prestations remboursées = 3000 DT par prestataire et par an\n");
        else if(niveau==2)
            printf("Niveau 2: details des plafonds de remboursement:\n\tConsultations: 30 DT / acte\n\tMedicaments: 600 DT\n\tAnalyses: 200 DT\n\tRadiologie: 250 DT\n\tChirurgie: 1800 DT\nMaximum de prestations remboursées = 3500 DT par prestataire et par an\n");
        else
            printf("Niveau 3: details des plafonds de remboursement:\n\tConsultations: 40 DT / acte\n\tMedicaments: 600 DT\n\tAnalyses: 300 DT\n\tRadiologie: 300 DT\n\tChirurgie: 2000 DT\nMaximum de prestations remboursées = 5000 DT par prestataire et par an\n");
    }

    return 0;
    }
