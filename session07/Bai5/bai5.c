#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

// Cau truc phan tu trong hang doi uu tien
typedef struct {
    int priority; // Muc do uu tien
    char data[100]; // Du lieu phan tu
} Element;

// Cau truc hang doi uu tien
typedef struct {
    Element array[MAX];
    int front;
    int rear;
} Queue;

// Khoi tao hang doi uu tien rong
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
    return queue->rear == MAX - 1;
}

// Them phan tu vao hang doi uu tien (enqueue)
void enqueue(Queue *queue, int priority, const char *data) {
    if (isFull(queue)) {
        printf("Hang doi day.\n");
        return;
    }
    // Cap nhat rear neu hang doi dang rong
    if (isEmpty(queue)) {
        queue->front = 0;
    }

    // Tao mot phan tu moi voi muc do uu tien va du lieu
    queue->rear++;
    queue->array[queue->rear].priority = priority;
    snprintf(queue->array[queue->rear].data, 100, "%s", data);

    // Sap xep lai phan tu trong hang doi theo muc do uu tien
    for (int i = queue->rear; i > queue->front; i--) {
        if (queue->array[i].priority < queue->array[i - 1].priority) {
            // Hoan doi vi tri cua cac phan tu
            Element temp = queue->array[i];
            queue->array[i] = queue->array[i - 1];
            queue->array[i - 1] = temp;
        }
    }

    printf("Da them '%s' (uu tien %d) vao hang doi.\n", data, priority);
}

// Lay phan tu co uu tien cao nhat ra khoi hang doi (dequeue)
void dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong.\n");
        return;
    }
    // Phan tu co uu tien cao nhat la phan tu o vi tri front
    printf("Lay ra phan tu: '%s' (uu tien %d)\n", queue->array[queue->front].data, queue->array[queue->front].priority);

    // Di chuyen cac phan tu con lai len tren
    for (int i = 0; i < queue->rear; i++) {
        queue->array[i] = queue->array[i + 1];
    }

    queue->rear--;
    if (queue->rear == -1) {
        queue->front = -1;
    }
}

// In cac phan tu trong hang doi
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong.\n");
    } else {
        printf("Cac phan tu trong hang doi: \n");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("'%s' (uu tien %d)\n", queue->array[i].data, queue->array[i].priority);
        }
    }
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    // Them cac phan tu vao hang doi uu tien
    enqueue(&queue, 2, "Task A");
    enqueue(&queue, 1, "Task B");
    enqueue(&queue, 3, "Task C");

    // In ra trang thai cua hang doi
    printf("Hang doi sau khi them cac phan tu: \n");
    printQueue(&queue);

    // Thuc hien dequeue
    dequeue(&queue);
    printf("Hang doi sau khi loai bo phan tu dau tien: \n");
    printQueue(&queue);

    // Thuc hien dequeue lan nua
    dequeue(&queue);
    printf("Hang doi sau khi loai bo phan tu dau tien: \n");
    printQueue(&queue);

    return 0;
}

