// This program calculates the maximum subarray sum in a given array
// Naive Approach - Time Complexity: O(n²)

#include <stdio.h>
#define MAXN 50000


int maxLives(int a[], int n) {
    
    int max = a[0];
    int sum = a[0];

    for (int i = 0; i < n - 1; ++i) {
        sum = a[i];
        
        for (int j = i + 1; j < n; ++j) {
            sum += a[j];
            if (sum > max) max = sum;
        }
    }
    return max;
}


int main() {
    
    // Test 1
    // int a[] = {-2, 5, -1, 8, -11, 7, 3};
    // int n = 7;
    // Output = 12 (5 + (-1) + 8)

    // Test 2
    // int a[] = {50, 42, -35, 2, -60, 5, 30, -1, 40, 31};
    // int n = 10;
    // Output = 105 (5 + 30 + (-1) + 40 + 31)

    int n;
    scanf("%d", &n);

    int a[MAXN];
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    int ans = maxLives(a, n);
    printf("%d\n", ans);
    
    return 0;
}
