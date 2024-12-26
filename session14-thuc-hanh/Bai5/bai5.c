#include <stdio.h>

// Ham sap xep chen theo thu tu tang dan
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Di chuyen cac phan tu lon hon key ve sau
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

        // Hien thi qua trinh chen
        printf("Sau khi chen phan tu %d: ", key);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
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

    // Nhap so luong phan tu cua mang
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Hien thi mang ban dau
    printf("Mang ban dau: ");
    printArray(arr, n);

    // Sap xep mang theo thu tu tang dan
    printf("\nQua trinh sap xep chen:\n");
    insertionSort(arr, n);

    // Hien thi mang sau khi sap xep
    printf("\nMang sau khi sap xep: ");
    printArray(arr, n);

    return 0;
}
