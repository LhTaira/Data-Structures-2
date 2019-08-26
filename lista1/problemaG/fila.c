#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char value[26];
    struct Stack * next;
} Stack;

Stack * createStack(char * n) {
    Stack * stack = malloc(sizeof(Stack));
    stack->next = NULL;
    stack->value = n;

    return stack;
}


Stack * push(Stack * stack, char * value) {
    if(stack == NULL) {
        stack = createStack(value);
        return stack;
    }
    stack->next = createStack(value);
    return stack;
}

Stack * pop(stack) {
    Stack * aux = stack;

    aux = aux->next;
    free(stack);
    return(stack);
}

int main() {
    Stack * stack;
    char name[26];

    while(scanf("%s", name) == 1) {
        stack = push(name);
    }
}