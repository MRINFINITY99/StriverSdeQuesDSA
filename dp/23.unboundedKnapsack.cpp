#include<bits/stdc++.h>
using namespace std;

int f(int ind,int W,vector<int>&val,vector<int>&wt,vector<vector<int>>&dp){
    if(ind==0){
        return ((int)(W/wt[0]))*val[0];
    }
    if(dp[ind][W]!=-1)return dp[ind][W];
    int notTake=0+f(ind-1,W,val,wt,dp);
    int take=0;
    if(wt[ind]<=W){
        take=val[ind]+f(ind-1,W-wt[ind],val,wt,dp);
    }
    return dp[ind][W]=max(take,notTake);
}

int unboundedKnapsack(int n,int w,vector<int>&val,vector<int>&wt){
    vector<vector<int>>dp(n,vector<int>(w+1,0));
    vector<int>prev(w+1,0);
    for(int W=0;W<=w;W++){
        prev[W]=((int)(W/wt[0]))*val[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=w;W++){
            int notTake=0+prev[W];
            int take=0;
            if(wt[ind]<=W){
                take=val[ind]+prev[W-wt[ind]];
            }
            prev[W]=max(take,notTake);
        }
    }

    return prev[w];
}
//we can make the space optimization with two array to one array because to predict the new value we need the old value of same array and the same index value of another array so we can use the one array in place of two and use the value of the same array and then update it to predict the other values.


//tabulation

// int unboundedKnapsack(int n,int w,vector<int>&val,vector<int>&wt){
//     vector<vector<int>>dp(n,vector<int>(w+1,0));
//     for(int W=0;W<=w;W++){
//         dp[0][W]=((int)(W/wt[0]))*val[0];
//     }

//     for(int ind=1;ind<n;ind++){
//         for(int W=0;W<=w;W++){
//             int notTake=0+dp[ind-1][W];
//             int take=0;
//             if(wt[ind]<=W){
//                 take=val[ind]+dp[ind-1][W-wt[ind]];
//             }
//             dp[ind][W]=max(take,notTake);
//         }
//     }

//     return dp[n-1][w];
// }