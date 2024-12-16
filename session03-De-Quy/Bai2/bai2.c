#include <stdio.h>

int main() {
	int n, m;
	
	printf("Nhap 2 so nguyen n va m. n phai nho hon m. \n");
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Nhap m: ");
	scanf("%d", &m);
	
	int sum = 0;
	
	for(int i = n; i < m; i++) {
		sum += i;
	}
	
	printf("Tong cua %d và %d là: %d", n, m, sum);
}
