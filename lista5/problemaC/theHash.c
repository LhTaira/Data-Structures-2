#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define swap(a, b) {char c = a; a = b; b = c; }

void reverse(char str[], int length) 
{ 
    int start = 0; 
    int end = length -1; 
    while (start < end) 
    { 
        swap(*(str+start), *(str+end)); 
        start++; 
        end--; 
    } 
} 
  
// Implementation of itoa() 
char* itoa(int num, char* str, int base) 
{ 
    int i = 0; 
    int isNegative = 0; 
  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    } 
  
    // In standard itoa(), negative numbers are handled only with  
    // base 10. Otherwise numbers are considered unsigned. 
    if (num < 0 && base == 10) 
    { 
        isNegative = 1; 
        num = -num; 
    } 
  
    // Process individual digits 
    while (num != 0) 
    { 
        int rem = num % base; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/base; 
    } 
  
    // If number is negative, append '-' 
    if (isNegative == 1) 
        str[i++] = '-'; 
  
    str[i] = '\0'; // Append string terminator 
  
    // Reverse the string 
    reverse(str, i); 
  
    return str; 
} 

typedef struct OutputItem {
    char string[100];
    struct OutputItem * next;
} OutputItem;

typedef struct DataItem {
    int id;
    char fn[10];
    char ln[10];
    char bd[11];
    char pn[17];

    struct DataItem * next;
} DataItem;

OutputItem ** pushOutputFirst(OutputItem ** outputLast, char * string) {
    OutputItem ** aux = malloc(sizeof(OutputItem));

    strcpy((*aux)->string, string);
    (*aux)->next = NULL;

    outputLast = aux;
    return aux;
}
 
OutputItem ** pushOutput(OutputItem ** outputQueue, OutputItem ** outputLast, char * string) {
    if(*outputQueue == NULL) {
        return pushOutputFirst(outputLast, string);
    }

    OutputItem * item = malloc(sizeof(OutputItem));
    strcpy(item->string, string);
    item->next = NULL;
    (*outputLast)->next = item;
    *outputLast = item;
    return outputQueue;
}

void printOutputQueue(OutputItem ** outputQueue) {
    while(*outputQueue != NULL) {
        printf("%s", (*outputQueue)->string);
        (*outputQueue) = (*outputQueue)->next;
    }
}

DataItem * pushFirst(DataItem * list, DataItem ** last, int id, char * fn, char * ln, char * bd, char * pn) {
    list = malloc(sizeof(DataItem));

    list->id = id;
    strcpy(list->fn, fn);
    strcpy(list->ln, ln);
    strcpy(list->bd, bd);
    strcpy(list->pn, pn);
    list->next = NULL;
    *last = list;

    return list;
}

DataItem * pushBack(DataItem * list, DataItem ** last, int id, char * fn, char * ln, char * bd, char * pn, OutputItem ** outputQueue, OutputItem ** outputLast) {
    if(list == NULL) {
        return pushFirst(list, last, id, fn, ln, bd, pn);
    }
    DataItem * aux = list;
    while(aux != NULL) {
        if(aux->id == id) {
            char stringAux[26];
            char  stringAux2[6];

            itoa(id, stringAux2, 10);
            strcpy(stringAux, "ID ");
            strcat(stringAux, stringAux2);
            strcat(stringAux, " ja cadastrado.\n");
            pushOutput(outputQueue, outputLast, stringAux);
            return list;
        }
        aux = aux->next;
    }

    DataItem * item = malloc(sizeof(DataItem));
    strcpy(item->fn, fn);
    strcpy(item->ln, ln);
    strcpy(item->bd, bd);
    strcpy(item->pn, pn);
    item->next = NULL;

    (*last)->next = item;
    (*last) = item;

    return list;
}

DataItem * delete(DataItem * list, DataItem ** last, int id, OutputItem ** outputQueue, OutputItem ** outputLast) {
    if(list == NULL) {
        char stringAux[100];
        char stringAux2[6];
        itoa(id, stringAux2, 10);
        strcpy(stringAux, "ID ");
        strcat(stringAux, stringAux2);
        strcat(stringAux, " nao existente.\n");
        pushOutput(outputQueue, outputLast, stringAux);
        return list; 
    }

    if(list->id == id) {
        if(*last = list) {
            free(list);
            list == NULL;
            *last == NULL;
            return list;
        }
        DataItem * aux = list;

        list = list->next;
        free(aux);
        return list;
    }
    while(list->next != NULL) {
        list = list->next;

        if(list->id == id) {
            if(*last = list) {
                free(list);
                list == NULL;
                *last == NULL;
                return list;
            }
            
            DataItem * aux = list;

            list = list->next;
            free(aux);
            return list;
        }
    }
}

