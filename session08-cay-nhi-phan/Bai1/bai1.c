#include <stdio.h>
#include <stdlib.h>

// Cau truc cua mot nut trong cay nhi phan tim kiem
typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// Tao mot nut moi
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Them mot nut vao cay
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

// Duyet cay theo thu tu (In-order traversal)
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d \t", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Duyet cay theo thu tu (In-order traversal)
void inoderTraversal(Node* root) {
    if (root != NULL) {
        preorderTraversal(root->left);
        printf("%d \t", root->key);
        preorderTraversal(root->right);
    }
}
// Duyet cay theo thu tu (Postorder traversal)
void postoderTraversal(Node* root) {
    if (root != NULL) {
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        printf("%d \t", root->key);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 3);
    printf("\nDuyet truoc: ");
    preorderTraversal(root);
    printf("\nDuyet giua: ");
    inoderTraversal(root);
    printf("\nDuyet sau: ");
    postoderTraversal(root);
    return 0;
}
