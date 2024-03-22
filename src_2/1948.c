#include <stdio.h>

int division(int x1, int x2);  // Проверка на деление: х1 делится на х2
int simple(int i);  // Проверка, что делитель является простым числом
int check(int number);

int main() {
    int number;  // Делимое
    int result;
    char c;

    if (scanf("%d%c", &number, &c) != 1 || c != '\n') {
        printf("n/a");
    } else {
        if (number < 0) number = -number;
        result = check(number);
        if (result == 1) result = number;
        printf("%d", result);
    }
}

int check(int number) {
    int result;
    for (int i = 1; i < number; i++) {
        if (division(number, i) == 0 && simple(i) == 1) {
            result = i;
        }
    }
    return result;
}

int division(int x1, int x2) {
    while ((x1 - x2) >= 0) {
        x1 = x1 - x2;
    }
    return x1;
}

int simple(int i) {
    for (int j = 2; j < i; j++) {
        if (division(i, j) == 0) {
            return 0;
        }
    }
    return 1;
}
