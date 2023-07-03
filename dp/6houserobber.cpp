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

//last and first are adjacent so we can either take first or either take last
long long int houseRobber(vector<int>&valueInHouse){
    vector<int>temp1,temp2;
    long long int n=valueInHouse.size();
    if(n==1)return valueInHouse[0];
    for(int i=0;i<n;i++){
        if(i!=0)temp1.push_back(valueInHouse[i]);
        if(i!=n-1)temp2.push_back(valueInHouse[i]);
    }
    return max(maximumNonAdjacentSum(temp1),maximumNonAdjacentSum(temp2));
}