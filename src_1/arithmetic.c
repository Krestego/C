#include <stdio.h>

int main() {
    int x, y;
    char z;
    if (scanf("%d %d%c", &x, &y, &z) != 3 || z != '\n') {
        printf("n/a\n");
    } else if (y == 0) {
        printf("%d %d %d n/a\n", x + y, x - y, x * y);
    } else {
        printf("%d %d %d %d\n", x + y, x - y, x * y, x / y);
    }

    return 0;
}