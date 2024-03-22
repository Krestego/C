#include <stdio.h>

int max(int x1, int x2);

int main() {
    int num1, num2;
    char c;

    if (scanf("%d %d%c", &num1, &num2, &c) != 3 || c != '\n') {
        printf("n/a");
    } else {
        int n = max(num1, num2);
        printf("%d\n", n);
    }

    return 0;
}

int max(int x1, int x2) {
    int n = x1;
    if (x2 > x1) n = x2;
    return n;
}