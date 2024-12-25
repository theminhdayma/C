#include <stdio.h>

// Ham hoan doi hai gia tri
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Ham sap xep theo thuat toan Selection Sort
void selectionSort(int arr[], int n, int mode) {
    for (int i = 0; i < n - 1; i++) {
        int selectedIndex = i;

        // Tim phan tu trong phan mang chua sap xep
        for (int j = i + 1; j < n; j++) {
            if ((mode && arr[j] < arr[selectedIndex]) || (!mode && arr[j] > arr[selectedIndex])) {
                selectedIndex = j;
            }
        }

        if (selectedIndex != i) {
            swap(&arr[i], &arr[selectedIndex]);
        }
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
    int a = 1;
    int b = 0;

    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n], tempArr[n];
    printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        tempArr[i] = arr[i]; 
    }

    printf("Mang ban dau: ");
    printArray(arr, n);

    // Sap xep tang dan
    selectionSort(arr, n, a); // mode = 1
    printf("Mang sau khi sap xep tang dan: ");
    printArray(arr, n);

    // Sap xep giam dan
    selectionSort(tempArr, n, b); // mode = 0
    printf("Mang sau khi sap xep giam dan: ");
    printArray(tempArr, n);

    return 0;
}
