#include <stdio.h>

#define NMAX 10

int input(int *a, int *n);      // Вводим число
void output(int *a, int *n);    // Выводим результат
void squaring(int *a, int *n);  // Возведение в степень

int main() {
    int n, data[NMAX];
    int result;
    result = input(data, &n);
    if ((result != 1) || (!result)) {
        squaring(data, &n);

        output(data, &n);
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

void squaring(int *a, int *n) {
    for (int *p = a; p - a < *n; p++) {
        *p = *p * *p;
    }
}