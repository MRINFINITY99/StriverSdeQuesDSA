#include<bits/stdc++.h>
using namespace std;

int f(int ind,int transaction,int n,vector<int>&prices,vector<vector<int>>dp){
    if(ind==n||transaction==4)return 0;
    if(dp[ind][transaction]!=-1)return dp[ind][transaction];
    if(transaction%2==0){
        return dp[ind][transaction]= max(-prices[ind]+f(ind+1,transaction-1,n,prices,dp),0+f(ind+1,transaction,n,prices,dp));
    }else{
        return dp[ind][transaction]= max(prices[ind]+f(ind+1,transaction+1,n,prices,dp),0+f(ind+1,transaction,n,prices,dp));
    }
}

int buySellTransaction(vector<int>&prices,int n){
    vector<vector<int>>dp(n+1,vector<int>(5,-1));
    for(int i=0;i<=4;i++){
        dp[n][i]=0;
    }
    for(int i=0;i<=n;i++){
        dp[i][4]=0;
    }

    for(int ind=n-1;ind>=0;ind--){
        for(int ts=3;ts>=0;ts--){
            if(ts%2==0){
                dp[ind][ts]= max(-prices[ind]+dp[ind+1][ts-1],0+dp[ind+1][ts]);
            }else{
                dp[ind][ts]= max(prices[ind]+dp[ind+1][ts+1],0+dp[ind+1][ts]);
            }
        }
    }

    return dp[0][0];
}