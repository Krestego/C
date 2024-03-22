#include <math.h>
#include <stdio.h>

int fibonacci(int x) {
    if (x < 0) {
        return -1;
    } else if (x <= 1) {
        return x;
    }
    int a = 0, b = 1, next;
    for (int i = 2; i <= x; i++) {
        next = a + b;
        a = b;
        b = next;
    }
    return b;
}

int main() {
    int num;
    char c;

    if (scanf("%d%c", &num, &c) != 2 || c != '\n') {
        printf("n/a");
    }

    else

    {
        int result = fibonacci(num);
        if (result == -1) {
            printf("n/a\n");
        } else {
            printf("%d", result);
        }
    }

    return 0;
}