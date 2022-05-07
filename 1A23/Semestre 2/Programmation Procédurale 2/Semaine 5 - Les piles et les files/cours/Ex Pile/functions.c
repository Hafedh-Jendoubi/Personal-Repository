#include "functions.h"

int bien_paranthesee(char *expr)
{
    int r, x1=0, x2=0;
    char *c;
    pile p=NULL, nouv;

    for(c=expr; *c!='\0'; c++){
        nouv = (pile*) malloc(sizeof(pile));
        if(nouv == NULL){
            printf("Error!\n"); break;
        }else{
            if(*c == '(')
                x1++;
            else if(*c == ')')
                x2++;
            nouv->c = *c;
            nouv->suivant = p;
            p = nouv;
        }
    }

    if(x1 == x2)
        r = 1;
    else
        r = 0;

    return r;
}
