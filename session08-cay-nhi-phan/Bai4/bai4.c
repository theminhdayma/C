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

// Tinh chieu cao cua cay
int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left); 
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Duyet cay theo thu tu truoc
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d\t", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;

    // Chen cac dinh vao cay
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);

    printf("Cay duyet theo thu tu truoc (Preorder):\n");
    preorderTraversal(root);
    printf("\n");

    // Tinh chieu cao cua cay
    int treeHeight = height(root);
    printf("Chieu cao cua cay: %d\n", treeHeight);

    return 0;
}

