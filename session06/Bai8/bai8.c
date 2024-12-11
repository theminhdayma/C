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

// Lay phan tu ra khoi ngan xep
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack rong.\n");
        return -1; 
    } else {
        return stack->array[stack->top--];
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

// In stack
void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong.\n");
    } else {
        printf("Cac phan tu trong ngan xep: ");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d ", stack->array[i]);
        }
        printf("\n");
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
	
	printf("Ngan xep ban dau: ");
    printStack(&stack);
    
    pop(&stack);
    printf("Ngan xep sau khi loai bo phan tu tren cung\n");
    printStack(&stack);
    
    int value = peek(&stack);
    printf("Phan tu tren cung cua stack la: %d", value);
    return 0;
}

