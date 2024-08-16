#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length, int *sdvig);
void output(int *buffer, int length);
int sdvig_massiva(int *buffer, int length, int sdvig);

int input(int *buffer, int *length, int *sdvig) {
    int error = scanf("%d", length);
    if ((*length > NMAX || *length <= 0)) {
        error = 0;
    }
    for (int *p = buffer; (error) && (p - buffer < *length); p++) {
        if ((scanf("%d", p)) != 1) {
            error = 0;
        }
    }
    if (scanf("%d", sdvig) != 1) {
        error = 0;
    }
    return error;
}

int sdvig_massiva(int *buffer, int length, int sdvig) {
    if (sdvig > 0) {
        for (int i = 0; i < sdvig; i++) {
            int tmp = buffer[0];
            for (int j = 0; j < length; j++) {
                buffer[j - 1] = buffer[j];
            }
            buffer[length - 1] = tmp;
        }
    } else {
        sdvig = -1 * sdvig;
        for (int i = 0; i < sdvig; i++) {
            int tmp = buffer[length - 1];
            for (int j = length - 1; j > 0; j--) {
                buffer[j] = buffer[j - 1];
            }
            buffer[0] = tmp;
        }
    }

    return sdvig;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
}

int main() {
    int n, data[NMAX], sdvig;
    if (input(data, &n, &sdvig)) {
        sdvig_massiva(data, n, sdvig);
        output(data, n);
    } else {
        printf("%s", "n/a");
    }
    return 0;
}
