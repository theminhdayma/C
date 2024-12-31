#include <stdio.h>
#include <stdlib.h>

#define V 100

int graph[V][V];
int visited[V];

void BFS(int start, int n) {
    int queue[V], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void DFS(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(i, n);
        }
    }
}

int main() {
    int n, edges, start;

    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &n);

    printf("Nhap so canh cua do thi: ");
    scanf("%d", &edges);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Nhap cac canh (dinh u, dinh v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Nhap dinh bat dau: ");
    scanf("%d", &start);

    for (int i = 0; i < n; i++) visited[i] = 0;
    printf("Ket qua duyet BFS: ");
    BFS(start, n);

    for (int i = 0; i < n; i++) visited[i] = 0;
    printf("Ket qua duyet DFS: ");
    DFS(start, n);
    printf("\n");

    return 0;
}
