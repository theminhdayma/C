#include <stdio.h>

int recursive_sum(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n - 1] + recursive_sum(arr, n - 1);
}

int main() {
    int n;
    
    printf("Nhap n: ");
    scanf("%d", &n);

    int arr[n];
    
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    
    int sum = recursive_sum(arr, n);
    
    printf("Tong cac phan tu trong mang la: %d\n", sum);
}

