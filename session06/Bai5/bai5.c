#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    }
}

// Lay phan tu tu ngan xep
char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong.\n");
        return ; 
    } else {
        return stack->array[stack->top--];
    }
}

int main() {
    Stack stack;
    initializeStack(&stack);
    char input[MAX];
    char reversed[MAX];
    
    printf("Nhap chuoi: ");
    fgets(input, MAX, stdin);

    // Dua tung ki tu vao ngan xep
    for (int i = 0; i < strlen(input); i++) {
        push(&stack, input[i]);
    }

    int i = 0;
    while (!isEmpty(&stack)) {
        reversed[i++] = pop(&stack);
    }
    
    printf("Chuoi sau khi dao nguoc: %s", reversed);

    return 0;
}

