#include <stdio.h>

int countWays(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    return countWays(n - 1) + countWays(n - 2);
}

int main() {
    int n;
    
    printf("Nhap vao so buoc cau thang: ");
    scanf("%d", &n);
    
    int result = countWays(n);
    printf("So cach di len cau thang voi %d bac là: %d\n", n, result);

    return 0;
}

