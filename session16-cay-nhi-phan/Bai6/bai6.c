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

Node* insert(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Ham kiem tra
int countNodesGreaterThanX(Node* root, int X) {
    if (root == NULL) {
        return 0;
    }

    int count = 0;
    if (root->key > X) {
        count = 1;
    }

    count += countNodesGreaterThanX(root->left, X);
    count += countNodesGreaterThanX(root->right, X);

    return count;
}

int main() {
    Node* root = NULL; 
    int n, value, X;

    printf("Nhap so luong nut trong cay: ");
    scanf("%d", &n);

    printf("Nhap gia tri cac nut:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value); 
    }

    printf("Nhap gia tri X: ");
    scanf("%d", &X);

    int count = countNodesGreaterThanX(root, X);
    printf("So nut co gia tri lon hon %d la: %d\n", X, count);

    return 0;
}
