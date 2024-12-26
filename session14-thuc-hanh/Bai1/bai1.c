#include <stdio.h>

int linearSearch (int arr[], int n, int x) {
    for(int i = 0; i < n ; i ++) {
        if(arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n = 5;
    int arr[] = {1, 2, 3, 4, 5};

    int x;
    printf("Nhap phan tu can tim kiem: ");
    scanf("%d", &x);

    int result = linearSearch(arr, n, x);
    if(result != -1) {
        printf("Tim thay phan tu %d tai vi tri %d", x, result + 1);
    } else {
        printf("Khong tim thay phan tu %d", x);
    }

}