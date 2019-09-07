#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int value;
    struct Queue * next;
} Queue;

Queue * createQueue(int n) {
    Queue * queue = malloc(sizeof(Queue));
    queue->next = NULL;
    queue->value = n;

    return queue;
}


Queue * push(Queue * queue, int value, Queue ** end) {
    Queue * aux = queue;
    if(queue == NULL) {
        queue = createQueue(value);
        (*end) = queue;

        return queue;
    }

    (*end)->next = createQueue(value);
    (*end) = (*end) -> next;
    return aux;
}

Queue * pop(Queue * queue) {

    if(queue == NULL) {
        return queue;
    }

    Queue * aux = queue;

    aux = aux->next;
    free(queue);
    return(aux);
}

int main() {
    int n, m, j = 0, tempo = 0, aux;

    int * casas;
    Queue * encomendas = NULL;
    Queue ** end;


    scanf("%d", &n);
    scanf("%d", &m);

    casas = malloc(n * sizeof(int));
    (end) = malloc(sizeof(Queue **));
    (*end) = malloc(sizeof(Queue *));
    (*end) = encomendas;

    for(int i = 0; i < n; i++) {
        scanf("%d", &casas[i]);
    }

    for(int i = 0; i < m; i++) {
        scanf("%d", &aux);
        encomendas = push(encomendas, aux, end);
    }

    for(int i = 0; i < m; i++) {
        if(encomendas == NULL) {
            break;
        }

        while(encomendas->value < casas[j]) {
            j--;
            tempo++;
        }
        while(encomendas->value > casas[j]) {
            j++;
            tempo++;
        }
        
        encomendas = pop(encomendas);
    }

    printf("%d\n", tempo);

    free(casas);
    free(end);
    
    return 0;
}