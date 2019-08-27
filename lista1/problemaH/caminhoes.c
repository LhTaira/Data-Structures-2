#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack{
    int number;
    struct Stack * next;
} Stack;

Stack * createStack(char * n) {
    Stack * stack = (Stack *) malloc(sizeof(Stack));

    stack->next = NULL;
    stack->number = n;

    return stack;
}


Stack * push(Stack * stack, char * value, Stack ** end) {
    Stack * aux = stack;
    if(stack == NULL) {
        stack = createStack(value);
        (*end) = stack;

        return stack;
    }

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

int main() {
    Stack * stack = NULL;
    // Stack * aux;

    int numberOfTrucks;
    int aux;

    int * trucks;

    Stack ** end;
    end = (Stack **) malloc(sizeof(Stack**));
    (* end) = (Stack *) malloc(sizeof(Stack*));

    scanf("%d", &numberOfTrucks);

    trucks = (int*) malloc(numberOfTrucks*sizeof(int));

    for(int i = 0; i<numberOfTrucks; i++) {
        scanf("%d", &trucks[i]);
    }
  

    return 0;

}