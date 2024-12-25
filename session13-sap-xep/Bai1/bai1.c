#include <stdio.h>

// Ham hoan doi gia tri hai bien
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Ham thuc hien thuat toan Sap xep noi bot
void bubbleSort(int arr[], int n, int ascending) {
    int i, j;
    int swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0; 

        for (j = 0; j < n - i - 1; j++) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        if (!swapped)
            break;
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
    bubbleSort(arr, n, a);
    printf("Mang sau khi sap xep tang dan: ");
    printArray(arr, n);

    // Sap xep giam dan
    bubbleSort(tempArr, n, b);
    printf("Mang sau khi sap xep giam dan: ");
    printArray(tempArr, n);

    return 0;
}

