#include<bits/stdc++.h>
using namespace std;

//tabulation
int lcs(string X,string Y,int m,int n){
    //2d array
    int L[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0){
                L[i][j]=0;
            }
            else if(X[i-1]==Y[j-1]){
                L[i][j]=L[i-1][j-1]+1;
            }
            else{
                L[i][j]=max(L[i-1][j],L[i][j-1]);
            }
        }
    }
    return L[m][n];
}

int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){
    if(i<0||j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j])return dp[i][j]=1+f(i-1,j-1,s,t,dp);
    return dp[i][j]=max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
}


int main(){
    string s1="AGGTAB";
    string s2="GXTXAYB";
    int m=s1.size();
    int n=s2.size();
    cout<<"length of lcs is "<<lcs(s1,s2,m,n);
    return 0;
}