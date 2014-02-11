#include <stdio.h>

// Calculates and prints the first n Fibonacci numbers.
void fib(int n) {
    int n1 = 1;
    int n2 = 1;
    int temp = 0;
    printf("%d\n", n1);
    for(int i=1; i<n; i++) {
        printf("%d\n", n2);
        temp = n1 + n2;
        n1 = n2;
        n2 = temp;
    };
}

int main() {
    fib(20);
    return 0;
}
