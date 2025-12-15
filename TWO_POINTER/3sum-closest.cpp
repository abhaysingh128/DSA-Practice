#include<bits/stdc++.h>
using namespace std;
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxdiff=INT_MAX;
        int res,diff;
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left=i+1;
            int right=n-1;
            while(left<right)
            {
                int sum=nums[left]+nums[right]+nums[i];
                diff=abs(sum-target);
                if(diff<maxdiff)
                {
                    maxdiff=diff;
                    res=sum;
                }
                if(sum==target)
                {
                   left++;
                   right--;
                }
                else if(sum<target) left++;
                else right--;
            }
        }
        return res;  
    }
int main()
{   
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    int result = threeSumClosest(nums, target);
    cout << "The sum that is closest to the target " << target << " is: " << result << endl;
    return 0;
}