void info(DataItem * list, int id, OutputItem ** outputQueue, OutputItem ** outputLast) {  
    while(list != NULL) {
        if(list->id == id) {
            char stringAux[100];
            strcpy(stringAux, list->fn);
            strcat(stringAux, " ");
            strcat(stringAux, list->ln);
            strcat(stringAux, " ");
            strcat(stringAux, list->bd);
            strcat(stringAux, " ");
            strcat(stringAux, list->pn);
            strcat(stringAux, "\n");
            pushOutput(outputQueue, outputLast, stringAux);
            return;
        }
        list = list->next;
    }

    char stringAux[100];
    char stringAux2[6];
    itoa(id, stringAux2, 10);
    strcpy(stringAux, "ID ");
    strcat(stringAux, stringAux2);
    strcat(stringAux, " nao existente.\n");
    pushOutput(outputQueue, outputLast, stringAux);
}

int queryFn(DataItem * list, int id, char * fn) {
    while(list != NULL) {
        if(list->id == id){
            if(strcmp(list->fn, fn) == 0) {
                return 1;
            }
        }
        list = list->next;
    }
    return 0;
}

int queryLn(DataItem * list, int id, char * ln) {
    while(list != NULL) {
        if(list->id == id){
            if(strcmp(list->ln, ln) == 0) {
                return 1;
            }
        }
        list = list->next;
    }
    return 0;
}

int queryBd(DataItem * list, int id, char * bd) {
    while(list != NULL) {
        if(list->id == id){
            if(strcmp(list->bd, bd) == 0) {
                return 1;
            }
        }
        list = list->next;
    }
    return 0;
}

int queryPn(DataItem * list, int id, char * pn) {
    while(list != NULL) {
        if(list->id == id){
            if(strcmp(list->pn, pn) == 0) {
                return 1;
            }
        }
        list = list->next;
    }
    return 0;
}

void query(DataItem * list, char * fn, char * ln, char * bd, char * pn, OutputItem ** outputQueue, OutputItem ** outputLast) {
   int id;
    char stringAux[100];
    char stringAux2[6];
    int i = 0;
    strcpy(stringAux, "");
   while(list != NULL){
        id = list->id;

        if(fn[0] == '0' || queryFn(list, id, fn) == 1) {
            if(ln[0] == '0' || queryLn(list, id, ln) == 1) {
                if(bd[1] == '0'|| queryBd(list, id, bd) == 1) {
                    if(pn[0] == '0' || queryPn(list, id, pn) == 1) {
                        if(i > 0) {
                            strcat(stringAux, " ");
                        }
                        itoa(id, stringAux2, 10);
                        strcat(stringAux, stringAux2);
                    }
                }
            }
        }
        i++;
        list = list->next;
    }
    strcat(stringAux, "\n");
    pushOutput(outputQueue, outputLast, stringAux);
}

int main() {
    DataItem * list = NULL;
    DataItem ** last;

    OutputItem ** outputQueue;
    OutputItem ** outputLast;

    outputQueue = malloc(sizeof(OutputItem*));
    *outputQueue = NULL;
    outputLast = malloc(sizeof(OutputItem*));
    *outputLast = NULL;

    last = malloc(sizeof(DataItem*));
    *last = NULL;

    char input[100], fn[10], ln[10], bd[11], pn[17];
    int id;


    while(scanf("%s", input) == 1) {
        cheat:
        switch(input[0]) {
            case 'a':
                scanf("%d", &id);
                scanf("%s", fn);
                scanf("%s", ln);
                scanf("%s", bd);
                scanf("%s", pn);

                list = pushBack(list, last, id, fn, ln, bd, pn, outputQueue, outputLast);
                break;
            case 'd':
                scanf("%d", &id);

                list = delete(list, last, id, outputQueue, outputLast);
                break;
            case 'q':
                while(scanf("%s", input) == 1 && (input[0] == 'f' || input[0] == 'l' || input[0] == 'b' || input[0] == 'p')) {
                    fn[0] = '0';
                    ln[0] = '0';
                    bd[1] = '0';
                    pn[0] = '0';

                    if(input[0] == 'f') {
                        strcpy(fn, &input[3]);
                    } else if(input[0] == 'l') {
                        strcpy(ln, &input[3]);
                    } else if(input[0] == 'b') {
                        strcpy(bd, &input[3]);
                    } else if(input[0] == 'p') {
                        strcpy(pn, &input[3]);
                    }
                }
                query(list, fn, ln, bd, pn, outputQueue, outputLast);
                goto cheat;
                break;
            case 'i':
                scanf("%d", &id);
                info(list,  id, outputQueue, outputLast);
                break;
        }
    }


    printOutputQueue(outputQueue);
    return 0;
}