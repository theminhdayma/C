#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

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

// Lam sach cau
void cleanString(const char *input, char *cleaned) {
    int j = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (isalnum(input[i])) {
            cleaned[j++] = tolower(input[i]); 
        }
    }
    cleaned[j] = '\0'; 
}

// Kiem tra doi xung
int isPalindrome(const char *input) {
    Stack stack;
    initializeStack(&stack);

    char cleaned[MAX];
    cleanString(input, cleaned);
    int length = strlen(cleaned);

    // Day nua cau vao stack
    for (int i = 0; i < length / 2; i++) {
        push(&stack, cleaned[i]);
    }

    //Kiem tra nua sau
    for (int i = (length + 1) / 2; i < length; i++) {
        if (isEmpty(&stack) || pop(&stack) != cleaned[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[MAX];

    printf("Nhap cau: ");
    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = '\0'; 

    if (isPalindrome(input)) {
        printf("Cau nay la cau doi xung");
    } else {
        printf("Cau nay khong phai cau doi xung");
    }

    return 0;
}

