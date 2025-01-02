#include <stdio.h>
#define MAX 100

typedef struct Stack {
    int data[MAX]; 
    int top;
} Stack;

// Ham khoi tao ngan xep
void initStack(Stack *stack) {
    stack->top = -1; 
}

// Ham kiem tra ngan xep co rong khong
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Ham kiem tra ngan xep co day khong
int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

// Push
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Ngan xep day, khong the them phan tu.\n");
        return;
    }
    stack->data[++stack->top] = value;
    printf("Da them phan tu %d vao ngan xep.\n", value);
}

// Pop
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong, khong the lay phan tu.\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Peek
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong, khong co phan tu tren dinh.\n");
        return -1;
    }
    return stack->data[stack->top];
}

// Ham hien thi 
void displayStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong.\n");
        return;
    }
    printf("Cac phan tu trong ngan xep: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Them phan tu vao ngan xep (push)\n");
        printf("2. Lay va xoa phan tu khoi ngan xep (pop)\n");
        printf("3. Kiem tra phan tu tren dinh ngan xep (peek)\n");
        printf("4. Kiem tra ngan xep co rong khong\n");
        printf("5. Kiem tra ngan xep co day khong\n");
        printf("6. Hien thi cac phan tu trong ngan xep\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap gia tri can them: ");
            scanf("%d", &value);
            push(&stack, value);
            break;
        case 2:
            value = pop(&stack);
            if (value != -1) {
                printf("Da lay phan tu %d ra khoi ngan xep.\n", value);
            }
            break;
        case 3:
            value = peek(&stack);
            if (value != -1) {
                printf("Phan tu tren dinh ngan xep la: %d\n", value);
            }
            break;
        case 4:
            if (isEmpty(&stack)) {
                printf("Ngan xep rong.\n");
            } else {
                printf("Ngan xep khong rong.\n");
            }
            break;
        case 5:
            if (isFull(&stack)) {
                printf("Ngan xep day.\n");
            } else {
                printf("Ngan xep chua day.\n");
            }
            break;
        case 6:
            displayStack(&stack);
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
