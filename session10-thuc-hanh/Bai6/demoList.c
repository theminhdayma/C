#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Tạo một đỉnh mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Thêm cạnh vào đồ thị
void addEdge(Node* graph[], int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;

    // Nếu là đồ thị không hướng, thêm cạnh ngược lại
    newNode = createNode(src);
    newNode->next = graph[dest];
    graph[dest] = newNode;
}

// Hiển thị danh sách kề
void printGraph(Node* graph[], int vertices) {
    printf("Danh sách kề của đồ thị:\n");
    for (int i = 0; i < vertices; i++) {
        printf("Đỉnh %d: ", i);
        Node* temp = graph[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Thuật toán DFS (đệ quy)
void DFSUtil(Node* graph[], int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    Node* temp = graph[vertex];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            DFSUtil(graph, temp->data, visited);
        }
        temp = temp->next;
    }
}

void DFS(Node* graph[], int startVertex, int vertices) {
    bool visited[MAX_VERTICES] = {false};
    printf("Duyệt DFS bắt đầu từ đỉnh %d: ", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

// Thuật toán BFS (sử dụng hàng đợi)
void BFS(Node* graph[], int startVertex, int vertices) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES], front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("Duyệt BFS bắt đầu từ đỉnh %d: ", startVertex);
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        Node* temp = graph[currentVertex];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                visited[temp->data] = true;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    int vertices, edges, src, dest, startVertex;
    printf("Nhập số đỉnh: ");
    scanf("%d", &vertices);

    Node* graph[MAX_VERTICES] = {NULL};

    printf("Nhập số cạnh: ");
    scanf("%d", &edges);

    printf("Nhập các cạnh (đỉnh nguồn, đỉnh đích):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printGraph(graph, vertices);

    printf("Nhập đỉnh bắt đầu duyệt DFS: ");
    scanf("%d", &startVertex);
    DFS(graph, startVertex, vertices);

    printf("Nhập đỉnh bắt đầu duyệt BFS: ");
    scanf("%d", &startVertex);
    BFS(graph, startVertex, vertices);

    // Giải phóng bộ nhớ
    for (int i = 0; i < vertices; i++) {
        Node* temp = graph[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }

    return 0;
}
