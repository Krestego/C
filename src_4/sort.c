#include <stdio.h>

int input(int *a, int n);
void output(int *a, int n);
void bubl(int *a, int n);

int main() {
    int n = 10;
    int data[n];
    int result;

    result = input(data, n);
    if (result != 1) {
        bubl(data, n);
        output(data, n);

    } else {
        printf("n/a");
    }

    return 0;
}
int input(int *a, int n) {
    char ch;
    for (int p = 0; p < n; p++) {
        if (scanf("%d", &a[p]) != 1) {
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
    return 1;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
}

void bubl(int *a, int n) {
    for (int p = 0; p < n - 1; p++) {
        for (int j = 0; j < n - p - 1; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
