#include<stdio.h>
#include<stdlib.h>

void insertElementArray(int **pArray, int *n, int position, int value);
void deleteElementArray(int **pArray, int *n, int position);

int main(){
    // Mang dong 
    int n;
    int *pArray = NULL;
    int position, value;

    // Nhap so phan tu cua mang
    printf("Moi ban nhap vao so phan tu cua mang: ");
    scanf("%d", &n);

    // Cap nhat bo nho dong
    pArray = (int*) malloc(n * sizeof(int));
    
    // Nhap gia tri cho cac phan tu trong mang
    for(int i = 0; i < n; i++){
        printf("arr[%d] = ", i);
        scanf("%d", pArray + i);
    }

    printf("\nNhap vao vi tri can chen: ");
    scanf("%d", &position);
    printf("Nhap vao gia tri can chen: ");
    scanf("%d", &value);

    insertElementArray(&pArray, &n, position, value);
    printf("\nSau khi chen: ");
    for(int i = 0; i < n; i++){
        printf("\narr[%d] = %d", i, *(pArray + i));
    }

    printf("\nNhap vao vi tri can xoa: ");
    scanf("%d", &position);

    deleteElementArray(&pArray, &n, position);
    printf("\nSau khi xoa: ");
    for(int i = 0; i < n; i++){
        printf("\narr[%d] = %d", i, *(pArray + i));
    }

    free(pArray);

    return 0;
}

// Ham chen phan tu
void insertElementArray(int **pArray, int *n, int position, int value){
    if(position < 0 || position > *n){
        printf("Vi tri can chen khong hop le\n");
        return;
    }

    // Cap phat bo nho
    *pArray = (int*) realloc(*pArray, (*n + 1) * sizeof(int));
    
    // Dich cac phan tu sang phai
    for(int i = *n; i > position; i--){
        (*pArray)[i] = (*pArray)[i - 1];
    }

    // Gan gia tri moi
    (*pArray)[position] = value;
    (*n)++;
}

// Ham xoa phan tu
void deleteElementArray(int **pArray, int *n, int position){
    if(position < 0 || position >= *n){
        printf("Vi tri can xoa khong hop le\n");
        return;
    }

    // Dich cac phan tu sang trai
    for(int i = position; i < *n - 1; i++){
        (*pArray)[i] = (*pArray)[i + 1];
    }

    // Giam kich thuoc mang
    *pArray = (int*) realloc(*pArray, (*n - 1) * sizeof(int));
    (*n)--;
}

