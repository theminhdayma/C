#include <stdio.h>

int main() {
    int n;

    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int A[n];

    printf("Nhap cac phan tu cho mang: ");
    for(int i = 0; i < n; i ++) {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    int value = 0;
    for (int i = 0; i < n; i++) {
        printf("%d", A[i]);
        if(A[i] > value) {
            value = A[i];
        }
    }

    printf("Gia tri lon nhat trong mang la: %d", value);

    return 0;
}
