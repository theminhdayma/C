#include <stdio.h>

#define V 100

int visited[V];
int graph[V][V];

// Duyet DFS
void DFS(int v, int n) {
    // Danh dau dinh hien tai da tham
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {   
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(i, n); 
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

    DFS(start, n);

    return 0;
}
