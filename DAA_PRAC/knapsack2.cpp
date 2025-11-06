#include <bits/stdc++.h>
using namespace std;

int solveKnapsack(vector<int>& wt, vector<int>& val, int i, int W, vector<vector<int>>& dp) {
    if (i < 0 || W == 0) return 0;            // Base case
    if (dp[i][W] != -1) return dp[i][W];      // If already computed

    int notTake = solveKnapsack(wt, val, i - 1, W, dp);
    int take = 0;
    if (wt[i] <= W)
        take = val[i] + solveKnapsack(wt, val, i - 1, W - wt[i], dp);

    return dp[i][W] = max(take, notTake);
}


int knapsack(vector<int>& wt, vector<int>& val, int W) {
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return solveKnapsack(wt, val, n - 1, W, dp);
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);
    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) cin >> wt[i];

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) cin >> val[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "\nMaximum value = " << knapsack(wt, val, W) << endl;
    return 0;
}
