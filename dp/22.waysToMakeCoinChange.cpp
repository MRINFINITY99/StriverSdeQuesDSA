#include<bits/stdc++.h>
using namespace std;

long f(int ind,int T,int *a,vector<vector<long>>&dp){
    if(ind==0){
        return (T%a[0]==0);
    }
    if(dp[ind][T]!=-1)return dp[ind][T];
    long notTake=f(ind-1,T,a,dp);
    long take=0;
    if(a[ind]<=T)take=f(ind,T-a[ind],a,dp);
    return dp[ind][T]=take+notTake;
}

long countWaysToMakeChange(int *denomination,int n,int value){
    vector<long>prev(value+1,0),cur(value+1,0);

    for(int T=0;T<=value;T++){
        prev[T]=(T%denomination[0]==0);
    }
    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=value;T++){
            long notTake=prev[T];
            long take=0;
            if(denomination[ind]<=T)take=cur[T-denomination[ind]];
            cur[T]=take+notTake;
        }
        prev=cur;
    }

    return prev[value];
}


//tabulation
// long countWaysToMakeChange(int *denomination,int n,int value){
//     vector<vector<long>>dp(n,vector<int>(value+1,0));

//     for(int T=0;T<=value;T++){
//         dp[0][T]=(T%denomination[0]==0);
//     }
//     for(int ind=1;ind<n;ind++){
//         for(int T=0;T<=value;T++){
//             long notTake=dp[ind-1][T];
//             long take=0;
//             if(denomination[ind]<=T)take=dp[ind][T-denomination[ind]];
//             dp[ind][T]=take+notTake;
//         }
//     }

//     return dp[n-1][value];
// }