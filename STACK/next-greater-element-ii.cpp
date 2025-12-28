//find next greater element in circular array
#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElements(vector<int>& nums) { 
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st; 

    for(int i = 0; i < 2 * n; i++) {
        int currentIndex = i % n;
        while(!st.empty() && nums[st.top()] < nums[currentIndex]) {
            ans[st.top()] = nums[currentIndex];
            st.pop();
        }
        if(i < n) {
            st.push(currentIndex);
        }
    }
    return ans;
}
int main() {
    vector<int> nums = {1, 2, 1};
    vector<int> result = nextGreaterElements(nums);
    for(int val : result) {
        cout << val << " ";
    }
    return 0;
}