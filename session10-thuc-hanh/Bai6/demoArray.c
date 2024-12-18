#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 4 // Số đỉnh của đồ thị

// Thêm cạnh vào đồ thị
void addEdge(int matrix[V][V], int i, int j) {
    matrix[i][j] = 1; // Đồ thị có hướng
    matrix[j][i] = 1; // Nếu là đồ thị không hướng, thêm cạnh ngược lại
}

// Hiển thị ma trận kề
void printMatrix(int matrix[V][V]) {
    printf("Ma trận kề của đồ thị:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Thuật toán DFS (đệ quy)
void DFSUtil(int matrix[V][V], int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < V; i++) {
        if (matrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(matrix, i, visited);
        }
    }
}

void DFS(int matrix[V][V], int startVertex) {
    bool visited[V] = {false};
    printf("Duyệt DFS bắt đầu từ đỉnh %d: ", startVertex);
    DFSUtil(matrix, startVertex, visited);
    printf("\n");
}

// Thuật toán BFS (sử dụng hàng đợi)
void BFS(int matrix[V][V], int startVertex) {
    bool visited[V] = {false};
    int queue[V], front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("Duyệt BFS bắt đầu từ đỉnh %d: ", startVertex);
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < V; i++) {
            if (matrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int matrix[V][V] = {0};

    // Thêm các cạnh
    addEdge(matrix, 0, 1);
    addEdge(matrix, 0, 2);
    addEdge(matrix, 1, 2);
    addEdge(matrix, 2, 3);

    // Hiển thị ma trận kề
    printMatrix(matrix);

    // Duyệt đồ thị
    DFS(matrix, 0); // Duyệt DFS từ đỉnh 0
    BFS(matrix, 0); // Duyệt BFS từ đỉnh 0

    return 0;
}
