// Stock Buy Sell to Maximize Profit having at most k transactions
#include <bits/stdc++.h>
using namespace std;
int f(int ind ,int buy ,int cap, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(cap==0) return 0;
        if(ind==prices.size()) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int profit=0;
        if(buy){
            profit=max(-prices[ind]+f(ind+1, 0, cap, prices, dp), f(ind+1, 1, cap, prices, dp));
        }
        else{
            profit=max(prices[ind]+f(ind+1, 1, cap-1, prices, dp), f(ind+1, 0, cap, prices, dp));
        }
        return dp[ind][buy][cap]=profit;
}
int maxProfit(int k, vector<int>& prices) {
    int n=prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
    return f(0, 1, k, prices, dp);
    
}
int main() {
    int n, k;
    cout << "Enter the number of days: ";
    cin >> n;
    vector<int> prices(n);
    cout << "Enter the stock prices for each day:\n";
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    cout << "Enter the maximum number of transactions allowed: ";
    cin >> k;
    cout << "Maximum profit: " << maxProfit(k, prices) << endl;
    return 0;
}