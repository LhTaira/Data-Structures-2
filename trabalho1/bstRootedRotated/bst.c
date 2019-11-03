#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node * left;
    struct Node * right;
} Node;

Node * rotateLeft(Node * grandParent) {
	Node * temp = grandParent->right;
	grandParent->right = temp->left;
	temp->left = grandParent;
	return temp;
}

Node * rotateRight(Node * grandParent) {
	Node * temp = grandParent->left;
	grandParent->left = temp->right;
	temp->right = grandParent;
	return temp;
}

Node * createTree(int value) {
    Node * newTree = malloc(sizeof(Node));
    newTree->value = value;
    newTree->left = NULL;
    newTree->right = NULL;
    return newTree;
}

Node * insertAtRoot(Node * tree, int value) {
    if(tree == NULL) {
        return createTree(value);
    }
    if(value < tree->value) {
        tree->left = insertAtRoot(tree->left, value);
        return rotateRight(tree);
    }
    if(value > tree->value) {
        tree->right = insertAtRoot(tree->right, value);
        return rotateLeft(tree);
    }
    return tree;
}

void printInOrder(Node * tree, Node * root) {
    if(tree == NULL) {
        return;
    }
    printInOrder(tree->left, root);
    if(tree == root) {
        printf("*%d ", tree->value);
    } else {
        printf("%d ", tree->value);
    }
    printInOrder(tree->right, root);
}

int main() {
    Node * tree = NULL;
    int aux;

    while(scanf("%d", &aux) == 1) {
        tree = insertAtRoot(tree, aux);
        printInOrder(tree, tree);
        printf(".\n");
    }

}