#include <stdio.h>

int main()
{
    int i, j, mi, ma, k, N, M[50][50], max[50], min[50];

    printf("Taper le nombre de case et colones de cette Matrice: "); scanf("%d", &N);

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("Remplissez M[%d][%d]: ", i, j); scanf("%d", &M[i][j]);
        }
    }

    k=0;
    for(i=0; i<N; i++){
        ma = M[i][0];
        for(j=0; j<N; j++){
            if(M[i][j]>ma){
                max[k] = M[i][j];
                k = k + 1;
            }
        }
    }
    k=0;
    for(j=0; j<N; j++){
        mi = M[0][j];
        for(i=0; i<N; i++){
            if(M[i][j]<mi){
                min[k] = M[i][j];
                k = k + 1;
            }
        }
    }

    for(i=0; i<N; i++)
        printf("%d | ", max[i]);
    printf("\n");
    for(i=0; i<N; i++)
        printf("%d | ", min[i]);

    return 0;
}
