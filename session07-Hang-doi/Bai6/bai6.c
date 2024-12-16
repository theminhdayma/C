#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Cau truc hang doi hai dau (Queue)
typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

// Khoi tao hang doi
void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Kiem tra hang doi co rong khong
int isEmpty(Queue *queue) {
    return queue->front == -1;
}

// Kiem tra hang doi co day khong
int isFull(Queue *queue) {
    return (queue->rear + 1) % MAX == queue->front;
}

// Them phan tu vao dau hang doi
void addFront(Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Hang doi da day.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->front = (queue->front - 1 + MAX) % MAX;
    }
    queue->arr[queue->front] = data;
    printf("Them phan tu vao dau: %d\n", data);
}

// Them phan tu vao cuoi hang doi
void addRear(Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Hang doi da day.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX;
    }
    queue->arr[queue->rear] = data;
    printf("Them phan tu vao cuoi: %d\n", data);
}

// Lay phan tu ra khoi dau hang doi
int removeFront(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong.\n");
        return -1;
    }

    int data = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1; // Hang doi rong
    } else {
        queue->front = (queue->front + 1) % MAX;
    }
    printf("Lay ra phan tu tu dau: %d\n", data);
    return data;
}

// Lay phan tu ra khoi cuoi hang doi
int removeRear(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong.\n");
        return -1;
    }

    int data = queue->arr[queue->rear];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1; // Hang doi rong
    } else {
        queue->rear = (queue->rear - 1 + MAX) % MAX;
    }
    printf("Lay ra phan tu tu cuoi: %d\n", data);
    return data;
}

// In ra trang thai hang doi hien tai
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong.\n");
        return;
    }

    printf("Hang doi hien tai: [");
    int i = queue->front;
    while (1) {
        printf("%d", queue->arr[i]);
        if (i == queue->rear) break;
        i = (i + 1) % MAX;
        printf(", ");
    }
    printf("]\n");
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    // Them phan tu vao dau, cuoi hang doi
    addFront(&queue, 10);
    addRear(&queue, 20);
    addFront(&queue, 5);
    
    // In ra trang thai hang doi
    printQueue(&queue);

    // Lay phan tu ra khoi dau, cuoi hang doi
    removeFront(&queue);
    printQueue(&queue);

    removeRear(&queue);
    printQueue(&queue);

    return 0;
}

