#include <stdio.h>

#define V 100

int visited[V];
int graph[V][V];

// Duyet BFS
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
}

int main() {
    int n, start, edges;

    printf("Nhap vao so dinh cua do thi: ");
    scanf("%d", &n);

    printf("Nhap cac canh: ");
    scanf("%d", &edges);

    printf("Nhap canh(u v): \n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; 
        graph[v][u] = 1;
    }

    printf("Nhap vao dinh bat dau duyet: ");
    scanf("%d", &start);

    printf("Ket qua duyet BFS bat dau tu dinh %d:\n", start);
    BFS(start, n);

    return 0;
}
