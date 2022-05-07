#include <stdio.h>

int main()
{
    int a, b;

    printf("Taper a: "); scanf("%d", &a);
    printf("Taper b: "); scanf("%d", &b);
    if(a>b){
        printf("%d est le max!", a);
    }else{
        printf("%d est le max!", b);
    }

    return 0;
}
