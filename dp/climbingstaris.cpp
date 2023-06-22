#include <bits/stdc++.h> 
using namespace std;
int f(int n, vector<int>&dp){
    
    if(n==0)return 1;
    if(n==1)return 1;
    if(dp[n]!=-1)return dp[n];
    int left=f(n-1,dp);
    int right=f(n-2,dp);
    return dp[n]=left+right;
}
int countDistinctWays(int nStairs) {
    vector<int>dp(nStairs+1,-1);
    return f(nStairs,dp);
}

int main(){
    int n;
    cin>>n;
    cout<<"Total ways"<<countDistinctWays(n);
    return 0;
}