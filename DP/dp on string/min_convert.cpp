// Minimum opertaions to convert one string to another
#include <bits/stdc++.h>
using namespace std;    
int lcs(string s1, string s2){
    int m=s1.size();
    int n=s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
    if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
    else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    }
    }
    return dp[m][n];
}
int minDistance(string word1, string word2) {
    int size1=word1.size();
    int size2=word2.size();
    return size1+size2-2*lcs(word1,word2);
    
}
int main() {
    string word1, word2;
    cout << "Enter first string: ";
    cin >> word1;
    cout << "Enter second string: ";
    cin >> word2;
    cout << "Minimum operations to convert string 1 to string 2: " << minDistance(word1, word2) << endl;
    return 0;
}