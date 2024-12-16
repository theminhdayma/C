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
	
	int item = 0;
    int maxCount = 0;
	
	for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (A[i] == A[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            item = A[i];
        }
    }
	
	printf("Phan tu xuat hien nhieu nhat la: %d", item);
}
