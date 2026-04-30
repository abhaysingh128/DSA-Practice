//0-1 Knapsack Problem using Dynamic Programming
#include<bits/stdc++.h>
using namespace std;
int knapsack(int W, int wt[], int val[], int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}
int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    int val[n], wt[n];
    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    cout << "Enter maximum weight capacity of knapsack: ";
    cin >> W;

    int maxValue = knapsack(W, wt, val, n);
    cout << "Maximum value in Knapsack = " << maxValue << endl;
    return 0;
}
