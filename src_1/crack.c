#include <stdio.h>

int main() {
    double num1, num2;

    if (scanf("%lf %lf", &num1, &num2) != 2) {
        printf("n/a");
        return 0;
    }

    double dist = num1 * num1 + num2 * num2;

    if (dist < 25) {
        printf("GOTCHA");

    } else {
        printf("MISS");
    }
    return 0;
}