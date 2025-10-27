#include <stdio.h>
int main () {
    char shape;
    printf("Enter shape: ");
    scanf("%c", &shape);

    switch (shape) {
        case 's':
            printf("Enter dimensions: ");
            float a;
            scanf("%f", &a);
            printf("%f", a*a);
                break;
        case 'r':
            printf("Enter dimensions: ");
            float sideA, sideB;
            scanf("%f %f", &sideA, &sideB);
            printf("%f", sideA*sideB);
                break;
        case 'c':
            printf("Enter dimensions: ");
            float radius;
            scanf("%f", &radius);
            printf("%f", 3.14*radius*radius);
                break;
        case 't':
            printf("Enter dimensions: ");
            float sideC, height;
            scanf("%f %f", &sideC, &height);
            printf("%f", (sideC * height) / 2);
                break;
                default: printf("Invalid shape");
    }
}
