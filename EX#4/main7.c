#include <stdio.h>

int factorial(int n) {
    if (n == 1) return 1;            // 中止條件（base case）
    return n * factorial(n - 1);     // 遞迴關係（recursive case）
}

int main() {
    int n = 5;
    int m = factorial(n);
    printf("factorial %d = %d\n", n, m);
    return 0;
}
