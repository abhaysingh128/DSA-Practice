#include<bits/stdc++.h>
using namespace std;
int frogJump(int i, vector<int>& heights) {
   if(i==0) return 0;
   if(i==1) return abs(heights[1]-heights[0]);
   int firstjump = frogJump(i-1, heights) + abs(heights[i]-heights[i-1]);
   int secondjump = frogJump(i-2, heights) + abs(heights[i]-heights[i-2]);
   return min(firstjump, secondjump);
}
int main() {
    int n;
    cin>>n;
    vector<int> heights(n);
    for(int i=0;i<n;i++) {
        cin>>heights[i];
    }
    cout<<frogJump(n-1, heights);
    return 0;
}