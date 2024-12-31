#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//Ham kiem tra
int isIdentical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }

    if (root1 == NULL || root2 == NULL) {
        return 0;
    }

    if (root1->key == root2->key &&
        isIdentical(root1->left, root2->left) &&
        isIdentical(root1->right, root2->right)) {
        return 1;
    }

    return 0;
}

int main() {
    Node* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);

    Node* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->left = createNode(4);
    root2->left->right = createNode(5);

    Node* root3 = createNode(1);
    root3->left = createNode(2);
    root3->right = createNode(3);
    root3->left->left = createNode(6);
    root3->left->right = createNode(5);

    if (isIdentical(root1, root2)) {
        printf("Cay 1 va Cay 2 giong het nhau.\n");
    } else {
        printf("Cay 1 va Cay 2 khong giong nhau.\n");
    }

    if (isIdentical(root1, root3)) {
        printf("Cay 1 va Cay 3 giong het nhau.\n");
    } else {
        printf("Cay 1 va Cay 3 khong giong nhau.\n");
    }

    return 0;
}
