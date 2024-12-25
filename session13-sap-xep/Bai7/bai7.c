#include <stdio.h>

void custom_sort(int arr[], int n) {
    int even[n], odd[n];
    int even_count = 0, odd_count = 0;
    int i, j, k;

    // Tach thanh 2 mang chan le
    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even[even_count++] = arr[i];
        } else {
            odd[odd_count++] = arr[i];
        }
    }

    for (i = 0; i < even_count - 1; i++) {
        for (j = i + 1; j < even_count; j++) {
            if (even[i] > even[j]) {
                int temp = even[i];
                even[i] = even[j];
                even[j] = temp;
            }
        }
    }

    for (i = 0; i < odd_count - 1; i++) {
        for (j = i + 1; j < odd_count; j++) {
            if (odd[i] < odd[j]) {
                int temp = odd[i];
                odd[i] = odd[j];
                odd[j] = temp;
            }
        }
    }

    // Ghep mang
    i = 0, j = 0, k = 0;
    while (i < even_count) {
        arr[k++] = even[i++];
    }
    while (j < odd_count) {
        arr[k++] = odd[j++];
    }

    printf("Mang da sap xep: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 4, 2, 7, 5, 8, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    custom_sort(arr, n);

    return 0;
}
