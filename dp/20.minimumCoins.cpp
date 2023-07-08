#include<bits/stdc++.h>
using namespace std;

int f(int ind,int T,vector<int>&num,vector<vector<int>>&dp){
    if(ind==0){
        if(T%num[0]==0)return T/num[0];
        else 
            return 1e9;
    }
    if(dp[ind][T]!=-1)return dp[ind][T];

    int notTake=0+f(ind-1,T,num,dp);
    int take=INT_MAX;
    if(num[ind]<=T)take=1+f(ind,T-num[ind],num,dp);
    
    return dp[ind][T]= min(take,notTake);
}

int minimumCoins(vector<int>&num,int target){
    int n=num.size();
    vector<int>prev(target+1,0),cur(target+1,0);
    for(int T=0;T<=target;T++){
        if(T%num[0]==0)prev[T]=T/num[0];
        else
            prev[T]=1e9;
    }
    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=target;T++){
            int notTake=0+prev[T];
            int take=INT_MAX;
            if(num[ind]<=T)take=1+cur[T-num[ind]];
            
            cur[T]= min(take,notTake);
        }
        prev=cur;
    }
    


    int ans= prev[target];
    if(ans>=1e9)return -1;
    return ans;
}










//tabulation
// int minimumCoins(vector<int>&num,int target){
//     int n=num.size();
//     vector<vector<int>>dp(n,vector<int>(target+1,0));
//     for(int T=0;T<=target;T++){
//         if(T%num[0]==0)dp[0][T]=T/num[0];
//         else
//             dp[0][T]=1e9;
//     }
//     for(int ind=1;ind<n;ind++){
//         for(int T=0;T<=target;T++){
//             int notTake=0+dp[ind-1][T];
//             int take=INT_MAX;
//             if(num[ind]<=T)take=1+dp[ind][T-num[ind]];
            
//             dp[ind][T]= min(take,notTake);
//         }
//     }
    


//     int ans= dp[n-1][target];
//     if(ans>=1e9)return -1;
//     return ans;
// }