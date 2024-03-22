#include <math.h>
#include <stdio.h>

double calc(double x);

int main() {
    double x, num;
    scanf("%lf", &x);
    num = calc(x);
    printf("%.1f\n", num);

    return 0;
}

double calc(double x) {
    double y =
        7e-3 * pow(x, 4) + ((22.8 * cbrt(x) - 1e3) * x + 3) / (x * x / 2) - x * pow((10 + x), (2 / x)) - 1.01;
    return y;
}