#include <stdio.h>

int main() {
    int n, x, found = 0;

    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So luong phan tu phai lon hon 0.\n");
        return 1;
    }

    int arr[n];

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Nhap so can tim: ");
    scanf("%d", &x);

    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("So %d da duoc tim thay trong mang.\n", x);
    } else {
        printf("So %d khong co trong mang.\n", x);
    }

    return 0;
}

