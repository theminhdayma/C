#include <stdio.h>

int binarySearch (int arr[], int n, int x) {
    int left = 0, right = n -1;

    while (left <= right) { 
        int mid = left + (right - left) / 2;

        if(mid == x) {
            return mid;
        }

        if(arr[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main () {
    int n = 5;
    int arr[] = {1, 2, 3, 4, 5};

    int x;
    printf("Nhap phan tu can tim kiem: ");
    scanf("%d", &x);

    int result = binarySearch(arr, n, x);
    if(result != -1) {
        printf("Tim thay phan tu %d tai vi tri %d", x, result);
    } else {
        printf("Khong tim thay phan tu %d", x);
    }

    return 0;
}
