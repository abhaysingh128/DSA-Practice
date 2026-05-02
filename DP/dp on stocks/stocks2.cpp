// Best Time to Buy and Sell Stock II
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    for(int i = 1; i < prices.size(); i++) {
        if(prices[i] > prices[i-1]) {
            maxProfit += prices[i] - prices[i-1];
        }
    }
    return maxProfit;
}
int main() {
    int n;
    cout << "Enter the number of days: ";
    cin >> n;
    vector<int> prices(n);
    cout << "Enter the stock prices for each day:\n";
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    cout << "Maximum profit: " << maxProfit(prices) << endl;
    return 0;
}