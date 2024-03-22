#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int *n);
int max(int *a, int *n);
int min(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    int result;
    result = input(data, &n);

    if ((result != 1) || (!result)) {
        output(data, &n);
        output_result(max(data, &n), min(data, &n), mean(data, n), variance(data, n));

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

void output(int *a, int *n) {
    for (int *p = a; p - a < *n; p++) {
        printf("%d ", *p);
    }
}

int max(int *a, int *n) {
    int maximum = a[0];
    for (int *p = a; p - a < *n; p++) {
        if (*p > maximum) maximum = *p;
    }
    return maximum;
}

int min(int *a, int *n) {
    int minimum = a[0];
    for (int *p = a; p - a < *n; p++) {
        if (*p < minimum) minimum = *p;
    }
    return minimum;
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
