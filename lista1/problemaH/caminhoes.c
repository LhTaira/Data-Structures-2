#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pilha {
    int n;
    struct Pilha * prev;
} Pilha;

typedef struct Stack{
    char * value;
    struct Stack * next;
} Stack;

Pilha * append(Pilha * pilha, int elemento) {
    Pilha * no;
    no = (Pilha *) malloc(sizeof(Pilha));

    no->n = elemento;
    no->prev = pilha;
    return no;
}

Pilha * pop(Pilha * pilha) {
    Pilha * aux = pilha->prev;
    free(pilha);
    return aux;
}

Pilha * createPilha(Pilha * pilha) {
    pilha = malloc(sizeof(Pilha));
    pilha->prev = NULL;
    pilha->n = 0;
    return pilha;
}


Stack * createStack(char * n) {
    Stack * stack = (Stack *) malloc(sizeof(Stack));
    stack->value = (char *) malloc(4*sizeof(char));
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

Stack * popStack(Stack * stack) {
    Stack * aux = stack;

    aux = aux->next;
    free(stack);
    return(aux);
}

int main() {
    Pilha * pilha = NULL;

    Stack * response = NULL;

    Stack ** end;

    char no[3] = "no\0";
    char yes[4] = "yes\0";

    int numberOfTrucks;
    int not = 0;

    int * trucks;
    int * final;

    end = (Stack **) malloc(sizeof(Stack**));
    (* end) = (Stack *) malloc(sizeof(Stack*));

    while(scanf("%d", &numberOfTrucks) == 1 && numberOfTrucks != 0) {


        int j = 0;
        int k = 0;
        int expectedTruck = 1;

        pilha = createPilha(pilha);
        trucks = (int *) malloc((numberOfTrucks+1)*sizeof(int));
        final = (int *) malloc(numberOfTrucks*sizeof(int));

        for(j = 0; j<numberOfTrucks; j++) {
            scanf("%d", &trucks[j]);
        }

        trucks[j] = 0;
        j=0;

        while((pilha->n !=0 || trucks[j] != 0) && expectedTruck <= numberOfTrucks ) {
            if(trucks[j] == expectedTruck) {
                final[k] = expectedTruck;
                expectedTruck++;
                k++;
                j++;
            } else if(pilha->n == expectedTruck) {
                pilha = pop(pilha);
                final[k] = expectedTruck;
                expectedTruck++;
                k++;
            } else if(trucks[j] != 0) {
                pilha = append(pilha, trucks[j]);
                j++;
            } else {
                response = push(response, no, end);
                not = 1;
                break;
            }
        }
        if(not != 1) {
            response = push(response, yes, end);
        }
        
        not = 0;

        while(pilha->prev != NULL) {
            pilha = pop(pilha);
        }

        pilha = pop(pilha);

        free(pilha);
        free(trucks);
        free(final);
        }

    while(response->next != NULL) {
        printf("%s\n", response->value);
        response = popStack(response);
    }
        printf("%s\n", response->value);

    

    return 0;

}