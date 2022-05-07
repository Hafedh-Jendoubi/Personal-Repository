#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char id[30];
    int age;
}voyageur;

int main()
{
    /** ****************************** STRUCT READ ****************************** **/
    FILE *f;
    char filename[30] = "struct_test.bin";
    voyageur v, v_test;
    int i, choix, k=0;

    f = fopen(filename, "wb");
    if(f==NULL)
        printf("EROR: Memory struggle!\n");
    else
    {
        for(i=0; i<2; i++){
            printf("ID[%d]: ", i+1); scanf("%s", v.id);
            printf("Age[%d]: ", i+1); scanf("%d", &v.age);
            fwrite(&v, sizeof(voyageur), 1, f);
        }
    }
    fclose(f);

    f = fopen(filename, "rb");
    if(f==NULL)
        printf("EROR: Memory Struggle!\n");
    else{
        printf("Voulez vous lire le contenu de ce fichier? ([0] Non - [1] Oui) "); scanf("%d", &choix);
        if(choix==0){
            printf("Quitting..\n");
            exit(1);
        }else
        {
                printf("**Reading the bin file..**\n"); sleep(1); printf("It says: \n");
                while(k<2){
                    k++;
                    fread(&v_test, sizeof(voyageur), 1, f);
                    printf("ID: %s\tAge: %d\n", v_test.id, v_test.age);
            }
        }
    }
    fclose(f);

    return 0;
}

    /** ****************************** STRING READ ******************************
    FILE *f;
    char buffer[30], ch[30], filename[20] = "test.bin";
    int choix;

    f = fopen(filename, "wb");
    if(f==NULL)
        printf("EROR: Memory struggle!\n");
    else
    {
        printf("Taper une phrase: "); fflush(stdin); gets(ch);
        fwrite(&ch, sizeof(char), 30, f);
        printf("**Writing it on the bin file..**\n"); sleep(1); printf("Done.\n");
    }
    fclose(f);

    f = fopen(filename, "rb");
    if(f==NULL)
        printf("EROR: Memory Struggle!\n");
    else{
        printf("Voulez vous lire le contenu de ce fichier? ([0] Non - [1] Oui) "); scanf("%d", &choix);
        if(choix==0){
            printf("Quitting..\n");
            exit(1);
        }else
        {
            fread(&buffer, sizeof(char), 30, f);
            printf("**Reading the bin file..**\n"); sleep(1); printf("It says: \n");
            printf("%s\n", buffer);
        }
    }
    fclose(f);
    ********************************************************************************** **/
