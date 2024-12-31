#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// Hàm tạo một nút mới
struct Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int findMax(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    int currentMax = root->key;
    if (leftMax > currentMax) {
        currentMax = leftMax;
    }
    if (rightMax > currentMax) {
        currentMax = rightMax;
    }

    return currentMax;
}

int main() {
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(20);

    int maxValue = findMax(root);
    printf("Gia tri lon nhat trong cay la: %d\n", maxValue);

    return 0;
}
