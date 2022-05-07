#include "functions.h"
#include "menu.h"

int main()
{
    int ch=-1;
    liste l=NULL;

    do{
        menu(&ch);
        switch(ch){
            case 0:
                printf("...\n"); break;

            case 1:
                afficher_clients(l); menu(&ch); break;

            case 2:
                add_menu(&l, &ch); break;

            case 3:
                delete_menu(&l, &ch); break;

            case 4:
                search_menu(&l, &ch); break;
        }
    }while(ch!=0);

    return 0;
}
