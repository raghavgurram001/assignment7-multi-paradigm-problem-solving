#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- helper: compare for qsort ---------- */
int cmp_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

/* ---------- mean ---------- */
double calc_mean(int *arr, int n) {
    long sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return (double)sum / n;
}

/* ---------- median (modifies a copy) ---------- */
double calc_median(int *arr, int n) {
    int *copy = malloc(n * sizeof(int));
    if (!copy) exit(1);
    memcpy(copy, arr, n * sizeof(int));
    qsort(copy, n, sizeof(int), cmp_int);

    double med;
    if (n % 2 == 1)
        med = copy[n/2];
    else
        med = (copy[n/2 - 1] + copy[n/2]) / 2.0;

    free(copy);
    return med;
}

/* ---------- mode (returns the value with highest frequency;
              on ties returns the smallest one) ---------- */
int calc_mode(int *arr, int n) {
    int *copy = malloc(n * sizeof(int));
    if (!copy) exit(1);
    memcpy(copy, arr, n * sizeof(int));
    qsort(copy, n, sizeof(int), cmp_int);

    int mode = copy[0];
    int max_count = 1, cur_count = 1;

    for (int i = 1; i < n; i++) {
        if (copy[i] == copy[i-1]) {
            cur_count++;
            if (cur_count > max_count) {
                max_count = cur_count;
                mode = copy[i];
            }
        } else {
            cur_count = 1;
        }
    }
    free(copy);
    return mode;
}

int main(void) {
    int data[] = {1, 2, 2, 3, 4, 2, 5};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Data: ");
    for (int i = 0; i < n; i++) printf("%d ", data[i]);
    printf("\n");

    printf("Mean   : %.2f\n", calc_mean(data, n));
    printf("Median : %.2f\n", calc_median(data, n));
    printf("Mode   : %d\n",   calc_mode(data, n));

    return 0;
}
