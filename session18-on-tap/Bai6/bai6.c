#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

TreeNode* search(TreeNode* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void preOrder(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(TreeNode* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void deleteTree(TreeNode* root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

int main() {
    TreeNode* root = NULL;
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Them phan tu vao cay\n");
        printf("2. Tim kiem phan tu trong cay\n");
        printf("3. Duyet cay theo tien thu tu (pre-order)\n");
        printf("4. Duyet cay theo giua thu tu (in-order)\n");
        printf("5. Duyet cay theo hau thu tu (post-order)\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                TreeNode* result = search(root, value);
                if (result != NULL) {
                    printf("Gia tri %d tim thay.\n", value);
                } else {
                    printf("Gia tri %d khong ton tai.\n", value);
                }
                break;
            case 3:
                printf("Duyet cay theo tien thu tu: ");
                preOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Duyet cay theo giua thu tu: ");
                inOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Duyet cay theo hau thu tu: ");
                postOrder(root);
                printf("\n");
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 6);

    deleteTree(root);
    return 0;
}
