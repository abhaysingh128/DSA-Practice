// Stock Buy Sell with Transaction Fee
#include <bits/stdc++.h>    
using namespace std;
int f(int ind ,int buy, vector<int>& prices, int fee, vector<vector<int>>& dp){
    if(ind>=prices.size()) return 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    int profit=0;
    if(buy){
        profit=max(-prices[ind]+f(ind+1, 0, prices, fee, dp), f(ind+1, 1, prices, fee, dp));
    }
    else{
        profit=max(prices[ind]-fee+f(ind+1, 1, prices, fee, dp), f(ind+1, 0, prices, fee, dp));
    }
    return dp[ind][buy]=profit;
}
int maxProfit(vector<int>& prices, int fee) {
    int n=prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, 1, prices, fee, dp);
}
int main() {
    int n, fee;
    cout << "Enter the number of days: ";
    cin >> n;
    vector<int> prices(n);
    cout << "Enter the stock prices for each day:\n";
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    cout << "Enter the transaction fee: ";
    cin >> fee;
    cout << "Maximum profit: " << maxProfit(prices, fee) << endl;
    return 0;
}