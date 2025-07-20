#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    printf("Enter number of coins: ");
    scanf("%d", &n);

    int coin[n + 1];
    int dp[n + 1];
    coin[0] = 0;

    for (int i = 1; i <= n; i++) {
        printf("Enter value of coin %d: ", i);
        scanf("%d", &coin[i]);
    }


    dp[0] = 0;
    dp[1] = coin[1];


    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + coin[i]);
    }


    printf("Maximum value collected = %d\n", dp[n]);

    return 0;
}

