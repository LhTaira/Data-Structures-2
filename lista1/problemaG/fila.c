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


Stack * push(Stack * stack, char * value) {
    Stack * aux = stack;
    if(stack == NULL) {
        stack = createStack(value);
        return stack;
    }

    while(stack->next != NULL) {
        stack = stack->next;
    }

    stack->next = createStack(value);
    return aux;
}

Stack * pop(Stack * stack) {
    Stack * aux = stack;

    aux = aux->next;
    free(stack);
    return(stack);
}

void toFinalDaFila(Stack * stack) {
    Stack * aux = stack;

    while(aux->next != NULL) {
        aux = aux->next;
    }

    aux->next = stack->next;
    stack->next = stack->next->next;
    aux->next->next = NULL;
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
    char name[26];

    while(scanf("%s", name) == 1) {
        stack = push(stack, name);
    }

    // while(1) {
    //     int i = 0;
    //     while(scanf("%c", &name[i++]) == 1 && name[i-1] != '\0' && name[i-1] != -1) {
    //     }
    //     stack = push(stack, name);

    //     if(name[i-1] != -1) {
    //         printf("shit\n");
    //         break;
    //     }
    // }
    

    aux = stack;
    
    while(stack->next !=NULL){
        if(getFirstChar(stack->next->value) == getLastChar(stack->value) ||
         getFirstChar(stack->next->value) == getLastChar(stack->value)-32 ||
          getFirstChar(stack->next->value) == getLastChar(stack->value)+32) {
            toFinalDaFila(stack);
        }

        stack = stack->next;
    }

    while(printf("%s\n", aux->value) && aux->next != NULL) {
        aux = aux->next;
    }

    return 0;

}