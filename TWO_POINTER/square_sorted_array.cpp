#include<bits/stdc++.h>
using namespace std;
 vector<int> sortedSquares(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);

        }
        if(neg.size()==0)
        {
            for(int i=0;i<pos.size();i++)
            {
                pos[i]=pos[i]*pos[i];
            }
            return pos;
        }
        if(pos.size()==0)
        {
            for(int i=0;i<neg.size();i++)
            {
                neg[i]=neg[i]*neg[i];
            }
            reverse(neg.begin(),neg.end());
            return neg;
        }
        int n=neg.size();
        int m=pos.size();
        vector<int>res(n+m);
        for(int i=0;i<m;i++) pos[i]=pos[i]*pos[i];
        for(int i=0;i<n;i++) neg[i]=neg[i]*neg[i];
        reverse(neg.begin(),neg.end());
        int i=0,j=0;
        int id=0;
        while(i<n && j<m)
        {
            if(neg[i]<=pos[j])
            {
                res[id]=neg[i];
                id++;
                i++;
            }
            else 
            {
                res[id]=pos[j];
                id++;
                j++;
            }
        }
        while(i<n)
        {
            res[id]=neg[i];
            id++;
            i++;
        }
        while(j<m)
        {
            res[id]=pos[j];
            id++;
            j++;
        }
        return res;
    }
int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    vector<int>res=sortedSquares(nums);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}