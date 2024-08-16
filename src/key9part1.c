#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length, int sum);
int sum_numbers(const int *buffer, int length);
int find_numbers(const int *buffer, int length, int number, int *numbers);

int input(int *buffer, int *length) {
    int error = scanf("%d", length);
    if ((*length > NMAX || *length <= 0)) {
        error = 0;
    }
    for (int *p = buffer; (error) && (p - buffer < *length); p++) {
        if ((scanf("%d", p)) != 1) {
            error = 0;
        }
    }
    return error;
}

int sum_numbers(const int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

int find_numbers(const int *buffer, int length, int number, int *numbers) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && (number % buffer[i] == 0)) {
            numbers[count] = buffer[i];
            count++;
        }
    }
    return count;
}

void output(int *a, int n, int sum) {
    printf("%d\n", sum);
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
}

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        int sum = sum_numbers(data, n);
        if (sum != 0) {
            int numbers[NMAX];
            output(numbers, find_numbers(data, n, sum, numbers), sum);
        } else {
            printf("%s", "n/a");
        }
    } else {
        printf("%s", "n/a");
    }
    return 0;
}