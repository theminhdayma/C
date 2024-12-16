#include <stdio.h>

int main() {
	int n, m;
	
	printf("Nhap so phan tu cua mang 1: ");
	scanf("%d", &n);
	
	printf("Nhap so phan tu cua mang 2: ");
	scanf("%d", &m);

	int A1[n], A2[m],kq[n + m];
	
	printf("Nhap phan tu cho mang 1: \n");
	for (int i = 0; i < n; i++) {
        printf("A1[%d]: ", i + 1);
        scanf("%d", &A1[i]);
        kq[i] = A1[i];
    }
	
	printf("Nhap phan tu cho mang 2: \n");
	for(int i = 0; i < m; i++) {
		printf("A2[%d]: ", i + 1);
		scanf("%d", &A2[i]);
		kq[n + i] = A2[i];
	}
	
	
	printf("Mang sau khi gop: ");
    for(int i = 0; i < n + m; i++) {
		printf("%d, ", kq[i]);
	}
}
