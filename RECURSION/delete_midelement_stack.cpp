#include<bits/stdc++.h>
using namespace std;
void deletemid(stack<int>& st, int size)
{
     int mid;
     if(size%2==0) mid = size/2+1;
     else mid = size/2;
     if(mid==1)
     {
         st.pop();
         return;
     }
     int val=st.top();
     st.pop();
     deletemid(st,size-1);
     st.push(val);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    int size=st.size();
    deletemid(st,size);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}