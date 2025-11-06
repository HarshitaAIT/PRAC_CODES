#include <iostream>
#include <algorithm>
using namespace std;

// Function to calculate maximum value
double fractionalKnapsack(int n, int W, int value[], int weight[]) {
    // Create an array to store value/weight ratio
    double ratio[100];
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)value[i] / weight[i];
    }

    // Create an index array to help sort items using sort()
    int index[100];
    for (int i = 0; i < n; i++) index[i] = i;

    // Sort items based on ratio (descending order)
    sort(index, index + n, [&](int a, int b) {
        return ratio[a] > ratio[b];
    });

    int curWeight = 0;
    double finalValue = 0.0;

    // Pick items in sorted order
    for (int i = 0; i < n; i++) {
        int idx = index[i]; // actual item index
        if (curWeight + weight[idx] <= W) {
            curWeight += weight[idx];
            finalValue += value[idx];
        } else {
            int remain = W - curWeight;
            finalValue += ratio[idx] * remain;
            break;
        }
    }

    return finalValue;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    int value[100], weight[100];
    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> value[i] >> weight[i];
    }

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    double result = fractionalKnapsack(n, W, value, weight);

    cout << "\nMaximum value in knapsack = " << result << endl;

    return 0;
}


/*
Enter number of items: 3
Enter value and weight of each item:
60 10
100 20
120 30
Enter capacity of knapsack: 50

*/