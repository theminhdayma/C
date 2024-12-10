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

//Kiem tra bieu thuc
int isValidExpression(const char *expression) {
    Stack stack;
    initializeStack(&stack);

    for (int i = 0; i < strlen(expression); i++) {
        char current = expression[i];

        if (current == '(' || current == '{' || current == '[') {
            push(&stack, current); 
        } else if (current == ')' || current == '}' || current == ']') {
            if (isEmpty(&stack)) {
                return 0;
            }
            char top = pop(&stack);
            if ((top == '(' && current != ')') ||
                (top == '{' && current != '}') ||
                (top == '[' && current != ']')) {
                return 0; 
            }
        }
    }

    return isEmpty(&stack); 
}

int main() {
    char expression[MAX];

    printf("Nhap bieu thuc: ");
    fgets(expression, MAX, stdin);
    expression[strcspn(expression, "\n")] = '\0'; \

    if (isValidExpression(expression)) {
        printf("Bieu thuc hop le");
    } else {
        printf("Bieu thuc khong hop le");
    }

    return 0;
}

