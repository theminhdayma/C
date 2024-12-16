#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Cau truc ngan xep
typedef struct {
	int array[MAX];
	int top;
} Stack;

//Khoi tao stack rong
void initializeStack(Stack *stack) {
    stack->top = -1;
}

// Kiem tra stack co rong khong
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

//  Kiem tra stack co day khong
int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

// Them phan tu vao stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack day.\n");
    } else {
        stack->array[++stack->top] = value;
        printf("Da them %d vao ngan xep.\n", value);
    }
}

// Xem phan tu tren cung cua stack
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong.\n");
        return -1;
    } else {
        return stack->array[stack->top];
    }
}

int main() {
	Stack stack;
    initializeStack(&stack);
    int n;

    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        push(&stack, value);
    }
    
    int value = peek(&stack);
    printf("Phan tu tren cung cua stack la: %d", value);
    return 0;
}

