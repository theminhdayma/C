#include <stdio.h>
#include <stdlib.h>

// Cau truc danh sach ke
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int V;
    Node** adjList;
} Graph;

// Ham tao do thi
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjList = (Node**)malloc(V * sizeof(Node*)); // Cap phat cho danh sach ke

    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Ham them canh vao do thi (danh cho do thi vo huong)
void addEdge(Graph* graph, int i, int j) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = j;
    newNode->next = graph->adjList[i];
    graph->adjList[i] = newNode;

    // Do thi vo huong, them canh nguoc lai
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = i;
    newNode->next = graph->adjList[j];
    graph->adjList[j] = newNode;
}

// Ham tinh bac cua moi dinh
void calculateDegrees(Graph* graph) {
    int* degree = (int*)malloc(graph->V * sizeof(int));  // Mang bac dong

    // Khoi tao mang bac
    for (int i = 0; i < graph->V; i++) {
        degree[i] = 0;
    }

    // Tinh bac cua moi dinh
    for (int i = 0; i < graph->V; i++) {
        Node* temp = graph->adjList[i];
        while (temp) {
            degree[i]++;
            temp = temp->next;
        }
    }

    // Hien thi bac cua cac dinh
    printf("Bac cua cac dinh:\n");
    for (int i = 0; i < graph->V; i++) {
        printf("Dinh %d: %d\n", i, degree[i]);
    }

    // Tim dinh co bac cao nhat
    int maxDegree = degree[0];
    int maxVertex = 0;
    for (int i = 1; i < graph->V; i++) {
        if (degree[i] > maxDegree) {
            maxDegree = degree[i];
            maxVertex = i;
        }
    }

    printf("Dinh co bac cao nhat la: %d\n", maxVertex);

    // Giai phong bo nho mang bac
    free(degree);
}

// Ham giai phong bo nho
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        Node* temp = graph->adjList[i];
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph->adjList);
    free(graph);
}

int main() {
    int V, E;

    printf("Nhap so dinh: ");
    scanf("%d", &V);
    printf("Nhap so canh: ");
    scanf("%d", &E);

    Graph* graph = createGraph(V);

    printf("Nhap cac canh (i j):\n");
    for (int i = 0; i < E; i++) {
        int i, j;
        scanf("%d %d", &i, &j);
        addEdge(graph, i, j);
    }

    calculateDegrees(graph);

    // Giai phong bo nho
    freeGraph(graph);

    return 0;
}


