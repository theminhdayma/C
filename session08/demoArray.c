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
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Tim nut co gia tri nho nhat trong cay
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Xoa mot nut trong cay
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Nut can xoa duoc tim thay
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Nut co 2 con
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
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
    int choice, value;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Them mot nut vao cay\n");
        printf("2. Duyet cay theo thu tu\n");
        printf("3. Tim kiem mot nut\n");
        printf("4. Xoa mot nut\n");
        printf("5. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri nut can them: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Cac nut trong cay theo thu tu: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                Node* found = search(root, value);
                if (found != NULL) {
                    printf("Tim thay nut co gia tri %d trong cay.\n", value);
                } else {
                    printf("Khong tim thay nut co gia tri %d trong cay.\n", value);
                }
                break;

            case 4:
                printf("Nhap gia tri nut can xoa: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 5:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 5);

    return 0;
}

