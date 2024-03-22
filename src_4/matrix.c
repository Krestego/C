#include <stdio.h>
#include <stdlib.h>

#define NMAX 100

int input_number(int *n);
void input_size(int n, int *h, int *v);
int input_matrix(int *a, int v);
void otput(int *a, int v);

void stat(int h, int v);
void dynamic_1(int h, int v);
void dynamic_2(int h, int v);
void dynamic_3(int h, int v);

int main() {
    int n, h, v;

    input_number(&n);

    if (n < 1 || n > 4) {
        printf("n/a");
        return 1;
    } else {
        input_size(n, &h, &v);
    }

    return 0;
}

int input_number(int *n) {
    char c;
    if ((scanf("%d%c", n, &c) != 2) || c != '\n') {
        return 1;
    }
    return 0;
}

void input_size(int n, int *h, int *v) {
    char c;
    if ((scanf("%d%d%c", h, v, &c) != 3) || c != '\n') {
        printf("n/a");

    } else {
        if (n == 1) {
            stat(*h, *v);
        }

        else if (n == 2) {
            dynamic_1(*h, *v);
        }

        else if (n == 3) {
            dynamic_2(*h, *v);
        } else if (n == 4) {
            dynamic_3(*h, *v);
        }
    }
}

int input_matrix(int *a, int v) {
    for (int i = 0; i < v; i++) {
        scanf("%d", &a[i]);
    }
    return 0;
}

void otput(int *a, int v) {
    for (int i = 0; i < v; i++) {
        if (i < v - 1) {
            printf("%d ", a[i]);
        } else {
            printf("%d", a[i]);
        }
    }
}

void stat(int h, int v) {
    int mas[NMAX][NMAX];
    if ((h < 1 || h > NMAX) || (v < 1 || v > NMAX)) {
        printf("n/a");
    } else {
        for (int p = 0; p < h; p++) {
            input_matrix(mas[p], v);
        }

        for (int k = 0; k < h; k++) {
            otput(mas[k], v);
        }
    }
}

void dynamic_1(int h, int v) {
    int mas[h][v];

    for (int p = 0; p < h; p++) {
        input_matrix(mas[p], v);
    }

    int **pointer_array = malloc(h * v * sizeof(int) + h * sizeof(int *));
    int *ptr = (int *)(pointer_array + h);
    int count = 0;

    for (int i = 0; i < h; i++) pointer_array[i] = ptr + (v + 1) * i;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < v; j++) pointer_array[i][j] = ++count;

    free(pointer_array);

    for (int k = 0; k < h; k++) {
        otput(mas[k], v);
        if (k < h - 1) {
            printf("\n");
        }
    }
}

void dynamic_2(int h, int v) {
    int mas[h][v];

    for (int p = 0; p < h; p++) {
        input_matrix(mas[p], v);
    }

    int count = 0;
    int **pointer_array = malloc(h * sizeof(int *));

    for (int i = 0; i < h; i++) pointer_array[i] = malloc(v * sizeof(int));

    for (int i = 0; i < h; i++)
        for (int j = 0; j < v; j++) pointer_array[i][j] = ++count;

    for (int i = 0; i < h; i++) free(pointer_array[i]);

    free(pointer_array);

    for (int k = 0; k < h; k++) {
        otput(mas[k], v);
        if (k < h - 1) {
            printf("\n");
        }
    }
}

void dynamic_3(int h, int v) {
    int mas[h][v];

    for (int p = 0; p < h; p++) {
        input_matrix(mas[p], v);
    }
    int **pointer_array = malloc(h * sizeof(int *));
    int *values_array = malloc(h * v * sizeof(int));
    int count = 0;

    for (int i = 0; i < h; i++) pointer_array[i] = values_array + (v + 1) * i;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < v; j++) pointer_array[i][j] = ++count;

    free(values_array);
    free(pointer_array);

    for (int k = 0; k < h; k++) {
        otput(mas[k], v);
        if (k < h - 1) {
            printf("\n");
        }
    }
}
