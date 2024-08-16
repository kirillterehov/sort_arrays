#include <stdio.h>
#define NMAX 10

int input(int *buffer);
void output(int *buffer);
void merge_sorting(int *buffer, int l, int r);
void quick_sorting(int *buffer, int low, int high);

int input(int *buffer) {
    int error = 1;
    for (int *p = buffer; (error) && (p - buffer < NMAX); p++) {
        if ((scanf("%d", p)) != 1) {
            error = 0;
        }
    }
    return error;
}

void merge(int *buffer, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1] = {0};
    int R[n2] = {0};
    for (int i = 0; i < n1; i++) {
        L[i] = buffer[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = buffer[m + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            buffer[k] = L[i];
            i++;

        } else {
            buffer[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        buffer[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        buffer[k] = R[j];
        j++;
        k++;
    }
}

void merge_sorting(int *buffer, int l, int r) {
    if (l < r) {
        int medium = (l + r - 1) / 2;
        merge_sorting(buffer, l, medium);
        merge_sorting(buffer, medium + 1, r);
        merge(buffer, l, medium, r);
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *buffer, int low, int high) {
    int pivot = buffer[high];
    int i = low - 1;
    for (int j = 0; j < high; j++) {
        if (buffer[j] <= pivot) {
            i++;
            swap(&buffer[i], &buffer[j]);
        }
    }
    swap(&buffer[i + 1], &buffer[high]);
    return (i + 1);
}

void quick_sort(int *buffer, int low, int high) {
    if (low < high) {
        int pi = partition(buffer, low, high);
        quick_sort(buffer, low, pi - 1);
        quick_sort(buffer, pi + 1, high);
    }
}

void output(int *a) {
    for (int *p = a; p - a < NMAX; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}

int main() {
    int data[NMAX];
    if (input(data)) {
        int l = 0;
        int r = NMAX - 1;
        merge_sorting(data, l, r);
        output(data);
        quick_sort(data, l, r);
        output(data);
    } else {
        printf("%s", "n/a");
    }
    return 0;
}
