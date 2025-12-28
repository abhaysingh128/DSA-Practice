//print numbers from 1 to n using recursion
#include<bits/stdc++.h>
using namespace std;
void print1ton(int n)
{
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    print1ton(n-1);
    cout<<n<<endl;
}
int main()
{
    int n;
    cin>>n;
    print1ton(n);
    return 0;
}
