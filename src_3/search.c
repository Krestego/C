#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
void output_result(int *a, int n, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    int result;
    result = input(data, &n);

    if ((result != 1) || (!result)) {
        output_result(data, n, mean(data, n), variance(data, n));

    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *a, int *n) {
    if ((scanf("%d", n) != 1) || (getchar() != '\n')) {
        return 1;
    }

    if (*n <= NMAX && *n > 0) {
        char ch;
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1) {
                return 1;
            } else {
                ch = getchar();
                if ((ch) != ' ') {
                    if ((ch) == '\n') {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

double mean(int *a, int n) {
    double summ = 0;

    for (int p = 0; p < n; p++) {
        summ += a[p];
    }
    return summ / n;
}

double variance(int *a, int n) {
    double variance_number = 0;
    double sraf = mean(a, n);

    for (int p = 0; p < n; p++) {
        variance_number = variance_number + (a[p] - sraf) * (a[p] - sraf);
    }

    return variance_number / n;
}

void output_result(int *a, int n, double mean_v, double variance_v) {
    double deviation_v = 0;
    double sigma_1 = 0;
    double sigma_2 = 0;
    deviation_v = sqrtl(variance_v);  // Стандартное отклонение
    sigma_1 = mean_v - 3 * deviation_v;
    sigma_2 = mean_v + 3 * deviation_v;
    int count = 0;

    for (int p = 0; p < n; p++) {
        if (a[p] % 2 == 0 && a[p] != 0 && (double)a[p] >= sigma_1 && (double)a[p] <= sigma_2 &&
            (double)a[p] >= mean_v) {
            if (count == 0) {
                printf("%i", a[p]);
                count++;
            }
        }
    }
    if (count == 0) printf("0");
}
