//check if the given parentheses string is valid or not
#include<bits/stdc++.h>
using namespace std;
bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{'||s[i]=='[')
            {
                    st.push(s[i]);
                    continue;
            }
            if(st.empty()) return false;
            if(s[i]==')' && st.top()=='(')
            {
                 st.pop();
                 continue;
            }
            if(s[i]==']' && st.top()=='[')
             {
                 st.pop();
                 continue;
            }
            if(s[i]=='}' && st.top()=='{') 
             {
                 st.pop();
                 continue;
            }
            else return false;
        }
        if (st.empty()) return true;
        return false;
        
    }
int main()
{
    string s;
    cout<<"Enter the parentheses string: ";
    cin>>s;
    if(isValid(s))
        cout<<"The parentheses string is valid."<<endl;
    else
        cout<<"The parentheses string is not valid."<<endl;
    return 0;
}