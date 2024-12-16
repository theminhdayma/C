#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 1000000 

// Ham tim dinh co khoang cach ngan nhat chua duoc duyet
int minDistance(int dist[], int visited[], int V) {
    int min = INF, minIndex;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Thuat toan Dijkstra de tim duong di ngan nhat
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int V, int start) {
    int dist[MAX_VERTICES];  // Mang luu khoang cach ngan nhat
    int visited[MAX_VERTICES];  // Mang danh dau cac dinh da tham
    int i, j;

    // Khoi tao mang khoang cach va mang da tham
    for (i = 0; i < V; i++) {
        dist[i] = INF;  // Ban dau cho tat ca cac khoang cach la vo cung
        visited[i] = 0;  // Ban dau chua tham dinh nao
    }

    dist[start] = 0;  // Khoang cach tu dinh nguon den chinh no la 0

    // Tim duong di ngan nhat cho tat ca cac dinh
    for (i = 0; i < V - 1; i++) {
        // Lay dinh co khoang cach ngan nhat chua duoc tham
        int u = minDistance(dist, visited, V);

        // Danh dau dinh u la da tham
        visited[u] = 1;

        // Cap nhat khoang cach cua cac dinh k
        for (j = 0; j < V; j++) {
            // Neu co canh tu u den j va j chua tham
            // Cap nhat khoang cach neu tim duoc duong di ngan hon
            if (!visited[j] && graph[u][j] != INF && dist[u] != INF && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    // In ra khoang cach ngan nhat tu dinh nguon den cac dinh con lai
    printf("Khoang cach ngan nhat tu dinh %d:\n", start);
    for (i = 0; i < V; i++) {
        if (dist[i] == INF) {
            printf("Dinh %d: Khong the toi duoc\n", i);
        } else {
            printf("Dinh %d: %d\n", i, dist[i]);
        }
    }
}

int main() {
    int V, E;
    printf("Nhap so dinh: ");
    scanf("%d", &V);
    printf("Nhap so canh: ");
    scanf("%d", &E);

    int graph[MAX_VERTICES][MAX_VERTICES];

    // Khoi tao ma tran ke voi gia tri vo cung (INF) cho cac cap dinh khong co canh
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                graph[i][j] = 0;  // Khoang cach tu dinh den chinh no la 0
            } else {
                graph[i][j] = INF;  // Khong co canh giua cac dinh khac
            }
        }
    }

    // Nhap cac canh va trong so
    printf("Nhap cac canh va trong so (dinh1 dinh2 trongso):\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;  // Vi do thi vo huong
    }

    int start;
    printf("Nhap dinh nguon: ");
    scanf("%d", &start);

    // Goi ham Dijkstra
    dijkstra(graph, V, start);

    return 0;
}

