#include <stdio.h>

int fibonacci(int a) {
    if (a == 0) return 0;
    if (a == 1) return 1;
    return fibonacci(a - 1) + fibonacci(a - 2);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

	if (n < 0) {
        printf("Gia tri n khong hop le.\n");
        return 1;
    }
    
    printf("Day so Fibonacci: ");
    for (int i = 0; i < n; i++) {
        printf("%d, ", fibonacci(i));
    }
}

