#include <stdio.h>

// Prints all factors of n.
void printFactors(n) {
    for(int i=1; i<=n; i++) {
        if(n%i == 0) printf("%d\n", i);
    }
}

int main() {
    int user_num = 0;
    printf("Enter an integer: ");
    scanf("%d", &user_num);
    printFactors(user_num);
    return 0;
}
