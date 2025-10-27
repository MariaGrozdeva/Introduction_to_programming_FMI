#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    short lastDigit = n % 10;
    if (lastDigit == 0 ||lastDigit == 2 || lastDigit == 4 || lastDigit == 6 || lastDigit == 8) {
        printf("%d", (n - lastDigit) + (lastDigit % 3));
    } else {
        printf("%d", (n - lastDigit) + (lastDigit % 2));
    }
}
