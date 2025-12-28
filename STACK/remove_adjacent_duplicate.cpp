//rmove all adjacent duplicates in a string
#include<bits/stdc++.h>
using namespace std;
string removeDuplicates(string s) {
        stack<char>st;
        string ans;
        for(int i=0;i<s.length();i++)
        {
         if(st.empty())
         { 
            st.push(s[i]);
            continue;
         }
         if(s[i]==st.top())
         {
            st.pop();
            continue;
         }
         st.push(s[i]);   
        }
        while(!st.empty())
        {
            char c=st.top();
            st.pop();
            ans.push_back(c);
        }
        reverse(ans.begin(),ans.end());
        return ans;
}
int main()
{
    string s;
    cin>>s;
    cout<<removeDuplicates(s)<<endl;
    return 0;
}
