#include <stdio.h>

int main() {
    int n;

    // Nhap so luong phan tu cua mang
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];

    // Nhap cac phan tu cua mang
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // Kiem tra cac phan tu doi xung
    int hasSymmetry = 0; 
    printf("Cac cap phan tu doi xung:\n");
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] == arr[n - i - 1]) {
            printf("Cap doi xung: (%d, %d)\n", arr[i], arr[n - i - 1]);
            hasSymmetry = 1;
        }
    }

    // Neu khong co phan tu doi xung
    if (!hasSymmetry) {
        printf("Khong co phan tu doi xung trong mang.\n");
    }

    return 0;
}

