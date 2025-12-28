//arr={1,1,2,3}
//money=5 check if we can make sum 5 by any combination of coins
#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],int n,int money){
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if(money%arr[j]==0) {
                cout<<"true"<<endl;
                return;
            }
            sum+=arr[j];
            if(sum==money) {
                cout<<"true"<<endl;
                return;
            }
        }
    }
    cout<<"false"<<endl;
}
int main()
{
    int arr[]={1,1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int money=5;
    solve(arr,n,money);
    return 0;
}