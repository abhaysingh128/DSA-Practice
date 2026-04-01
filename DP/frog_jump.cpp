#include<bits/stdc++.h>
using namespace std;
int dp[100005];
int frogJump(int i) {
    if(i==0) return 0;
    if (i==1) return abs(heights[1]-heights[0]);
    if(dp[i]!=-1) return dp[i];
    firstjump = frogJump(i-1) + abs(heights[i]-heights[i-1]);
    secondjump = frogJump(i-2) + abs(heights[i]-heights[i-2]);
    return dp[i] = min(firstjump, secondjump);

}
int main() {
    int n;
    cin>>n;
    vector<int> heights(n);
    for(int i=0;i<n;i++) {
        cin>>heights[i];
    }
    cout<<frogJump(n-1);
    return 0;
}
