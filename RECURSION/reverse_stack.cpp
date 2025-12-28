//reverse a stack using recursion
#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int>& st, int element);
void reverseStack(stack<int>& st)
{
    if(st.empty())
        return;
    int topElement = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, topElement);
}
void insertAtBottom(stack<int>& st, int element)
{
    if(st.empty())
    {
        st.push(element);
        return;
    }
    int topElement = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(topElement);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverseStack(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}

