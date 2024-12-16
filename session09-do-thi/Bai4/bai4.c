#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

typedef struct Node {
    int vertex;         
    struct Node* next;  
} Node;

// Danh sach ke
typedef struct {
    Node* head; 
} AdjList;

// Do thi
typedef struct {
    int numVertices;     
    AdjList adjLists[MAX]; 
    int visited[MAX];    
} Graph;

// Tao mot do thi moi
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i].head = NULL;
        graph->visited[i] = 0; 
    }

    return graph;
}

// Tao mot nut moi
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Them canh vao do thi
void addEdge(Graph* graph, int i, int j) {
    // Them dinh j vao danh sach ke cua i
    Node* newNode = createNode(j);
    newNode->next = graph->adjLists[i].head;
    graph->adjLists[i].head = newNode;

    // Vi do thi vo huong, them i vao danh sach ke cua j
    newNode = createNode(i);
    newNode->next = graph->adjLists[j].head;
    graph->adjLists[j].head = newNode;
}

// Thuat toan BFS
void bfs(Graph* graph, int startVertex) {
    int queue[MAX]; // Hang doi
    int front = 0, rear = 0;

    // Danh dau dinh bat dau da duoc tham va dua vao hang doi
    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("Thu tu duyet BFS: ");

    while (front != rear) {
        // Lay dinh dau tien trong hang doi
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Duyet cac dinh ke
        Node* temp = graph->adjLists[currentVertex].head;
        while (temp) {
            int adjVertex = temp->vertex;

            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }

            temp = temp->next;
        }
    }

    printf("\n");
}

// Ham main
int main() {
    int vertices, edges;
    printf("Nhap so dinh: ");
    scanf("%d", &vertices);
    printf("Nhap so canh: ");
    scanf("%d", &edges);

    Graph* graph = createGraph(vertices);

    printf("Nhap cac canh:\n");
    for (int k = 0; k < edges; k++) {
        int i, j;
        scanf("%d %d", &i, &j);
        addEdge(graph, i, j);
    }

    int startVertex;
    printf("Nhap dinh bat dau: ");
    scanf("%d", &startVertex);

    bfs(graph, startVertex);

    return 0;
}

