#include <stdio.h>
#include <stdlib.h>

#define V 100

int graph[V][V];
int visited[V];

void initGraph(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1; 
}

void removeEdge(int u, int v) {
    graph[u][v] = 0;
    graph[v][u] = 0;
}

// BFS
void BFS(int start, int n) {
    int queue[V], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    printf("Ket qua duyet BFS: ");
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

// DFS
void DFS(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(i, n);
        }
    }
}

// in
void printGraph(int n) {
    printf("Ma tran ke cua do thi:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, choice, u, v, start;

    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &n);

    initGraph(n);

    do {
        printf("\nMenu:\n");
        printf("1. Them canh\n");
        printf("2. Xoa canh\n");
        printf("3. Duyet BFS\n");
        printf("4. Duyet DFS\n");
        printf("5. In ma tran ke\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap dinh u va v de them canh (u v): ");
            scanf("%d %d", &u, &v);
            addEdge(u, v);
            printf("Da them canh (%d, %d).\n", u, v);
            break;
        case 2:
            printf("Nhap dinh u va v de xoa canh (u v): ");
            scanf("%d %d", &u, &v);
            removeEdge(u, v);
            printf("Da xoa canh (%d, %d).\n", u, v);
            break;
        case 3:
            printf("Nhap dinh bat dau: ");
            scanf("%d", &start);
            for (int i = 0; i < n; i++) visited[i] = 0;
            BFS(start, n);
            break;
        case 4:
            printf("Nhap dinh bat dau: ");
            scanf("%d", &start);
            for (int i = 0; i < n; i++) visited[i] = 0;
            printf("Ket qua duyet DFS: ");
            DFS(start, n);
            printf("\n");
            break;
        case 5:
            printGraph(n);
            break;
        case 6:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 6);

    return 0;
}
