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
	
	for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
	
	printf("Mang sau khi sap xep: ");
    for(int i = 0; i < n; i++) {
		printf("%d, ", A[i]);
	}
}
