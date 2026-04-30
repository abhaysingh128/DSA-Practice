//count no. of ways to reach nth stair if we can take 1 or 2 steps at a time
#include<bits/stdc++.h>
using namespace std;
int dp[100005];
int countWays(int n) {
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = countWays(n-1) + countWays(n-2);
}
int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    cout<<"Enter the number of stairs: ";
    cin>>n;
    cout<<"Number of ways to reach the "<<n<<"th stair: "<<countWays(n)<<endl;
    return 0;
}