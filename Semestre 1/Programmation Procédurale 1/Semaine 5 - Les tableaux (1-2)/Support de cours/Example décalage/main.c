#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, T[9]={11,20,7,10,0,15,12,14,8};

    for(i=0; i<8; i++){
        printf("| %d |", T[i]);         //Affichage du tableau initial
    }

    printf("\n\n");
    for(i=8; i>=4; i--){                //Déplacement des élements du tableau
        T[i] = T[i-1];
    }

    T[4] = 9;                           //Affectation

    for(i=0; i<9; i++){
        printf("| %d |", T[i]);         //Affichage du tableau final
    }

    return 0;
}
