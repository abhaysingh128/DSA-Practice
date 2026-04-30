//count the number of subsets with given sum
#include<bits/stdc++.h> 
using namespace std;
int countSubsetSum(int arr[], int n, int sum) {
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1; // There's one way to make sum 0: use no elements

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
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
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter sum to check: ";
    cin >> sum;

    int count = countSubsetSum(arr, n, sum);
    cout << "Number of subsets with given sum = " << count << endl;
    return 0;
}