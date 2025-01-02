#include <stdio.h>
#define MAX 100 

// Cấu trúc hàng đợi
typedef struct Queue {
    int data[MAX];
    int front;
    int rear; 
} Queue;

// Hàm khởi tạo hàng đợi
void initQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Hàm kiểm tra hàng đợi có rỗng không
int isEmpty(Queue *queue) {
    return queue->front == -1;
}

// Hàm kiểm tra hàng đợi có đầy không
int isFull(Queue *queue) {
    return queue->rear == MAX - 1;
}

// enqueue
void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Hang doi day, khong the them phan tu.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->data[++queue->rear] = value;
    printf("Da them phan tu %d vao hang doi.\n", value);
}

// dequeue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong, khong the lay phan tu.\n");
        return -1;
    }
    int value = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return value;
}

// peek
int peek(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong, khong co phan tu o dau.\n");
        return -1;
    }
    return queue->data[queue->front];
}

// Ham hien thi
void displayQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong.\n");
        return;
    }
    printf("Cac phan tu trong hang doi: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main() {
    Queue queue;
    initQueue(&queue);
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Them phan tu vao hang doi (enqueue)\n");
        printf("2. Lay va loai bo phan tu o dau hang doi (dequeue)\n");
        printf("3. Kiem tra phan tu o dau hang doi (peek)\n");
        printf("4. Kiem tra hang doi co rong khong\n");
        printf("5. Kiem tra hang doi co day khong\n");
        printf("6. Hien thi cac phan tu trong hang doi\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap gia tri can them: ");
            scanf("%d", &value);
            enqueue(&queue, value);
            break;
        case 2:
            value = dequeue(&queue);
            if (value != -1) {
                printf("Da lay phan tu %d ra khoi hang doi.\n", value);
            }
            break;
        case 3:
            value = peek(&queue);
            if (value != -1) {
                printf("Phan tu o dau hang doi la: %d\n", value);
            }
            break;
        case 4:
            if (isEmpty(&queue)) {
                printf("Hang doi rong.\n");
            } else {
                printf("Hang doi khong rong.\n");
            }
            break;
        case 5:
            if (isFull(&queue)) {
                printf("Hang doi day.\n");
            } else {
                printf("Hang doi chua day.\n");
            }
            break;
        case 6:
            displayQueue(&queue);
            break;
        case 7:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
        }
    } while (choice != 7);

    return 0;
}
