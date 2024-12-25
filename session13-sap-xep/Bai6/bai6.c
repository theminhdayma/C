#include <stdio.h>

void selection_sort(int arr[], int n) {
    int i, j, min_index, temp;
    int count = 0; 

    printf("Mang ban dau: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < n - 1; i++) {
        min_index = i;

        // Tim phan tu nho nhat
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;	
            }
        }

        if (min_index != i) {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            count++;

            printf("Hoan doi: ");
            for (int k = 0; k < n; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
    }

    printf("Sap xep hoan thanh voi %d lan hoan doi.\n", count);
    printf("Mang da sap xep: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, n);

    return 0;
}
