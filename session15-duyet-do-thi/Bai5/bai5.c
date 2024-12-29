#include <stdio.h>
#include <stdlib.h>

#define V 100

int graph[V][V]; 
int visited[V];
int stack[V];    

// kiem tra chu trinh
int isCyclicDFS(int v, int n) {
    visited[v] = 1;  
    stack[v] = 1;  

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1) {
            if (!visited[i] && isCyclicDFS(i, n)) {
                return 1; 
            } else if (stack[i]) {
                return 1; 
            }
        }
    }

    stack[v] = 0;
    return 0;
}

// Ham kiem tra chu trinh trong do thi
int hasCycle(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) { 
            if (isCyclicDFS(i, n)) {
                return 1; 
            }
        }
    }
    return 0; 
}

int main() {
    int v, e;

    printf("Nhap so dinh: ");
    scanf("%d", &v);

    printf("Nhap so canh: ");
    scanf("%d", &e);

    for (int i = 0; i < v; i++) {
        visited[i] = 0;
        stack[i] = 0;
        for (int j = 0; j < v; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Nhap danh sach canh (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; 
    }

    if (hasCycle(v)) {
        printf("Do thi co chu trinh\n");
    } else {
        printf("Do thi khong co chu trinh\n");
    }

    return 0;
}
