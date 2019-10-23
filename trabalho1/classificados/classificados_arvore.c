#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node * l;
    struct Node * r;
} Node;

Node * createTree(int value) {
    Node * tree = malloc(sizeof(Node));

    tree->l = NULL;
    tree->r = NULL;
    tree->value = value;

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

Node * partR(Node * node, int k) {

    int t = (h->l == NULL) ? 0: h->l->value;

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

Node * balance(Node * tree) {
    if(h->value < 2) {
        return h;
    }

    h = partR(h, h->n/2);
    h->l = balance(h->l);
    h->r = balance(h->r);
    return h;
}

int * selectR(Node * h, int k) {
    if(h == NULL) {
        return NULL;
    }

    int t = (h->l == NULL) ? 0: h->l->value;

    if(t > k) {
        return selectR(h-l, k);
    }

    if(t < k) {
        return selectR(h->r, k-t-1);
    }
    int * temp = malloc(sizeof(int));
    *temp = h->value ;
    return temp;
}

Node * addNode(Node * tree, int value) {
    if(tree == NULL) {
        return createTree(value);
    }

    Node * newNode = malloc(sizeof(Node));
    
    newNode->value = value;

    if(tree->value < value) {
        newNode->l = tree;
        newNode->r = NULL;
    } else {
        newNode->l = NULL;
        newNode->r = tree;
    }

    return balance(tree);
}

Node * removeNode(Node * tree; int value) {
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

int main() {
    Node * tree = NULL;


}