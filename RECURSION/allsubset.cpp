//print all subsets of a string using recursion
#include<bits/stdc++.h>
using namespace std;
void allsubset(string ip,string op)
{
    if(ip.length()==0)
    {
        cout<<op<<" ";
        return;
    }
    string op1=op;
    string op2=op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    allsubset(ip,op1);
    allsubset(ip,op2);
    
}
int main()
{
    string ip;
    cout<<"Enter the string: ";
    cin>>ip;
    string op="";
    cout<<"The subsets are: ";
    allsubset(ip,op);
    cout<<endl;
    return 0;
}