#include <stdio.h>
#include <string.h>

// Khai bao cau truc sinh vien
typedef struct {
    char ten[50];
    int diem;
} SinhVien;

int main() {
    int n;

    // Nhap so luong sinh vien
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    SinhVien sv[n];

    // Nhap thong tin sinh vien
    for (int i = 0; i < n; i++) {
        printf("Nhap ten sinh vien thu %d: ", i + 1);
        scanf(" %[^\n]", sv[i].ten);
        printf("Nhap diem cua sinh vien thu %d: ", i + 1);
        scanf("%d", &sv[i].diem);
    }

    // Nhap ten sinh vien can tim
    char tenTimKiem[50];
    printf("Nhap ten sinh vien can tim: ");
    scanf(" %[^\n]", tenTimKiem);

    // Tim sinh vien va in ra diem
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(sv[i].ten, tenTimKiem) == 0) {
            printf("Diem cua %s la: %d\n", tenTimKiem, sv[i].diem);
            found = 1;
            break;
        }
    }

    // Neu khong tim thay sinh vien
    if (!found) {
        printf("Khong tim thay sinh vien.\n");
    }

    return 0;
}

