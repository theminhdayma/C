#include <stdio.h>

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    int is_sorted = 0;  // Bien kiem tra hoan doi
    int count = 0;  // Dem so lan lap

    printf("Mang ban dau: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < n - 1; i++) {
        is_sorted = 1;  

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                is_sorted = 0;
            }
            count++;
            printf("Mang sau lan lap %d: ", count);
            for (int k = 0; k < n; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }

        if (is_sorted) {
            break;  
        }
    }

    printf("Sap xep hoan thanh sau %d lan lap.\n", count);
    printf("Mang da sap xep: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, n);

    return 0;
}
