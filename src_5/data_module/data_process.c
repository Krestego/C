#include "data_process.h"

#include <math.h>
#include <stdlib.h>

#include "../data_libs/data_stat.h"

double normalization(double *data, int n) {
    double result = 1;
    double max_value = max(data, n);
    double min_value = min(data, n);
    double size = min_value - max_value;

    if (fabs(size) < EPS) {
        for (int i = 0; i < n; i++) {
            data[i] = data[i] / size - min_value / size;
        }
    } else {
        result = 0;
    }

    return result;
}
