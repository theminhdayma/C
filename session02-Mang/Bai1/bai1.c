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
	
	int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    
    printf("Gia tri lon nhat: %d", max);
}
