#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int len = strlen(str); 
    int start = 0, end = len - 1;
    
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str[100];
    
    printf("Nhap 1 chuoi bat ky: ");
    fgets(str, sizeof(str), stdin); 
    
    reverseString(str);
    
    printf("Chuoi sau khi dao nguoc: %s\n", str);
    
    return 0;
}

