#include "data_io.h"

#include <stdio.h>
#include <stdlib.h>

void input_size(int *n, int *p_flg) {
    char c;
    if (*p_flg != 1)
        if ((scanf("%d%c", n, &c) != 2) || (*n <= 0) || (c != ' ' && c != '\n')) *p_flg = 1;
}

void input(double *data, int n, int *p_flg) {
    char c;
    for (int i = 0; i < n; i++) {
        if (*p_flg != 1)
            if ((scanf("%lf%c", &data[i], &c) != 2) || (c != ' ' && c != '\n')) *p_flg = 1;
    }
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            printf("%.2lf ", data[i]);
        } else {
            printf("%.2lf", data[i]);
        }
    }
}
