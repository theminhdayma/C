#include <stdio.h>

#define MAX 100

// In mang
void displayArray(int arr[], int size) {
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Ham them
int addElement(int arr[], int size, int element, int position) {
    if (size >= MAX) {
        printf("Mang da day, khong the them phan tu.\n");
        return size;
    }

    if (position < 0 || position > size) {
        printf("Vi tri khong hop le.\n");
        return size;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    return size + 1;
}

// Ham xoa
int deleteElement(int arr[], int size, int position) {
    if (position < 0 || position >= size) {
        printf("Vi tri khong hop le.\n");
        return size;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    return size - 1;
}

// Ham tim kiem
int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

// Cap nhat
void updateElement(int arr[], int size, int position, int newValue) {
    if (position < 0 || position >= size) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    arr[position] = newValue;
}

int main() {
    int arr[MAX], size, choice, element, position;

    printf("Nhap kich thuoc mang (toi da %d): ", MAX);
    scanf("%d", &size);
    if (size > MAX || size < 0) {
        printf("Kich thuoc khong hop le.\n");
        return 1;
    }

    printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Hien thi mang\n");
        printf("2. Them phan tu\n");
        printf("3. Xoa phan tu\n");
        printf("4. Tim kiem phan tu\n");
        printf("5. Cap nhat phan tu\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            displayArray(arr, size);
            break;
        case 2:
            printf("Nhap gia tri can them: ");
            scanf("%d", &element);
            printf("Nhap vi tri can them (0-%d): ", size);
            scanf("%d", &position);
            size = addElement(arr, size, element, position);
            break;
        case 3:
            printf("Nhap vi tri can xoa (0-%d): ", size - 1);
            scanf("%d", &position);
            size = deleteElement(arr, size, position);
            break;
        case 4:
            printf("Nhap gia tri can tim: ");
            scanf("%d", &element);
            position = searchElement(arr, size, element);
            if (position != -1) {
                printf("Phan tu %d nam o vi tri %d.\n", element, position);
            } else {
                printf("Khong tim thay phan tu %d.\n", element);
            }
            break;
        case 5:
            printf("Nhap vi tri can cap nhat (0-%d): ", size - 1);
            scanf("%d", &position);
            printf("Nhap gia tri moi: ");
            scanf("%d", &element);
            updateElement(arr, size, position, element);
            break;
        case 6:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
        }
    } while (choice != 6);

    return 0;
}
