#include <stdio.h>

// Ham hoan doi hai gia tri
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Ham sap xep theo thuat toan Selection Sort (Tang dan)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

// Ham tim kiem nhi phan
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; 
        }
        if (arr[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return -1; 
}

// Ham in mang
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, target;

    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Nhap phan tu can tim kiem
    printf("Nhap gia tri can tim: ");
    scanf("%d", &target);

    // Sap xep mang
    selectionSort(arr, n);

    // In mang sau khi sap xep
    printf("Mang sau khi sap xep: ");
    printArray(arr, n);

    // Tim kiem nhi phan
    int position = binarySearch(arr, n, target);
    if (position != -1) {
        printf("Phan tu %d duoc tim thay tai vi tri %d\n", target, position + 1);
    } else {
        printf("Khong tim thay phan tu %d\n", target);
    }

    return 0;
}
