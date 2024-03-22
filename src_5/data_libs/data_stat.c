#include "data_stat.h"

#include <math.h>
#include <stdlib.h>

double max(double *data, int n) {
    double maximum = data[0];
    for (int i = *data; i - *data < n; i++) {
        if (i > maximum) maximum = i;
    }
    return maximum;
}

double min(double *data, int n) {
    double minimum = data[0];
    for (int j = *data; j - *data < n; j++) {
        if (j < minimum) minimum = j;
    }
    return minimum;
}

double mean(double *data, int n) {
    double summ = 0;

    for (int p = 0; p < n; p++) {
        summ += data[p];
    }
    return summ / n;
}

double variance(double *data, int n) {
    double variance_number = 0;
    double sraf = mean(data, n);

    for (int p = 0; p < n; p++) {
        variance_number = variance_number + (data[p] - sraf) * (data[p] - sraf);
    }

    return variance_number / n;
}

double sort(double *data, int n) {
    for (int p = 0; p < n - 1; p++) {
        for (int j = 0; j < n - p - 1; j++) {
            if (data[j] > data[j + 1]) {
                double tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
    return 0;
}
