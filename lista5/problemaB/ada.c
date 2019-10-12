#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int value;
    struct Item * prev;
    struct Item * next;
} Item;

typedef struct Head {
    struct Tail * tail;
    Item * next;
} Head;

typedef struct Tail {
    struct Head * head;
    Item * prev;
} Tail;

void pushBack(Head * head, Tail * tail, int isHeadOrTail, int value);
void popBack(Head * head, Tail * tail, int isHeadOrTail);

//isHeadOrTail == 0: head == head
//isHeadOrTail == 1: head == tail

void createList(Head * head, Tail * tail) {
    head->tail = tail;
    tail->head = head;

    head->next = NULL;
    tail->prev = NULL;
}

void pushFirst(Head * head, Tail * tail, int value) {
    Item * item = malloc(sizeof(Item));

    item->value = value;
    item->prev = NULL;
    item->next = NULL;

    head->next = item;
    tail->prev = item;
}

void pushFront(Head * head, Tail * tail, int isHeadOrTail, int value) {
    if(isHeadOrTail == -1) {
        pushBack(head, tail, 1, value);
        return;
    }

    if(head->next == NULL) {
        pushFirst(head, tail, value);
        return;
    }
    
    Item * item = malloc(sizeof(Item));
    
    item->value = value;
    item->next = head->next;
    item->prev = NULL;

    head->next->prev = item;
    head->next = item;
}

void pushBack(Head * head, Tail * tail, int isHeadOrTail, int value) {
    if(isHeadOrTail == -1) {
        pushFront(head, tail, 1, value);
        return;
    }

    if(tail->prev == NULL) {
        pushFirst(head, tail, value);
        return;
    }

    Item * item = malloc(sizeof(Item));
    
    item->value = value;
    item->prev = tail->prev;
    item->next = NULL;

    tail->prev->next = item;
    tail->prev = item;
}

void popFront(Head * head, Tail * tail, int isHeadOrTail) {
    if(isHeadOrTail == -1) {
        popBack(head, tail, 1);
        return;
    }

    if(head->next == NULL) {
        printf("No job for Ada?\n");
        return;
    }

    printf("%d\n", head->next->value);
    
    Item * toFree = head->next;

    if(head->next->next == NULL) {
        head->next = NULL;
        tail->prev = NULL;
        free(toFree);
        return;
    }
    head->next->next->prev = NULL;
    head->next = head->next->next;

    free(toFree);
}

void popBack(Head * head, Tail * tail, int isHeadOrTail) {
    if(isHeadOrTail == -1) {
        popFront(head, tail, 1);
        return;
    }

    if(tail->prev == NULL) {
        printf("No job for Ada?\n");
        return;
    }

    printf("%d\n", tail->prev->value);
    
    Item * toFree = tail->prev;

    if(tail->prev->prev == NULL) {
        tail->prev = NULL;
        head->next = NULL;
        free(toFree);
        return;
    }

    tail->prev->prev->next = NULL;
    tail->prev = tail->prev->prev;

    free(toFree);
}

int main() {
    int isHeadOrTail = 1;
    int nOperations, aux;

    char operation[9];

    Head * head;
    Tail * tail;

    head = malloc(sizeof(Head));
    tail = malloc(sizeof(Tail));

    createList(head, tail);

    scanf("%d", &nOperations);

    for(int i = 0; i < nOperations; i++) {
        scanf("%s", operation);

        switch(operation[0]) {
            case 'b'://print from back
                popBack(head, tail, isHeadOrTail);
                break;
            case 'f'://print from front
                popFront(head, tail, isHeadOrTail);
                break;
            case 'r'://switch head and tail
                isHeadOrTail = -isHeadOrTail;
                break;
            case 'p'://pushBack
                scanf("%d", &aux);
                pushBack(head, tail, isHeadOrTail, aux);
                break;
            case 't'://pushFront
                scanf("%d", &aux);
                pushFront(head, tail, isHeadOrTail, aux);
                break;
        }
    }
    
    return 0;
}