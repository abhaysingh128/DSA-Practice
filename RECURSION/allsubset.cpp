#include<bits/stdc++.h>
using namespace std;
void allsubset(string s, int n)
{
    string ans;
    if(n==0)
    {
        cout<<" "<<endl; 
        return;
    }
    allsubset(s,n-1);
    
}
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    allsubset(s,n);
    return 0;

}