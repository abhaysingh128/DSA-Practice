#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>numbers, int target) {
    vector<int>ans;
    int n=numbers.size();
    int i=0;
    int j=n-1;
    while(i<j)
    {
        if(numbers[i]+numbers[j]==target){
            ans.push_back(i+1);
            ans.push_back(j+1);
            return ans;
        }
        else if(numbers[i]+numbers[j]<target)
        {
         i++;
        }
        else j--;
    }
    return ans;    
}    
int main(){
    vector<int>ans;
    int target;
    cout<<"enter the target number: "<<endl;
    cin>>target;
    int n;
    cout<<"enter the size of array: "<<endl;
    cin>>n;
    cout<<"enter the array elements: "<<endl;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    } 
    ans=twoSum(nums,target);
    cout<<"the index pair having sum equal to target is: ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
