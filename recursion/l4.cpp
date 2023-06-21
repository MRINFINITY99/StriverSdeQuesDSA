#include<bits/stdc++.h>
using namespace std;

//reverse an array
//swap
void fun(int l,int r,vector<int>&arr){
    if(l>=r)return;
    swap(arr[l],arr[r]);
    fun(l+1,r-1,arr);
}

//one variable
void fun1(int i, vector<int>&arr){
    if(i>=arr.size()/2)return;
    swap(arr[i],arr[arr.size()-i-1]);
    fun1(i+1,arr);
}

//palindrome
bool fun2(int i,string &s){
    if(i>=s.size()/2)return true;
    if(s[i]!=s[s.size()-i-1])return false;
    return fun2(i+1,s);
}