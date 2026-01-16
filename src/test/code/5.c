#include <stdio.h>

int main() {
    int n = 0;
    double sum = 0;
    scanf("%d", &n);
    int i = 0;
    int a = 1;
    int b = 1;
    int temp = 0;

    for (i = 1; i < n; i++) {
        temp = a;
        a = b;
        b = temp + b;
        if (i % 2 != 0) {
            sum += (1.0000000 * a / b);
        } else
            sum -=  (1.0000000 * a / b);
    }

    printf("%.6f", sum);
    return 0;
}