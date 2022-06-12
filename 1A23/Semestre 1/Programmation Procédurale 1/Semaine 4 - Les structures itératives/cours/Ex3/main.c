#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, i=2;
    bool test=false;

    printf("Taper un nombre: "); scanf("%d", &n);

    while((test==false)&&(i<n)){
        if(n%i==0)
            test=true;
        else
            i++;
    }

    if(test==true)
        printf("%d n'est pas un nombre premier.\n", n);
    else
        printf("%d est un nombre premier.\n", n);

    return 0;
}
