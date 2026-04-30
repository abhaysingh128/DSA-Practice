// Triangle leetcode 120
#include<bits/stdc++.h>
using namespace std;
int minimumTotal(vector<vector<int>>& triangle) {
    int m = triangle.size();
    vector<vector<int>> dp = triangle;
    for (int i = 1; i < m; i++) {
        for (int j = 0; j <= i; j++) {
            // Case 1: Leftmost element (can only come from above)
            if (j == 0) {
                dp[i][j] += dp[i-1][j];
            }
            // Case 2: Rightmost element (can only come from diagonal left)
            else if (j == i) {
                dp[i][j] += dp[i-1][j-1];
            }
            // Case 3: Middle elements (can come from either parent)
            else {
                dp[i][j] += min(dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }
    // The answer is the minimum value in the entire last row
    int minSum = dp[m-1][0];
    for (int j = 1; j < m; j++) {
        minSum = min(minSum, dp[m-1][j]);
    }
    return minSum;
}
int main()
{
    
}