#include <stdio.h>
#include <stdbool.h>

#define MAX 100 

int matrix[MAX][MAX]; 
int visited[MAX];     

// Ham them canh vao ma tran ke
void addEdge(int u, int v) {
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}

// Ham DFS de phat hien chu ky
bool dfs(int node, int parent, int V) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (matrix[node][i] == 1) { // Co canh noi node -> i
            if (!visited[i]) {
                if (dfs(i, node, V)) {
                    return true; // Tim thay chu ky
                }
            } else if (i != parent) {
                return true; // Neu dinh da tham nhung khong phai cha -> chu ky
            }
        }
    }
    return false;
}

// Ham kiem tra chu ky
bool hasCycle(int V) {
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, V)) {
                return true; 
            }
        }
    }
    return false;
}

// Ham in ma tran ke
void printMatrix(int V) {
    printf("Ma tran ke cua do thi:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V, E;

    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &V);

    printf("Nhap so canh cua do thi: ");
    scanf("%d", &E);

    // Khoi tao ma tran ke
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            matrix[i][j] = 0;
        }
    }

    // Nhap cac canh
    printf("Nhap cac canh:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // In ma tran ke
    printMatrix(V);

    // Kiem tra chu ky
    if (hasCycle(V)) {
        printf("Do thi co chu ky\n");
    } else {
        printf("Do thi khong co chu ky\n");
    }

    return 0;
}

