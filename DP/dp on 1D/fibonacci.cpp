#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000+1;
int dp[MAX];
int fib(int n) {
    if(n==1) return 0;
    if(n==2) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fib(n-1) + fib(n-2);

}
int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    cout << "Enter the Fibonacci term to calculate: ";
    cin >> n;
    cout << "The " << n << "th Fibonacci number is: " << fib(n) << endl;
    return 0;
}