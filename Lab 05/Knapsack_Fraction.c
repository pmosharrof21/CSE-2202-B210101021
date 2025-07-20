#include <stdio.h>


struct Item {
    int number;
    int weight;
    int value;
    float ratio;
};

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    for (int i = 0; i < n; i++) {
        items[i].number = i + 1;
        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    float totalValue = 0.0;
    int remaining = capacity;

    printf("\nItems taken:\n");

    for (int i = 0; i < n && remaining > 0; i++) {
        if (items[i].weight <= remaining) {

            printf("Item %d: 100%% of weight %d and value %d\n",
                   items[i].number, items[i].weight, items[i].value);
            totalValue += items[i].value;
            remaining -= items[i].weight;
        } else {

            float frac = (float)remaining / items[i].weight;
            printf("Item %d: %.2f%% of weight %d and value %d\n",
                   items[i].number, frac * 100, items[i].weight, items[i].value);
            totalValue += items[i].value * frac;
            remaining = 0;
        }
    }

    printf("\nTotal value in knapsack = %.2f\n", totalValue);

    return 0;
}


