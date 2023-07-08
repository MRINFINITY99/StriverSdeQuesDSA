#include<bits/stdc++.h>
using namespace std;



int knapsack(vector<int>wt,vector<int>val,int n,int maxWeight){
    vector<int>prev(maxWeight+1,0),cur(maxWeight+1,0);
    for(int W=wt[0];W<=maxWeight;W++)prev[W]=val[0];

    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=maxWeight;W++){
            int notTake=0+prev[W];
            int take=INT_MIN;
            if(wt[ind]<=W){
                take=val[ind]+prev[W-wt[ind]];
            }
            cur[W]=max(take,notTake);
        }
        prev=cur;
    }
    return prev[maxWeight];
}

//here we use two array but there in one more way in which we can use only one array only prev because we can reassign or update that same array again for the more upcoming values. Because we need only a value to get the new value and we can use the old value for new values and then again start reassing the value in array. here we can only move from right to left for the new values.

//tabulation
// int knapsack(vector<int>wt,vector<int>val,int n,int maxWeight){
//     vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
//     for(int W=wt[0];W<=maxWeight;W++)dp[0][W]=val[0];

//     for(int ind=1;ind<n;ind++){
//         for(int W=0;W<=maxWeight;W++){
//             int notTake=0+dp[ind-1][W];
//             int take=INT_MIN;
//             if(wt[ind]<=W){
//                 take=val[ind]+dp[ind-1][W-wt[ind]];
//             }
//             dp[ind][W]=max(take,notTake);
//         }
//     }
//     return dp[n-1][maxWeight];
// }

//memoization
// int f(int ind,int W,vector<int>&wt,vector<int>&val,vector<vector<int>>&dp){
//     if(ind==0){
//         if(wt[0]<=W)return val[0];
//         return 0;
//     }

//     if(dp[ind][W]!=-1)return dp[ind][W];

//     int notTake=0+f(ind-1,W,wt,val,dp);
//     int take=INT_MIN;
//     if(wt[ind]<=W){
//         take=val[ind]+f(ind-1,W-wt[ind],wt,val,dp);
//     }
//     return dp[ind][W]=max(take,notTake);
// }