#include <stdio.h>
#define NMAX 10

int input(int *a);
void output(int *a);
void sorting(int *a);

int main() {
    int data[NMAX];
    if (input(data)) {
        sorting(data);
        output(data);
    } else {
        printf("%s", "n/a");
    }
    return 0;
}

int input(int *a) {
    int error = 1;
    for (int *p = a; (error) && (p - a < NMAX); p++) {
        if ((scanf("%d", p)) != 1) {
            error = 0;
        }
    }
    return error;
}

void sorting(int *a) {
    int temp;
    for (int i = 0; i < NMAX; i++) {
        for (int j = 0; j < NMAX - i; j++) {
            if (*(a + j) > *(a + j + 1)) {
                temp = *(a + j + 1);
                *(a + j + 1) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
}

void output(int *a) {
    for (int *p = a; p - a < NMAX; p++) {
        printf("%d ", *p);
    }
}
