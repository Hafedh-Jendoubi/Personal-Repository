#include "functions.h"

int main()
{
    int ch=-1;

    do{
        menu(&ch);
        switch(ch){
            case 0:
                printf("...\n"); break;

            case 1:
                break;
        }
    }while(ch!=0);

    return 0;
}
