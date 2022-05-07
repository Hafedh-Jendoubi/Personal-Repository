#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, p, o, m, n;
    float M1[50][50], M2[50][50], S[50][50];

    do{
    printf("Taper le nombre de lignes de M1: "); scanf("%d", &m);
    }while(m<=0);
    do{
    printf("Taper le nombre de colones de M1: "); scanf("%d", &n);
    }while(n<=0);
    do{
    printf("Taper le nombre de lignes de M2: "); scanf("%d", &o);
    }while(o<=0);
    do{
    printf("Taper le nombre de colones de M2: "); scanf("%d", &p);
    }while(p<=0);

    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            printf("Donner la valeur à stocker M1[%d][%d]: ", i, j); scanf("%f", &M1[i][j]);
        }
    }
    for (i=0; i<o; i++){
        for (j=0; j<p; j++){
            printf("Donner la valeur à stocker M2[%d][%d]: ", i, j); scanf("%f", &M2[i][j]);
        }
    }

    if((m>=o)&&(n>p)){
        for(i=0; i<m; i++){
            for(j=0; j<n; j++)
                S[i][j] = M1[i][j] + M2[i][j];
        }
        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                printf("%.2f | ", S[i][j]);
            }
            printf("\n");
        }
    }
    else if((m>=o)&&(n<p)){
        for(i=0; i<m; i++){
            for(j=0; j<p; j++)
                S[i][j] = M1[i][j] + M2[i][j];
        }
        for(i=0; i<m; i++){
            for(j=0; j<p; j++){
                printf("%.2f | ", S[i][j]);
            }
            printf("\n");
        }
    }
    else if((m<o)&&(n>=p)){
        for(i=0; i<o; i++){
            for(j=0; j<n; j++)
                S[i][j] = M1[i][j] + M2[i][j];
        }
        for(i=0; i<o; i++){
            for(j=0; j<n; j++){
                printf("%.2f | ", S[i][j]);
            }
            printf("\n");
        }
    }else{
        for(i=0; i<o; i++){
            for(j=0; j<p; j++)
                S[i][j] = M1[i][j] + M2[i][j];
        }
        for(i=0; i<o; i++){
            for(j=0; j<p; j++){
                printf("%.2f | ", S[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
