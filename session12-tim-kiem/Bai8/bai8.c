#include <stdio.h>

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    char condition[20];
    printf("Nhap dieu kien tim kiem (chan/le/hoac lon hon so): ");
    scanf("%s", condition);

    printf("Cac so thoa man dieu kien la: ");
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(condition, "chan") == 0 && arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
            found = 1;
        } else if (strcmp(condition, "le") == 0 && arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
            found = 1;
        } else if (strncmp(condition, "lon hon", 7) == 0) {
            int x = atoi(&condition[8]); 
            if (arr[i] > x) {
                printf("%d ", arr[i]);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("Khong co so nao thoa man dieu kien.\n");
    }

    return 0;
}

