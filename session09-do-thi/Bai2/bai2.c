#include <stdio.h>
#include <stdlib.h>

// Ham them canh vao ma tran ke
void addEdge(int matrix[][100], int u, int v) {
    matrix[u][v] = 1;
    matrix[v][u] = 1; // Do do thi vo huong
}

// Ham in ma tran ke
void printMatrix(int matrix[][100], int V) {
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
    int matrix[100][100] = {0}; 

    // Nhap so dinh
    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &V);

    // Nhap so canh
    printf("Nhap so canh cua do thi: ");
    scanf("%d", &E);

    // Nhap danh sach cac canh
    printf("Nhap cac canh:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < V && v >= 0 && v < V) {
            addEdge(matrix, u, v); 
        } else {
            printf("Canh khong hop le: (%d, %d). Vui long nhap lai.\n", u, v);
            i--; // Nhap lai canh nay
        }
    }

    // In ma tran ke
    printMatrix(matrix, V);

    return 0;
}

