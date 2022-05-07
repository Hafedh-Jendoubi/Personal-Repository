#include "functions.h"

void menu(int *ch)
{
    if(*ch == -1){
        printf("~~~~~~~~ Menu: ~~~~~~~~\n");
        printf("1- Show list elements\n");
        printf("2- Add element\n");
        printf("3- Delete element\n");
        printf("0- Exit\n");
    }
    do{
        printf("\nTaper votre choix: "); scanf("%d", &*ch);
    }while((*ch<0)||(*ch>3));
}

void show_list(list l)
{
    if(l == NULL)
        printf("List is empty\n");
    else{
        struct cellule *parc=l;

        while(parc != NULL){
            printf("%d\t", parc->val);
            parc = parc->next;
        }
        printf("\n");
    }
}

list add_element(list l, int x)
{
    FILE *f=NULL;

    f = fopen("history.txt", "a");
    if(f == NULL)
        printf("Eror: Can not have access to the file (add_element function).\n");
    else{
        struct cellule *nouv;

        nouv = (struct cellule*) malloc(sizeof(struct cellule));
        if(nouv == NULL)
          printf("Eror: Memory struggle. (add_element function)\n");
        else{
            struct tm *t;
            time_t mytime;

            time(&mytime);
            t = localtime(&mytime);
            
            nouv->val = x;
            nouv->next = NULL;
            if(l == NULL)
                l = nouv;
            else{
                struct cellule *parc=l;

                while(parc->next != NULL)
                    parc = parc->next;
                parc->next = nouv;
            }
            printf("Number %d has been added succefully\n", x);
            fprintf(f, "<%d/%d %d:%d:%d> Number %d has been succefully added\n",t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec, x);
        }
    }
    fclose(f);

    return l;
}

list delete_element(list l)
{
    FILE *f=NULL;

    f = fopen("history.txt", "a");
    if(f == NULL)
        printf("Eror: Can not have access to the file (delete_element function).\n");
    else{
        if(l == NULL)
            printf("List is empty\n");
        else{
            struct cellule *parc=l;
            struct tm *t;
            time_t mytime;

            time(&mytime);
            t = localtime(&mytime);

            if(parc->next == NULL){
                free(parc);
                l = NULL;
            }else{
                struct cellule *recent;

                while(parc->next != NULL){
                    recent = parc;
                    parc = parc->next;
                }
                recent->next = NULL;
                free(parc);
            }
            printf("Number has been succefully deleted\n");
            fprintf(f, "<%d/%d %d:%d:%d> Number has been succefully deleted\n",t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
        }
    }
    fclose(f);

    return l;
}

void save_data(list l)
{
    FILE *f=NULL;

    f = fopen("data.txt", "w+");
    if(f == NULL)
        printf("Eror: Can not have access to the file (save_data function).\n");
    else{
        struct cellule *parc=l;

        while(parc!=NULL){
            fprintf(f, "%d\n", parc->val);
            parc = parc->next;
        }
    }
    fclose(f);
}

int checkIfFileExists()
{
    struct stat buffer;
    int exist = stat("data.txt", &buffer);

    if(exist == 0)
        return 1;
    else
        return 0;
}

list load_data(struct tm *timeinfo)
{
    FILE *f=NULL;
    list l=NULL;
    time_t rawtime;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    if(checkIfFileExists()==1){
        f = fopen("data.txt", "r");
        if(f == NULL)
            printf("Eror: Can not have access to the file (load_data function).\n");
        else{
            int x; FILE *h=NULL;

            h = fopen("history.txt", "a");
            fprintf(h, "\n~~~~~~~~ Loading Data ~~~~~~~~\n");
            fclose(h);
            while(!feof(f)){
                fscanf(f, "%d\n", &x);
                l = add_element(l, x);
            }
            h = fopen("history.txt", "a");
            fprintf(h, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
            fclose(h);
        }
    }else
        f = fopen("data.txt", "w+");
    fclose(f);

    return l;
}