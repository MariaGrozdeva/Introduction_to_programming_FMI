#include <stdio.h>

int main()
{
    int grade;
    scanf("%d", &grade);

    if (grade == 2)
    {
        printf("Bad");
    }
    else if (grade == 3)
    {
        printf("Average");
    }
    else if (grade == 4)
    {
        printf("Good");
    }
    else if (grade == 5)
    {
        printf("Very good");
    }
    else if (grade == 6)
    {
        printf("Excellent");
    }
    else
    {
        printf("Invalid grade!");
    }

    return 0;
}
