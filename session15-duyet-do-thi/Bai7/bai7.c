#include <stdio.h>

#define V 100

int graph[V][V]; 
int visited[V];  

// Duyet DFS
void DFS(int v, int n) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            DFS(i, n);
        }
    }
}

// Ham kiem tra do thi lien thong
int isConnected(int n) {
    int a = 0;
    DFS(a, n);

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int v, e;

    printf("Nhap so dinh: ");
    scanf("%d", &v);

    printf("Nhap so canh: ");
    scanf("%d", &e);

    for (int i = 0; i < v; i++) {
        visited[i] = 0;
        for (int j = 0; j < v; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Nhap danh sach canh (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    if (isConnected(v)) {
        printf("Do thi lien thong\n");
    } else {
        printf("Do thi khong lien thong\n");
    }

    return 0;
}
