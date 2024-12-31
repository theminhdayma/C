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

// Ham kiem tra
int findPath(Node* root, int value, int path[], int* pathLen) {
    if (root == NULL) {
        return 0; 
    }

    path[*pathLen] = root->key;
    (*pathLen)++;

    if (root->key == value) {
        return 1;
    }

    if (findPath(root->left, value, path, pathLen) || findPath(root->right, value, path, pathLen)) {
        return 1;
    }

    (*pathLen)--;
    return 0;
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int value;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);

    int path[100];
    int pathLen = 0;

    if (findPath(root, value, path, &pathLen)) {
        printf("Duong di den gia tri %d: ", value);
        for (int i = 0; i < pathLen; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        printf("Khong tim thay gia tri %d trong cay.\n", value);
    }

    return 0;
}
