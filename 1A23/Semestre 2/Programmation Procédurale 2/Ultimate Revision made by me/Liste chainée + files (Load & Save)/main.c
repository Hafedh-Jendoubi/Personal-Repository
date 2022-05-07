#include "functions.h"

int main()
{
    int ch=-1, x;
    list l;

    l = load_data();
    do{
        menu(&ch);
        switch(ch){
            case 0:
                save_data(l); break;

            case 1:
                show_list(l); break;

            case 2:
                printf("Type a number: "); scanf("%d", &x);
                l = add_element(l, x); break;

            case 3:
                l = delete_element(l); break;
        }
    }while(ch!=0);

    return 0;
}