#include<bits/stdc++.h>
using namespace std;


int maximumNonAdjacentSum(vector<int>&nums){
    int n=nums.size();
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1)take+=prev2;

        int notTake=0+prev;

        int curi=max(take,notTake);
        prev2=prev;
        prev=curi;
    }
    return prev;
    
}



















//dp
// int f(int ind,vector<int>&nums,vector<int>&dp){
//     dp[0]=nums[0];
//     int neg=0;
//     for(int i=1;i<ind;i++){
//         int take=nums[ind];
//         if(i>1)take+=dp[i-2];
//         int nottake=0+dp[i-1];
//         dp[i]=max(take,nottake);
//     }
//     return dp[ind];
// }


//memoization
//int f(int ind,vector<int>&nums,vector<int>dp){
//     if(ind==0)return nums[ind];
//     if(ind<0)return 0;

//     if(dp[ind]!=-1)return dp[ind];

//     int pick=nums[ind]+f(ind-2,nums,dp);
//     int notPick=0+f(ind-1,nums,dp);

//     return dp[ind]=max(pick,notPick);
// }