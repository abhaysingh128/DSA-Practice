// Problem Link: https://leetcode.com/problems/house-robber-ii/
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return 0;
    if(n==1) return nums[0];
    int dp[n];
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);
    for(int i=2;i<n;i++) {
        dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[n-1];
}
int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==0)return 0;
    if(n==1) return nums[0];
    vector<int>temp1,temp2;
    for(int i=0;i<n;i++)
    {
        if(i!=0) temp1.push_back(nums[i]);
        if(i!=n-1) temp2.push_back(nums[i]);
    }
    int ans1=solve(temp1);
    int ans2=solve(temp2);
    return max(ans1,ans2);
}
int main() {
    int n;          
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }
    cout<<rob(nums);
    return 0;
}