#include <stdio.h>


int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n + 1], value[n + 1];

    for (int i = 1; i <= n; i++) {
        printf("Enter weight and value of item %d: ", i);
        scanf("%d %d", &weight[i], &value[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int dp[n + 1][W + 1];


    for (int i = 0; i <= n; i++)
        for (int w = 0; w <= W; w++)
            dp[i][w] = 0;


    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weight[i] <= w) {
                dp[i][w] = max(dp[i - 1][w], value[i] + dp[i - 1][w - weight[i]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }


    printf("Maximum value in knapsack = %d\n", dp[n][W]);

    return 0;
}

