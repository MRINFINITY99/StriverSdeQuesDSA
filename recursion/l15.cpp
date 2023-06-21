#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void permutationHelper(string s,int ind, vector<string>&ans){
        if(ind==s.size()){
            ans.push_back(s);
            return;
        }
        for(int i=ind;i<s.size();i++){
            swap(s[i],s[ind]);
            permutationHelper(s,ind+1,ans);
            swap(s[i],s[ind]);
        }
    }
    string getPermutation(int n,int k){
        string s;
        vector<string>ans;
        for(int i=1;i<=n;i++){
            s.push_back(i+'0');
        }
        permutationHelper(s,0,ans);
        sort(ans.begin(),ans.end());
        auto it=ans.begin()+(k-1);
        return *it;
    }

};