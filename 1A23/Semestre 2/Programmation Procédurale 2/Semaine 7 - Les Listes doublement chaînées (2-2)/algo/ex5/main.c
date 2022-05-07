#include "functions.h"

int main()
{
    int ch=-1;
    LD l; ep e; char c;

    initLDC(&l);
    do{
        menu(&ch);
        switch(ch){
            case 0:
                printf("...\n"); break;

            case 1:
                showPlaylist(l); break;

            case 2:
                do{
                    printf("\n~~~~ To stop adding episodes - Press \"N\" ~~~~\nChoice: "); fflush(stdin); scanf("%c", &c);
                    if((c!='n')&&(c!='N')){
                        saisirEpisode(&e); AjoutEpisode(&l, e);    
                    }
                }while((c!='n')&&(c!='N'));
                break;

            case 3:
                printf("%d\n", Theme_episode(l)); break;
        }
    }while(ch!=0);

    return 0;
}