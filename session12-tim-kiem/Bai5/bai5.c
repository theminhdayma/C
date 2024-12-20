#include <stdio.h>

// Ham tim kiem nhi phan
int binarySearch(int arr[], int left, int right, int x) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Kiem tra neu phan tu o giua la phan tu can tim
        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] > x) {
            return binarySearch(arr, left, mid - 1, x);
        }

        return binarySearch(arr, mid + 1, right, x);
    }

    return -1;
}

int main() {
    int n, x;

    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];

    // Nhap cac phan tu cua mang (da sap xep tang dan)
    printf("Nhap cac phan tu cua mang theo thu tu tang dan:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    int result = binarySearch(arr, 0, n - 1, x);

    if (result != -1) {
        printf("Phan tu %d nam o vi tri: %d\n", x, result);
    } else {
        printf("Khong tim thay phan tu trong mang.\n");
    }

    return 0;
}

