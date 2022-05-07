#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *t, i;


    t = (int*) malloc(3*sizeof(int));
    if(t == NULL)
        printf("Memory struggle!\n");
    else{
        for(i=0; i<3; i++){
            printf("T[%d] = ", i+1); scanf("%d", &t+i);
        }
        printf("%d\t%d\t%d", t, t+1, t+2);
    }

    return 0;
}