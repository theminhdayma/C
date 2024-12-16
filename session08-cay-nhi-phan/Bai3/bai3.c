#include <stdio.h>
#include <stdlib.h>

// Cau truc cua mot nut trong cay nhi phan
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

// Duyet cay theo thu tu truoc
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d\t", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Tim kiem mot nut trong cay
Node* search(Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

int main() {
    Node* root = NULL;

    // Chen cac dinh vao cay
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 3);

    printf("Cay duyet theo thu tu truoc:\n");
    preorderTraversal(root);
    printf("\n");
    
    int value;
    printf("Nhap phan tu can tim kiem: ");
    scanf("%d", &value);

    // Tim kiem gia tri trong cay
    Node* foundNode = search(root, value);
    if (foundNode != NULL) {
        printf("Found");
    } else {
        printf(" Not Found");
    }

    return 0;
}

