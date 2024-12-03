#include <stdio.h>

int main() {
	int n, x;
	
	printf("Nhap so phan tu: ");
	scanf("%d", &n);
	
	int A[n];
	
	for(int i = 0; i < n; i++) {
		printf("A[%d]: ", i + 1);
		scanf("%d", &A[i]);
	}
	
	printf("Nhap gia tri muon kiem tra: ");
	scanf("%d", &x);
	
	int kt = 0;
	
	for(int i = 0; i < n; i++) {
		if(A[i] == x) {
			kt ++;
		}
	}
	
	printf("Phan tu %d hien thi %d lan", x, kt);
}
