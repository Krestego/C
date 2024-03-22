/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int number, int *numbers, int j);
int sum_numbers(int *buffer, int length);
void find_numbers(int *buffer, int length, int *numbers, int number);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int length, buffer[NMAX];
    int array;
    int numbers[NMAX];
    int number;

    array = input(buffer, &length);
    number = sum_numbers(buffer, length);

    if (array != 1) {
        find_numbers(buffer, length, numbers, number);

    } else {
        printf("n/a");
    }

    return 0;
}

// Функция ввода массива
int input(int *buffer, int *length) {
    if ((scanf("%d", length) != 1) || (getchar() != '\n')) {
        return 1;
    }

    if (*length <= NMAX && *length > 0) {
        char ch;
        for (int *p = buffer; p - buffer < *length; p++) {
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

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/

// Функция подсчета суммы четных элементов
int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int p = 0; p < length; p++) {
        if (buffer[p] % 2 == 0) {
            sum += buffer[p];
        }
    }
    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/

// Функция создания нового массива
void find_numbers(int *buffer, int length, int *numbers, int number) {
    int j = 0;
    for (int p = 0; p < length; p++) {
        if (buffer[p] != 0 && number % buffer[p] == 0) {
            numbers[j] = buffer[p];
            j++;
        }
    }
    output(number, numbers, j);
}

// Итоговый вывод
void output(int number, int *numbers, int j) {
    printf("%d\n", number);

    for (int p = 0; p < j; p++) {
        if (p < j - 1) {
            printf("%d ", numbers[p]);
        } else {
            printf("%d", numbers[p]);
        }
    }
}
