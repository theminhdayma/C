#include <stdio.h>

int main() {
	int n,k;
	
	printf("Nhap n: ");
	scanf("%d", &n);
	
	int A[n];
	
	for(int i = 0; i < n; i++) {
		printf("A[%d]: ", i + 1);
		scanf("%d", &A[i]);
	}
	
	printf("Nhap phan tu muon xoa: ");
	scanf("%d", &k);
	
	for(int i = 0; i < n; i++) {
		if(A[i] == k) {
			for (int j = i; j < n - 1; j++) {
                A[j] = A[j + 1];
            }
            n--;
		}
	}
	
	printf("Mang sau khi xoa: ");
    for(int i = 0; i < n; i++) {
		printf("%d, ", A[i]);
	}
}
