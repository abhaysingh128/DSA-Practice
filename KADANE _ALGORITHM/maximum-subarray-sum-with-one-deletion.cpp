//FIND THE MAXIMUM SUBARRAY SUM WITH ONE DELETION ALLOWED
#include<bits/stdc++.h>
using namespace std;
  int maximumSum(vector<int>& arr) {
       int n=arr.size();
       int power=0;
       int nopower=arr[0];
       int res=arr[0];
       for(int i=1;i<n;i++)
       {
        int v1=arr[i];
        int v2=nopower+arr[i];
        int v3=power+arr[i];
        int v4=nopower;
        int res1=max(max(v1,v2),max(v3,v4));
        res=max(res,res1);
        nopower=max(v1,v2);
        power=max(v3,v4);
       }
       return res; 
    }
int main()
{
    vector<int> arr={1,-2,0,3};
    cout<<maximumSum(arr);
    return 0;
}