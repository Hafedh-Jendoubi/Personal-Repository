#include <stdio.h>
#include <stdlib.h>

typedef struct Cellule{
    int val;
    struct Cellule *next;
    struct Cellule *back;
}cellule;

typedef struct listeDC{
    cellule *head;
    cellule *tail;
}LDC;

void initLDC(LDC *l)
{
    l->head = NULL;
    l->tail = NULL;
}

void showLDC(LDC l)
{
    cellule *walk;

    if(l.head == NULL & l.tail == NULL)
        printf("List empty!\n");
    else{
        walk = l.head;
        while(walk != NULL){
            printf("%d\t", walk->val);
            walk = walk->next;
        }
    }
}

void add_tail(LDC *l, int x)
{
    cellule *new;

    new = (cellule*) malloc(sizeof(cellule));
    if(new == NULL)
        printf("Memory Struggle, (add_tail() function)\n");
    else{
        new->val = x;
        new->next = NULL;
        new->back = l->tail;
        if(l->head == NULL && l->tail == NULL)
            l->head = new;
        else
            l->tail->next = new;
        l->tail = new;
    }
}

void add_head(LDC *l, int x)
{
    cellule *new;

    new = (cellule*) malloc(sizeof(cellule));
    if(new == NULL)
        printf("Memory Struggle, (add_head() function)\n");
    else{
        new->val = x;
        new->back = NULL;
        new->next = l->head;
        if(l->head == NULL && l->tail == NULL)
            l->tail = new;
        else
            l->head->back = new;
        l->head = new;
    }
}

LDC concatene_liste(LDC a, LDC b)
{
    cellule *parc=a.head;

    if(parc == NULL)
        printf("a is empty\n");
    else{
        while(parc != NULL){
            add_tail(&b, parc->val);
            parc = parc->next;
        }
    }

    return b;
}

LDC inverse_liste(LDC a)
{
    cellule *forward=a.head, *back=a.tail;
    int x;

    if(a.head == NULL)
        printf("Liste is empty!\n");
    else{
        while((forward != back) && (forward->back != back)){
            x = forward->val;
            forward->val = back->val;
            back->val = x;
            forward = forward->next;
            back = back->back;
        }
    }

    return a;
}

LDC fusion_liste(LDC a, LDC b) //Only This functions is not working!!!
{
    cellule *new, *parc_b=b.head, *parc_a;

    if(b.head == NULL)
        printf("Empty list!\n");
    else{
        while(parc_b != NULL){
            new = (cellule*) malloc(sizeof(cellule));
            if(new == NULL)
                printf("Memory Error!\n");
            else{
                new->val = parc_b->val;
                parc_a = a.head;
                while((new->val < parc_a->val) && (parc_a != NULL)){
                    parc_a = parc_a->next;
                }
            }
            parc_b = parc_b->next;
        }
    }

    return a;
}

int main()
{
    LDC a, b;

    initLDC(&a); initLDC(&b);

    add_tail(&a, 1); add_tail(&a, 3); add_tail(&a, 5); add_tail(&a, 7); // a: Liste Doublement chainnée contenu entiers impairs
    add_tail(&b, 0); add_tail(&b, 2); add_tail(&b, 4); add_tail(&b, 6); // b: Liste Doublement chainnée contenu entiers pairs #~~~~~~~~~~~~~~~~#

    printf("a:\t"); showLDC(a); printf("\n");
    printf("b:\t"); showLDC(b);

    a = fusion_liste(a, b);

    printf("\n\n");

    showLDC(a);

    return 0;
}