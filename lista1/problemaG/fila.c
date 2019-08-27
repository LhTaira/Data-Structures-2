#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack{
    char * value;
    struct Stack * next;
} Stack;

Stack * createStack(char * n) {
    Stack * stack = (Stack *) malloc(sizeof(Stack));

    stack->value = (char *) malloc(26*sizeof(char));
    stack->next = NULL;
    strcpy(stack->value, n);

    return stack;
}


Stack * push(Stack * stack, char * value, Stack ** end) {
    Stack * aux = stack;
    if(stack == NULL) {
        stack = createStack(value);
        (*end) = stack;

        return stack;
    }

    // while(stack->next != NULL) {
    //     stack = stack->next;
    // }

    (*end)->next = createStack(value);
    (*end) = (*end) -> next;
    return aux;
}

Stack * pop(Stack * stack) {
    Stack * aux = stack;

    aux = aux->next;
    free(stack);
    return(stack);
}

void toFinalDaFila(Stack * stack, Stack ** aux) {
    // Stack * aux = end;

    // while(aux->next != NULL) {
    //     aux = aux->next;
    // }

    (*aux)->next = stack->next;
    stack->next = stack->next->next;
    (*aux)->next->next = NULL;
    (*aux) = (*aux)->next;
}

char getLastChar(char * string) {
    char aux;
    int i=0;

    while(string[i] != '\0') {
        aux = string[i++];
    }
     return aux;
}

char getFirstChar(char * string) {
    return string[0];
}

int main() {
    Stack * stack = NULL;
    Stack * aux;

    Stack ** end;
    end = (Stack **) malloc(sizeof(Stack**));
    (* end) = (Stack *) malloc(sizeof(Stack*));
    char name[26];

    while(scanf("%s", name) == 1) {
        stack = push(stack, name, end);
    }

    aux = stack;
    
    while(stack->next !=NULL){
        if(getFirstChar(stack->next->value) == getLastChar(stack->value) ||
         getFirstChar(stack->next->value) == getLastChar(stack->value)-32 ||
          getFirstChar(stack->next->value) == getLastChar(stack->value)+32) {
            toFinalDaFila(stack, end);
        }

        stack = stack->next;
    }

    while(printf("%s\n", aux->value) && aux->next != NULL) {
        aux = aux->next;
    }

    return 0;

}