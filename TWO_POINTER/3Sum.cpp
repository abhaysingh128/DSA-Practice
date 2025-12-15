#include<bits/stdc++.h>
using namespace std;
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left=i+1;
            int right=n-1;
            int sum=-1*nums[i];
            while(left<right)
            {
                int s=nums[left]+nums[right];
                if(s==sum)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    ans.push_back(temp);
                    left++;
                    right--;
                    while(left<n && nums[left]==nums[left-1]) left++;
                    while(right>=0 && nums[right]==nums[right+1]) right--;
                }
                else if(s<sum) left++;
                else right--;
            }
        }
        return ans;  
    }
int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = threeSum(nums);
    for (const auto& triplet : result) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); ++i) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    return 0;
}