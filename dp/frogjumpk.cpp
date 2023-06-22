#include<bits/stdc++.h>
using namespace std;

int frogjump(int n,vector<int>&heights,int k, vector<int>&dp){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mmSteps=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump=dp[i-j]+abs(heights[i]-heights[i-j]);
                mmSteps=min(jump,mmSteps);
            }
        }
        dp[i]=mmSteps;
    }
    return dp[n-1];
}

int solve(int n,vector<int>&heights,int k){
    vector<int>dp(n,-1);
    return frogjump(n,heights,k,dp);
}




















// int frogjump(int n,vector<int>&heights,int k,vector<int>&dp){
//     if(n==0)return 0;
//     if(dp[n]!=-1)return dp[n];
//     int mmSteps=INT_MAX;
//     int jump=0;
//     for(int j=1;j<=k;j++){
//         if(n-j>=0){
//             jump=frogjump(n-j,heights,k,dp)+abs(heights[n]-heights[n-j]);
//             mmSteps=min(mmSteps,jump);
//         }
//         return dp[n]=mmSteps;
//     }
// }