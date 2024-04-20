#include <stdio.h>


void print(float a[], int n) {
    for (int i = 0; i < n; ++i) printf("%.3f ", a[i]);
    printf("\n");
}


void swap(float *x, float *y) {
    float temp = *x;
    *x = *y;
    *y = temp;
}


void sort(float *a, float *b, int n) {

    for (int i = 0; i < n - 1; ++i) {
        int flag = 0;

        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] / b[j] < a[j + 1] / b[j + 1]) {
                swap(&a[j], &a[j + 1]);
                swap(&b[j], &b[j + 1]);
                flag = 1;
            }
        }
        if (!flag) {
            // print(a, n);
            // print(b, n);
            return;
        }
    }
}


float *knapsack(float *b, float *v, float *w, int n, float t) {
    
    sort(v, w, n);

    int i = 0;
    while (i < n && t > 0) {
        if (w[i] <= t) {
            b[i] = 1;
            t = t - w[i];
            ++i;
        } else {
            b[i] = t / w[i];
            t = 0;
        }
    }
    return b;
}


int main() {

    float value[] = {60, 100, 120};
    float weight[] = {10, 20, 30};
    float backpack[3];
    float total = 50;
    int n = 3;

    float *b = knapsack(backpack, value, weight, n, total);
    print(b, n);

    return 0;
}
