#include <inttypes.h>
#include <stdio.h>
int main() {
    int x, y, radius;
    scanf("%d %d %d", &radius, &x, &y);
    int squaredX = x*x;
    int squaredY = y*y;
    int radiusSquared = radius * radius;
    if (squaredX + squaredY < radiusSquared) {
        printf("In the circle!");
    } else if (squaredX + squaredY > radiusSquared) {
        printf("Out of the circle!");
    } else {
        printf("On the circle!");
    }
}
