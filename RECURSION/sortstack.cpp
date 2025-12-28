//sort a stack using recursion
#include <bits/stdc++.h>
using namespace std;
void insertInSortedStack(stack<int>& st, int val);
void sortStack(stack<int>& st)
{
    if(st.size()==1)
    {
        return;
    }
    int val=st.top();
    st.pop();
    sortStack(st);
    insertInSortedStack(st,val);
}
void insertInSortedStack(stack<int>& st, int val)
{
    if(st.size()==0 || st.top()<=val)
    {
        st.push(val);
        return;
    }
    int temp=st.top();
    st.pop();
    insertInSortedStack(st,val);
    st.push(temp);
}
int main()
{
    stack<int> st;
    st.push(34);
    st.push(3);
    st.push(31);
    st.push(98);
    st.push(92);
    st.push(23);
    sortStack(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}