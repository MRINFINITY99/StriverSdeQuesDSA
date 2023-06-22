#include<bits/stdc++.h>
using namespace std;
int maxProductSubArrya(vector<int>&nums){
    int prod1=nums[0],prod2=nums[0],result=nums[0];
    for(int i=1;i<nums.size();i++){
        int temp=max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2=min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1=temp;
        result=max(result,prod1);
    }
    return result;
}
int main(){
    vector<int>nums={1,2,3,4,5,0};
    cout<<maxProductSubArrya(nums);
    return 0;
}