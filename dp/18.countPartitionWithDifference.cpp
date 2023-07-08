#include<bits/stdc++.h>
using namespace std;
int mod=(1e9+7);

// int f(int ind,int sum,vector<int>&num,vector<vector<int>>&dp){
//     if(ind==0){
//         if(sum==0&&num[0]==0)return 2;
//         if(sum==0||sum==num[0])return 1;
//         return 0;
//     }
//     if(dp[ind][sum]!=-1)return dp[ind][sum];
//     int notTake=f(ind-1,sum,num,dp);
//     int take=0;
//     if(num[ind]<=sum)take=f(ind-1,sum-num[ind],num,dp);
//     return dp[ind][sum]=(notTake+take)%mod;
// }

int findWays(vector<int>&num,int tar){
    int n=num.size();
    vector<int>prev(tar+1,0),cur(tar+1,0);
    if(num[0]==0)prev[0]=2;
    else prev[0]=1;
    //num[0]=0
    if(num[0]!=0 && num[0]<=tar)prev[num[0]]=1;
    for(int i=1;i<n;i++){
        for(int sum=0;sum<=tar;sum++){
            int notTake=prev[sum];
            int take=0;
            if(num[i]<=sum)take=prev[sum];

           cur[sum]=(notTake+take)%mod;
        }
        prev=cur;
    }
    return prev[tar];
}

int countPartitions(int n,int d,vector<int>&arr){
    int totSum=0;
    for(auto &it:arr)totSum+=it;
    if(totSum-d<0||(totSum-d)%2)return false;
    return findWays(arr,(totSum-d)/2);
}

//s1-s2=d
//s1=totalsum-s2
//put s1 value in 1st equa
//s2=(totalsum-d)/2     totsum-d>=0 totsum-d has to be even
