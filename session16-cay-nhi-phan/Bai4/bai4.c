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

int searchValue(struct Node* root, int value) {
    if (root == NULL) {
        return 0;
    }
    if (root->key == value) {
        return 1;
    }
    return searchValue(root->left, value) || searchValue(root->right, value);
}

int main() {
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(20);

    int value;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);

    if (searchValue(root, value)) {
        printf("Gia tri %d duoc tim thay trong cay.\n", value);
    } else {
        printf("Gia tri %d khong ton tai trong cay.\n", value);
    }

    return 0;
}
