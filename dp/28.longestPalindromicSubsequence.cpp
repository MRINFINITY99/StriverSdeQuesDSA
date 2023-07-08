#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int j=0;j<=m;j++)dp[0][j]=0;
    for(int i=0;i<=n;i++)dp[i][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int longestPalindromeSubsequence(string s){
    string t=s;
    reverse(t.begin(),t.end());
    return longestSubsequence(s,t);
}