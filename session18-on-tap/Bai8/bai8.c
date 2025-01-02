#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

Node *adjList[MAX];
int visited[MAX];

void addEdge(int u, int v) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = u;
    newNode->next = adjList[v];
    adjList[v] = newNode; 
}

// BFS
void BFS(int start, int n) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS: ");
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        Node *temp = adjList[current];
        while (temp) {
            int v = temp->vertex;
            if (!visited[v]) {
                queue[rear++] = v;
                visited[v] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// DFS
void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    Node *temp = adjList[v];
    while (temp) {
        int u = temp->vertex;
        if (!visited[u]) {
            DFS(u);
        }
        temp = temp->next;
    }
}

int main() {
    int n, edges;

    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &n);

    printf("Nhap so canh cua do thi: ");
    scanf("%d", &edges);

    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }

    printf("Nhap cac canh (dinh u, dinh v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // BFS
    for (int i = 0; i < n; i++) visited[i] = 0; 
    BFS(0, n);

    // DFS
    printf("DFS: ");
    for (int i = 0; i < n; i++) visited[i] = 0;
    DFS(0);
    printf("\n");

    return 0;
}
