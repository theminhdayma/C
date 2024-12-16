#include <stdio.h>
#include <stdlib.h>

// Cau truc cua mot nut trong cay nhi phan
typedef struct Node {
    int key;
    struct Node* left, *right;
} Node;

// Ham tao mot nut moi
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Ham chen mot gia tri vao cay
Node* insert(Node* root, int key) {
    // Neu cay rong, tao nut moi
    if (root == NULL) {
        return createNode(key);
    }

    // Neu gia tri nho hon nut goc, chen vao cay con ben trai
    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    // Neu gia tri lon hon nut goc, chen vao cay con ben phai
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Ham tim kiem mot gia tri trong cay
Node* search(Node* root, int key) {
    // Neu cay rong hoac tim thay gia tri
    if (root == NULL || root->key == key) {
        return root;
    }

    // Neu gia tri nho hon nut goc, tim kiem ben trai
    if (key < root->key) {
        return search(root->left, key);
    }
    // Neu gia tri lon hon nut goc, tim kiem ben phai
    return search(root->right, key);
}

// Ham duyet cay theo thu tu inorder
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;

    // Chen cac gia tri vao cay
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    printf("Cay duyet theo thu tu inorder:\n");
    inorderTraversal(root);
    printf("\n");

    // Tim kiem gia tri trong cay
    int value = 7;
    Node* result = search(root, value);
    if (result != NULL) {
        printf("Gia tri %d ton tai trong cay.\n", value);
    } else {
        printf("Gia tri %d khong ton tai trong cay.\n", value);
    }

    value = 9;
    result = search(root, value);
    if (result != NULL) {
        printf("Gia tri %d ton tai trong cay.\n", value);
    } else {
        printf("Gia tri %d khong ton tai trong cay.\n", value);
    }

    return 0;
}

