#include <inttypes.h>
#include <stdio.h>
int main() {
    char sign;
    float a, b;
    scanf("%f %f %c", &a, &b, &sign);
    switch (sign) {
        case '+': printf("%f", a + b); break;
        case '-': printf("%f", a - b); break;
        case '*': printf("%f", a * b); break;
        case '/': if (b != 0) {
            printf("%f", a / b);
            break;
        }
       default: printf("Invalid operation!");
    }
}
