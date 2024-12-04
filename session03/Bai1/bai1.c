#include <stdio.h>

int factorial (a) {
	if(a == 0) return 1;
	return a * factorial(a - 1);
}

int main() {
	int n;
	
	printf("Nhap 1 so nguyen bat ky: ");
	scanf("%d", &n);
	
	if (n < 0) {
        printf("Gia tri n khong hop le.\n");
        return 1;
    }
	
	int kq = factorial(n);
	
	printf("Giai thua cua %d là: %d", n, kq);
	
}
