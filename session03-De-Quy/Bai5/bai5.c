#include <stdio.h>
#include <string.h>

int isSymmetrical(char str[], int start, int end) {
    while (start < end) start++;
    while (start < end) end--;
    
    if (start >= end) return 1;

    return isSymmetrical(str, start + 1, end - 1);
}

int main() {
    char str[1000];
    
    printf("Nhap chuoi can kiem tra: ");
    fgets(str, sizeof(str), stdin);

    if (isSymmetrical(str, 0, strlen(str) - 1)) {
        printf("Palindrome valid\n");
    } else {
        printf("Palindrome invalid\n");
    }

    return 0;
}

