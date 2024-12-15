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

// Ham kiem tra xem cay co phai la BST hay khong
int isBSTUtil(Node* root, int min, int max) {
    if (root == NULL) {
        return 1; // Cay rong la BST
    }

    // Kiem tra gia tri cua nut hien tai
    if (root->key <= min || root->key >= max) {
        return 0; // Vi pham quy tac BST
    }

    // Kiem tra tai cac cay con ben trai va ben phai
    return isBSTUtil(root->left, min, root->key) && isBSTUtil(root->right, root->key, max);
}

// Ham kiem tra xem cay co phai la BST hay khong
int isBST(Node* root) {
    return isBSTUtil(root, -100000, 100000); // Su dung gia tri toi thieu va toi da cho min va max
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
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    printf("Cay duyet theo thu tu inorder:\n");
    inorderTraversal(root);

    // Kiem tra xem cay co phai la BST hay khong
    if (isBST(root)) {
        printf("Cay la cay nhi phan tim kiem (BST).\n");
    } else {
        printf("Cay khong phai la cay nhi phan tim kiem (BST).\n");
    }

    return 0;
}

