#include<bits/stdc++.h>
using namespace std;

int f(int ind,int prev_ind,int arr[],int n,vector<vector<int>>&dp){
    if(ind==n)return 0;

    if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];

    int len=0+f(ind+1,prev_ind,arr,n,dp);
    if(prev_ind==-1||arr[ind]>arr[prev_ind]){
        len=max(len,1+f(ind+1,ind,arr,n,dp));
    }
    return dp[ind][prev_ind+1]= len;
}

int longestIncreasingSubsequence(int arr[],int n){
    vector<int>dp(n,1),hash(n);
    int maxi=1;
    int lastIndex=0;
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(arr[prev]<arr[i] && 1+dp[prev]>dp[i]){
                dp[i]=1+dp[prev];
                hash[i]=prev;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            lastIndex=i;
        }
    }
    vector<int>temp;
    temp.push_back(arr[lastIndex]);
    while(hash[lastIndex]!=lastIndex){
        lastIndex=hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(),temp.end());
    for(auto it:temp) cout<<it<<" ";
    cout<<endl;
    return maxi;
}