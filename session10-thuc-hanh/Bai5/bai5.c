#include <stdio.h>
#include <stdlib.h>

// Cấu trúc của một nút trong cây nhị phân tìm kiếm
typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// Tạo một nút mới
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Thêm một nút vào cây
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

// Duyệt cây theo thứ tự trước (Preorder traversal)
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d \t", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Duyệt cây theo thứ tự giữa (Inorder traversal)
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d \t", root->key);
        inorderTraversal(root->right);
    }
}

// Duyệt cây theo thứ tự sau (Postorder traversal)
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d \t", root->key);
    }
}

// Tìm nút có giá trị nhỏ nhất trong cây
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Xóa một nút trong cây
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Nút cần xóa được tìm thấy
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Nút có 2 con
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

// Tìm kiếm một nút trong cây
Node* search(Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Giải phóng toàn bộ cây
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Thêm một nút vào cây\n");
        printf("2. Duyệt cây (Preorder, Inorder, Postorder)\n");
        printf("3. Tìm kiếm một nút\n");
        printf("4. Xóa một nút\n");
        printf("5. Thoát\n");
        printf("Lựa chọn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhập giá trị nút cần thêm: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                if (root == NULL) {
                    printf("Cây hiện tại rỗng.\n");
                } else {
                    printf("Duyệt cây Preorder: ");
                    preorderTraversal(root);
                    printf("\nDuyệt cây Inorder: ");
                    inorderTraversal(root);
                    printf("\nDuyệt cây Postorder: ");
                    postorderTraversal(root);
                    printf("\n");
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("Cây hiện tại rỗng.\n");
                } else {
                    printf("Nhập giá trị cần tìm: ");
                    scanf("%d", &value);
                    Node* found = search(root, value);
                    if (found != NULL) {
                        printf("Tìm thấy nút có giá trị %d trong cây.\n", value);
                    } else {
                        printf("Không tìm thấy nút có giá trị %d trong cây.\n", value);
                    }
                }
                break;

            case 4:
                if (root == NULL) {
                    printf("Cây hiện tại rỗng.\n");
                } else {
                    printf("Nhập giá trị nút cần xóa: ");
                    scanf("%d", &value);
                    root = deleteNode(root, value);
                }
                break;

            case 5:
                printf("Giải phóng bộ nhớ và thoát chương trình.\n");
                freeTree(root);
                break;

            default:
                printf("Lựa chọn không hợp lệ.\n");
        }
    } while (choice != 5);

    return 0;
}
