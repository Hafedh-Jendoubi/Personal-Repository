#include <stdio.h>
#include <stdlib.h>

//Question 1:
int remplissage(int T[])
{
    int i, n;

    do{
        printf("Taper la taille du tableau: "); scanf("%d", &n);
    }while((n<0) || (n>50));
    for(i=0; i<n; i++){
        printf("Veuillez saisir T[%d] = ", i+1);
        scanf("%d", &T[i]);
    }

    return n;
}

//Question 2:
void affichage(int n, int T[])
{
    int i;

    for(i=0; i<n; i++)
        printf("%d | ", T[i]);
}

//Question 3:
float calculmoy(int n, int T[])
{
    int i;
    float moy=0;

    for(i=0; i<n; i++){
        moy = moy + T[i];
    }

    return moy/n;
}

//Question 4 - Pourcentage des nombres <5:
float pourcentage(int n, int T[])
{
    int k, i, t1[50];
    float pour;

    k=0;
    for(i=0; i<n; i++){
        if(T[i]<5){
            t1[k] = T[i];
            k++;
        }
    }
    pour = (k*100)/n;

    return pour;
}

//Question 5:
float variance(int n, int T[])
{
    int i;
    float var=0, xbar=0;

    for(i=0; i<n; i++)
        xbar = xbar + T[i];
    xbar = xbar/n;
    for(i=0; i<n-1; i++)
        var = var + (T[i] - xbar)*(T[i] - xbar);

    return var/n;
}

//Question 6 - Ajout 1ere methode:
int ajouterAFinTab1(int T[], int n)
{
    int x;
    printf("Donner la valeur à ajouter: ");
    scanf("%d", &x);

    T[n] = x;
    n++;

    return n;
}

//Question 6 - Ajout 2eme methode:
int ajouterAFinTab2(int T[], int n, int x)
{
    T[n] = x;
    n++;

    return n;
}

//STILL MORE!!!!!!!!!!!!!!!


int main()
{
    int n, T[50];
    float moy, pour, var;

    n = remplissage(T);
    affichage(n, T);
    moy = calculmoy(n, T);
    pour = pourcentage(n, T);
    var = variance(n, T);

    return 0;
}
