#include<bits/stdc++.h>
using namespace std;

void printF(int idx,vector<int>ds,int arr[],int n){
    if(idx==n){
        for(auto it:ds){
            cout<<it<<" ";
        }
        if(ds.size()==0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
    printF(idx+1,ds,arr,n);
    ds.push_back(arr[idx]);
    printF(idx+1,ds,arr,n);
    ds.pop_back();
    
}

int main(){
    int arr[]={3,1,2};
    int n=3;
    vector<int>ds;
    printF(0,ds,arr,n);
}