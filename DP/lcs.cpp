// Longest Common Subsequence
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp (1001, vector<int>(1001, -1));
int LCS(string s1, string s2){
    int m=s1.size();
    int n=s2.size();
    if(m==0 || n==0) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    if(s1[m-1]==s2[n-1]) return dp[m][n]=1+LCS(s1.substr(0,m-1), s2.substr(0,n-1));
    else return dp[m][n]=max(LCS(s1.substr(0,m-1), s2), LCS(s1, s2.substr(0,n-1)));
}
void printLCS(vector<vector<int>>& dp, string s1, string s2){
    string lcs="";
    int i=s1.size(), j=s2.size();
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            lcs+=s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }
    reverse(lcs.begin(), lcs.end());
    cout << "Longest Common Subsequence: " << lcs << endl;
}
int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;
    cout << "Length of longest common subsequence: " << LCS(s1, s2) << endl;
    printLCS(dp, s1, s2);
    return 0;
}   