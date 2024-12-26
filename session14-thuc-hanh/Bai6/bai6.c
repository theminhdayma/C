#include <stdio.h>

// Ham sap xep Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Ham tim kiem tuyen tinh
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; 
        }
    }
    return -1; 
}

// Ham tim kiem nhi phan
int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid; 
        }

        if (arr[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
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
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int choice;
    do {
        printf("\n===================Menu======================:\n");
        printf("1. In mang ban dau\n");
        printf("2. Sap xep mang bang Insertion Sort\n");
        printf("3. Tim kiem tuyen tinh\n");
        printf("4. Tim kiem nhi phan\n");
        printf("5. Thoat\n");
        printf("Chon mot chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Mang ban dau:");
                printArray(arr, n);
                break;

            case 2:
                insertionSort(arr, n);
                printf("Mang sau khi sap xep:\n");
                printArray(arr, n);
                break;

            case 3: {
                int x;
                printf("Nhap gia tri can tim (tuyen tinh): ");
                scanf("%d", &x);
                int result = linearSearch(arr, n, x);
                if (result != -1) {
                    printf("Tim thay %d tai vi tri %d.\n", x, result);
                } else {
                    printf("Khong tim thay %d.\n", x);
                }
                break;
            }

            case 4: {
                int x;
                printf("Nhap gia tri can tim (nhi phan): ");
                scanf("%d", &x);
                int result = binarySearch(arr, n, x);
                if (result != -1) {
                    printf("Tim thay %d tai vi tri %d.\n", x, result);
                } else {
                    printf("Khong tim thay %d.\n", x);
                }
                break;
            }

            case 5:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 5);

    return 0;
}