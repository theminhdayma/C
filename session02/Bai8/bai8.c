#include <stdio.h>

int main() {
    int n;

    printf("Nhap n: ");
    scanf("%d", &n);

    int arr[n - 1]; 
    int actualSum = 0; 
    
    printf("Nhap %d phan tu cua mang:\n", n - 1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
        actualSum += arr[i];
    }
    
    int expectedSum = n * (n + 1) / 2;

    int missingNumber = expectedSum - actualSum;

    printf("So bi thieu la: %d\n", missingNumber);
}

