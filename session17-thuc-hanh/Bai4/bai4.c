#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

typedef struct Graph {
    int vertices;
    int adjacencyMatrix[MAX][MAX];
} Graph;

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

Node* createBinaryTree(int n) {
    Node* root = NULL;
    for (int i = 1; i <= n; i++) {
        root = insert(root, i);
    }
    return root;
}

//Pre-order
void preOrder(Node* root) {
    if (root != NULL) {
        root->key;  
        preOrder(root->left);
        preOrder(root->right);
    }
}

//In-order
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        root->key; 
        inOrder(root->right);
    }
}

//Post-order
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        root->key;  
    }
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1;
}

void createRandomGraph(Graph* graph, int edges) {
    srand(time(NULL));
    for (int i = 0; i < edges; i++) {
        int src = rand() % graph->vertices;
        int dest = rand() % graph->vertices;
        if (src != dest) {
            addEdge(graph, src, dest);
        }
    }
}

//DFS
void DFS(Graph* graph, int start, int visited[]) {
    visited[start] = 1;
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjacencyMatrix[start][i] && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

//BFS
void BFS(Graph* graph, int start, int visited[]) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjacencyMatrix[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

// Ham do thoi gian
double measureTime(void (*func)(void*), void* arg) {
    clock_t start = clock();
    func(arg);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

void callPreOrder(void* arg) { preOrder((Node*)arg); }
void callInOrder(void* arg) { inOrder((Node*)arg); }
void callPostOrder(void* arg) { postOrder((Node*)arg); }

void callDFS(void* arg) {
    Graph* graph = ((Graph**)arg)[0];
    int start = *((int*)(((Graph**)arg)[1]));
    int visited[MAX] = {0};
    DFS(graph, start, visited);
}
void callBFS(void* arg) {
    Graph* graph = ((Graph**)arg)[0];
    int start = *((int*)(((Graph**)arg)[1]));
    int visited[MAX] = {0};
    BFS(graph, start, visited);
}

int main() {
    int n = 100;
    int edges = 200;

    Node* root = createBinaryTree(n);

    Graph* graph = createGraph(n);
    createRandomGraph(graph, edges);

    printf("Duyet cay:\n");
    printf("Pre-order: %.6f giay\n", measureTime(callPreOrder, root));
    printf("In-order: %.6f giay\n", measureTime(callInOrder, root));
    printf("Post-order: %.6f giay\n", measureTime(callPostOrder, root));

    printf("Duyet do thi:\n");
    int start = 0;
    void* dfsArgs[2] = {graph, &start};
    printf("DFS: %.6f giay\n", measureTime(callDFS, dfsArgs));
    printf("BFS: %.6f giay\n", measureTime(callBFS, dfsArgs));

    return 0;
}
