//find the maximum points you can earn by deleting some elements from the array. When you delete an element, you earn points equal to its value, and all elements with a value one less or one more than the deleted element are also deleted (and you earn no points for them).
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int a[n];
    int freq[100001]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
        freq[a[i]]++;
    }
    int dp[100001]={0};
    dp[1] = freq[1];
    for(int i=2;i<=1e5;i++){
        dp[i] = max(dp[i-1],dp[i-2]+i*freq[i]);
    }
    cout<<dp[100000];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
