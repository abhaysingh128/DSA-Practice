#include<bits/stdc++.h>
using namespace std;
int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int res=INT_MAX;
        int sum=0;
        int low=0;
        int high=0;
        while(high<n)
        {
            sum=sum+nums[high];
            while(sum>=target)
            {
                int len=high-low+1;
                res=min(len,res);
                sum=sum-nums[low];
                low++;
            }
            high++;
        }
        return(res == INT_MAX) ? 0 :res;

        
    }
int main() {
    vector<int> nums = {2,3,1,2,4,3};                       
    int target = 7;
    int result = minSubArrayLen(target, nums);
    cout << "Minimum size of subarray: " << result << endl;
    return 0;       
}