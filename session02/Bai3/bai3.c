#include <stdio.h>

int main() {
	int n;
	
	printf("Nhap n: ");
	scanf("%d", &n);
	
	int A[n];
	
	for(int i = 0; i < n; i++) {
		printf("A[%d]: ", i + 1);
		scanf("%d", &A[i]);
	}
	
	for (int i = 0; i < n / 2; i++) {
        int temp = A[i];
        A[i] = A[n - 1 - i];
        A[n - 1 - i] = temp;
    }
    
    printf("Mang sau khi dao nguoc: ");
    for(int i = 0; i < n; i++) {
		printf("%d, ", A[i]);
	}
}
