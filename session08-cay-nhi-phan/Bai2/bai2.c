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

// Ham ho tro de tim cac dinh o lop 2
void printNodesAtLevel(Node* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 0) {
        // Neu day la lop mong muon, in ra gia tri
        printf("%d\t", root->key);
    } else {
        // De quy sang trai va phai voi lop giam 1
        printNodesAtLevel(root->left, level - 1);
        printNodesAtLevel(root->right, level - 1);
    }
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
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 3);

    printf("Cay duyet theo thu tu truoc (Preorder):\n");
    preorderTraversal(root);

    printf("\nCac dinh thuoc lop 2:\n");
    printNodesAtLevel(root, 2);

    return 0;
}

