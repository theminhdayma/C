#include <stdio.h>
#include <stdlib.h>

#define V 4

typedef struct Node {
    int data;            
    struct Node* next;   
} Node;

// Tao mot dinh moi
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Them canh vao do thi
void addEdge(Node* arr[], int i, int j) {
    Node* newNode = createNode(j);
    newNode->next = arr[i];
    arr[i] = newNode;

    newNode = createNode(i);
    newNode->next = arr[j];
    arr[j] = newNode;
}

// In danh sach ke
void printMatrix(Node* arr[]) {
    printf("Danh sach ke:\n");
    for (int i = 0; i < V; i++) {
        printf("Dinh %d: ", i);
        Node* temp = arr[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Node* arr[V] = {NULL};

    addEdge(arr, 0, 1);
    addEdge(arr, 0, 2);
    addEdge(arr, 1, 2);
    addEdge(arr, 2, 3);

    printMatrix(arr);

    // Giai phong bo nho
    for (int i = 0; i < V; i++) {
        Node* temp = arr[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }

    return 0;
}

