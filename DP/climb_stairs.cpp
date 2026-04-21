// Problem Link: https://leetcode.com/problems/climbing-stairs/
#include<bits/stdc++.h>
using namespace std;
int dp[100005];
int climbStairs(int n) {
    if(n==0) return 1;
    if(n==1) return 1;
    for(int i=2;i<=n;i++) {
        if(dp[i]!=-1) return dp[i];
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main() {
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<climbStairs(n);
    return 0;
}