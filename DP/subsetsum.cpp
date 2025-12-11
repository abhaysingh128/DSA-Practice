#include<bits/stdc++.h> 
using namespace std;
bool isSubsetSum(int set[], int n, int sum) {
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}
int main() {
    int n, sum;
    cout << "Enter number of elements: ";
    cin >> n;
    int set[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }
    cout << "Enter sum to check: ";
    cin >> sum;

    if (isSubsetSum(set, n, sum)) {
        cout << "Found a subset with given sum" << endl;
    } else {
        cout << "No subset with given sum" << endl;
    }
    return 0;
}