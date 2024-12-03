#include <stdio.h>

int main() {
    int n, k;
    
    printf("Nhap n: ");
    scanf("%d", &n);

    int A[n];
    
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    printf("Nhap gia tri cua k: ");
    scanf("%d", &k);
    
    int check = 0;  
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] + A[j] == k) {
            	printf("Cac cap so co tong bang %d la: %d, %d", k, A[i], A[j]);
                check = 1;
            }
        }
    }
    
    if (!check) {
        printf("Khong tim thay cap nao co tong bang %d.\n", k);
    }
}

