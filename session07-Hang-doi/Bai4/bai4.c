#include <stdio.h>
#include <stdlib.h>

// Cau truc node trong danh sach lien ket doi
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Cau truc hang doi bang danh sach lien ket doi
typedef struct {
    Node *front;
    Node *rear;
} Queue;

// Khoi tao hang doi rong
void initializeQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Kiem tra hang doi co rong khong
int isEmpty(Queue *queue) {
    return queue->front == NULL;
}

// Them phan tu vao hang doi (enqueue)
void enqueue(Queue *queue, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong du bo nho de cap phat.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = queue->rear;

    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    printf("Da them %d vao hang doi.\n", value);
}

// Xem phan tu dau tien cua hang doi
int peek(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong.\n");
        return -1;
    } else {
        return queue->front->data;
    }
}

int main() {
    Queue queue;
    initializeQueue(&queue);
    int value;
    
    printf("Nhap phan tu muon them: ");
    scanf("%d", &value);
    enqueue(&queue, value);
    int valueHead = peek(&queue);
    printf("Gia tri phan tu dau tien: %d", valueHead);

    return 0;
}
