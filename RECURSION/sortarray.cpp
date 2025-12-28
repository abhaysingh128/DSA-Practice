//sort an array using recursion
#include<bits/stdc++.h>
using namespace std;
void insert(vector<int>& arr, int val);
void sortArray(vector<int>& arr)
{
    if(arr.size()==1)
    {
        return;
    }
    int val=arr.back();
    arr.pop_back();
    sortArray(arr);
    insert(arr,val);
}
void insert(vector<int>& arr, int val)
{
    if(arr.size()==0 || arr.back()<=val)
    {
        arr.push_back(val);
        return;
    }
    int temp=arr.back();
    arr.pop_back();
    insert(arr,val);
    arr.push_back(temp);
}
int main()
{
    vector<int> arr={5,2,9,1,5,6};
    sortArray(arr);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
