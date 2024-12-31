#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

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

// Duyet cay theo thu tu (Preorder traversal)
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d \t", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Duyet cay theo thu tu (In-order traversal)
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d \t", root->key);
        inorderTraversal(root->right);
    }
}

// Duyet cay theo thu tu (Postorder traversal)
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d \t", root->key);
    }
}

void convertTreeToGraph(Node* root, int adjacencyList[MAX][MAX], int size) {
    if (root != NULL) {
        int leftIndex = (root->left != NULL) ? root->left->key : -1;
        int rightIndex = (root->right != NULL) ? root->right->key : -1;

        if (leftIndex != -1) {
            adjacencyList[root->key][leftIndex] = 1;
            adjacencyList[leftIndex][root->key] = 1;
        }
        if (rightIndex != -1) {
            adjacencyList[root->key][rightIndex] = 1;
            adjacencyList[rightIndex][root->key] = 1;
        }

        convertTreeToGraph(root->left, adjacencyList, size);
        convertTreeToGraph(root->right, adjacencyList, size);
    }
}

// Hàm DFS
void DFS(int start, int visited[], int adjacencyList[MAX][MAX]) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < MAX; i++) {
        if (adjacencyList[start][i] && !visited[i]) {
            DFS(i, visited, adjacencyList);
        }
    }
}

// Hàm BFS
void BFS(int start, int visited[], int adjacencyList[MAX][MAX]) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < MAX; i++) {
            if (adjacencyList[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    printf("Duyet truoc: ");
    preorderTraversal(root);
    printf("\n");

    printf("Duyet giua: ");
    inorderTraversal(root);
    printf("\n");

    printf("Duyet sau: ");
    postorderTraversal(root);
    printf("\n");

    int adjacencyList[MAX][MAX] = {0};

    convertTreeToGraph(root, adjacencyList, MAX);

    printf("Duyet DFS: ");
    int visitedDFS[MAX] = {0};
    DFS(root->key, visitedDFS, adjacencyList);
    printf("\n");

    printf("Duyet BFS: ");
    int visitedBFS[MAX] = {0};
    BFS(root->key, visitedBFS, adjacencyList);
    printf("\n");

    return 0;
}
