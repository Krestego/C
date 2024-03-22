#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main() {
    int n;
    double *data = NULL;
    int flg = 0;
    int *p_flg = &flg;

    input_size(&n, p_flg);

    if (flg != 1) {
        data = malloc(n * sizeof(double));
        input(data, n, p_flg);
    }

    if (flg != 1) {
        if (normalization(data, n)) {
            output(data, n);
        } else {
            printf("ERROR");
        }
    }
    if (flg == 1) printf("n/a");

    free(data);

    return 0;
}
