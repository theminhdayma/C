#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Cau truc hang doi
typedef struct {
    int array[MAX];
    int front;
    int rear;
} Queue;

// Khoi tao hang doi rong
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

// Them phan tu vao hang doi (enqueue)
void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Hang doi day.\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX;
        queue->array[queue->rear] = value;
        printf("Da them %d vao hang doi.\n", value);
    }
}

// Loai phan tu khoi hang doi (dequeue)
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong.\n");
        return -1;
    } else {
        int value = queue->array[queue->front];
        if (queue->front == queue->rear) {
            // Hang doi chi con 1 phan tu, dat ve trang thai rong
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX;
        }
        return value;
    }
}

// In cac phan tu trong hang doi
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong.\n");
    } else {
        printf("Cac phan tu trong hang doi: ");
        int i = queue->front;
        while (1) {
            printf("%d ", queue->array[i]);
            if (i == queue->rear) {
                break;
            }
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    Queue queue;
    initializeQueue(&queue);
    int n;

    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        enqueue(&queue, value);
    }

    printf("Hang doi ban dau: ");
    printQueue(&queue);

    dequeue(&queue);
    printf("Hang doi sau khi loai bo phan tu dau tien: \n");
    printQueue(&queue);


    return 0;
}
