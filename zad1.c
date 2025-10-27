#include <stdio.h>
int main() {
    int grade;
    scanf("%d", &grade);
    switch (grade) {
        case 2: printf("Fail"); break;
        case 3: printf("Avarage"); break;
        case 4: printf("Good"); break;
        case 5: printf("Very good"); break;
        case 6: printf("Excellent"); break;
        default: printf("Invalid grade");
    }
}
