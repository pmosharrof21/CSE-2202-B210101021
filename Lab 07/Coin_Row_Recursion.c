#include <stdio.h>

int coinRow(int coins[], int i) {
    if (i == 0)
        return 0;
    if (i == 1)
        return coins[1];

    int include = coinRow(coins, i - 2) + coins[i];
    int exclude = coinRow(coins, i - 1);
    return (include > exclude) ? include : exclude;
}

int main() {
    int n;
    printf("Enter number of coins: ");
    scanf("%d", &n);

    int coins[n + 1];
    coins[0] = 0;

    for (int i = 1; i <= n; i++) {
        printf("Enter value of coin %d: ", i);
        scanf("%d", &coins[i]);
    }

    int maxValue = coinRow(coins, n);

    printf("Maximum value collected = %d\n", maxValue);

    return 0;
}

