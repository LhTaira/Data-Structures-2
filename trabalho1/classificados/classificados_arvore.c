#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    int id;
    int nNos;
    struct Node * l;
    struct Node * r;
} Node;

int updateNos(Node * tree) {
    if (tree == NULL) {
        return 0;
    }

    tree->nNos =  1 + updateNos(tree->l) + updateNos(tree->r);
    return tree->nNos;
}

Node * createTree(int value, int id) {
    Node * tree = malloc(sizeof(Node));

    tree->l = NULL;
    tree->r = NULL;
    tree->value = value;
    tree->id = id;

    return tree;
}

Node * rotateLeft(Node * grandParent) {
	Node * temp = grandParent->r;
	grandParent->r = temp->l;
	temp->l = grandParent;
	return temp;
}

Node * rotateRight(Node * grandParent) {
	Node * temp = grandParent->l;
	grandParent->l = temp->r;
	temp->r = grandParent;
	return temp;
}

Node * partR(Node * h, int k) {

    int t = (h->l == NULL) ? 0: h->l->nNos;

    if(t > k) {
        h->l = partR(h->l, k);
        h = rotateRight(h);
    }

    if(t < k) {
        h->r = partR(h->r, k-t-1);
        h = rotateLeft(h);
    }

    return h;
}

Node * balance(Node * h) {
    if(h->nNos <= 2) {
        return h;
    }

    h = partR(h, h->nNos/2);
    h->l = balance(h->l);
    h->r = balance(h->r);
    return h;
}

int * selectR(Node * h, int k) {
    if(h == NULL) {
        return NULL;
    }

    int t = (h->l == NULL) ? 0: h->l->nNos;

    if(t > k) {
        return selectR(h->l, k);
    }

    if(t < k) {
        return selectR(h->r, k-t-1);
    }
    int * temp = malloc(sizeof(int));
    *temp = h->value ;
    return temp;
}

Node * addNode(Node * tree, int value, int id) {
    if(tree == NULL) {
        return createTree(value, id);
    }

    Node * newNode = malloc(sizeof(Node));
    
    newNode->value = value;
    newNode->id = id;

    if(tree->value < value) {
        newNode->l = tree;
        newNode->r = NULL;
    } else if(tree->value == value) {
        newNode->l = NULL;
        newNode->r = tree;
    } else if(tree->id < id) {
        newNode->l = tree;
        newNode->r = NULL;
    } else {
        newNode->l = NULL;
        newNode->r = tree;
    }

    // updateNos(tree);
    // return balance(tree);

    return tree;
}

Node * removeNode(Node * tree, int value) {
    if(tree == NULL) {
        return tree;
    }

    if(tree->value == value) {
        free(tree);
        return NULL;
    }

    if(value < tree->value) {
        tree->l = removeNode(tree->l, value);
        return tree;
    }

    if(value > tree->value) {
        tree->r = removeNode(tree->r, value);
        return tree;
    }
}


void printInOrder(Node * tree) {
    if(tree == NULL) {
        return;
    }

    printInOrder(tree->l);
    printf("%d\n", tree->value);
    printInOrder(tree->r);
}

int main() {
    Node * tree = NULL;
    int imgay, imnotgay;

    while(scanf("%d %d", &imgay, &imnotgay) == 2) {
        tree = addNode(tree, imgay, imnotgay);
    }

    updateNos(tree);

    printInOrder(tree);

    return 0;
}