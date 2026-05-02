// Best Time to Buy and Sell Stock I
#include <bits/stdc++.h>
using namespace std;    
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for(int price : prices) {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
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