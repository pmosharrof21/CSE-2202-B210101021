#include <stdio.h>

int main() {
    int coins[ ] = {25, 10, 5, 1};
    int n = sizeof(coins) / sizeof(coins[0]);

    int amount;
    printf("Enter the amount: ");
    scanf("%d", &amount);

    printf("Coins used to make %d:\n", amount);

    int totalCoins = 0;

    for (int i = 0; i < n; i++) {
        if (amount >= coins[i]) {
            int count = amount / coins[i];
            amount = amount - count * coins[i];
            totalCoins += count;

            printf("%d coin(s) of %d\n", count, coins[i]);
        }
    }

    printf("Total coins used: %d\n", totalCoins);

    return 0;
}

